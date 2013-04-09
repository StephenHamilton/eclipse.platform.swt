/*******************************************************************************
 * Copyright (c) 2013 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.eclipse.swt.browser;


import java.io.*;
import java.util.*;
import org.eclipse.swt.*;
import org.eclipse.swt.graphics.*;
import org.eclipse.swt.internal.*;
import org.eclipse.swt.internal.cef3.*;
import org.eclipse.swt.internal.win32.*;
import org.eclipse.swt.widgets.*;

public class CEF extends WebBrowser {
	boolean creatingBrowser, ignoreDispose, suppressNavEvents;
	CEFClient client;
	CEFBrowser cefBrowser;
	String htmlText;
	Object[] pendingText, pendingUrl;
	long /*int*/ windowHandle;
	Hashtable ipcAdapters = new Hashtable(9);
	Hashtable downloads = new Hashtable(9);

	static boolean LibraryLoaded;
	static CEFApp App;
	static String InitError;
	
	public static cef_string_t CEFSTRING_EMPTY;
	
	static final String ABOUT_BLANK = "about:blank"; //$NON-NLS-1$
	static final String CEF3_PATH = "org.eclipse.swt.browser.CEF3Path"; //$NON-NLS-1$
	static final String STRING_NULL = "null"; //$NON-NLS-1$
	static final String STRING_RESULT = "result:"; //$NON-NLS-1$
	static final String URI_FILEROOT = "file:///"; //$NON-NLS-1$
	static final int CEF3_SUPPORTED_REVISON = 1094;
	static final int MAX_PROGRESS = 100;
	static final int RESPONSE_TIMEOUT = 3000;

	/* IPC message names */
	static final String MSG_dispose_ipc = "dispose_ipc"; //$NON-NLS-1$
	static final String MSG_evaluate = "evaluate"; //$NON-NLS-1$
	static final String MSG_init_ipc = "init_ipc"; //$NON-NLS-1$
	static final String MSG_on_before_navigation = "on_before_navigation"; //$NON-NLS-1$

	static {
		/*
		 * To use CEF3 the full path of its extracted package must be provided in the
		 * org.eclipse.swt.browser.CEF3Path java property.  If a value representing a
		 * valid directory is set for this property then add it to the library lookup
		 * path and then attempt to load the swt-cef3 library.
		 */
		
		// TODO is InitError really needed?  Some failure branches below don't set it
		String CEF3Path = System.getProperty(CEF3_PATH);
		if (CEF3Path != null && CEF3Path.length() > 0) {
			File file = new File(CEF3Path);
			if (!(file.exists() && file.isDirectory())) {
				InitError = "org.eclipse.swt.browser.CEF3Path value is not valid: " + CEF3Path;  // $NON-NLS-1$
			} else {
				TCHAR buffer = new TCHAR(0, CEF3Path, true);
				boolean success = OS.SetDllDirectory(buffer);
				if (success) {
					try {
						Library.loadLibrary("swt-cef3"); // $NON-NLS-1$

						/* initialize STRING_EMPTY */
						CEFSTRING_EMPTY = CreateCEFString("");

						/* initialize CEF3 */
						cef_main_args_t args = new cef_main_args_t();
						args.instance = OS.GetModuleHandle(null);
						App = new CEFApp();
						App.add_ref();
						int exitCode = CEF3.cef_execute_process(args, App.getAddress());
						if (exitCode < 0) {

							/* extract the subprocess executable */
							String NAME_SUBPROC_EXE = "swt-cef3subproc-win32.exe"; //$NON-NLS-1$
							File directory = new File(System.getProperty("user.home"), Library.SWT_LIB_DIR()); //$NON-NLS-1$
							file = new File(directory, NAME_SUBPROC_EXE);
							if (!file.exists()) {
								java.io.InputStream is = Library.class.getResourceAsStream("/" + NAME_SUBPROC_EXE); //$NON-NLS-1$
								if (is != null) {
									if (!directory.exists()) {
										directory.mkdirs();
									}
									int read;
									byte[] bytes = new byte[4096];
									try {
										FileOutputStream os = new FileOutputStream(file);
										while ((read = is.read(bytes)) != -1) {
											os.write(bytes, 0, read);
										}
										os.close();
										is.close();
									} catch (Exception e) {
									}
								}
							}

							if (!file.exists()) {
								InitError = "Failed to extract SWT's cef3 subprocess executable: " + NAME_SUBPROC_EXE; //$NON-NLS-1$
							} else {
								cef_settings_t settings = new cef_settings_t();
								settings.size = cef_settings_t.sizeof;
								settings.multi_threaded_message_loop = 1;
								settings.release_dcheck_enabled = 1;
								settings.browser_subprocess_path = CreateCEFString(file.getAbsolutePath());
								App.add_ref();
								int rc = CEF3.cef_initialize(args, settings, App.getAddress());
								if (rc != 0) {
									LibraryLoaded = true;
								} else {
									InitError = "cef3 initialization failed"; //$NON-NLS-1$
								}
							}
						}
					} catch (Throwable e) {
						InitError = "Failed to load the swt-cef3 library, org.eclipse.swt.browser.CEF3Path: " + CEF3Path; //$NON-NLS-1$
					}
				}
			}
		}

		if (LibraryLoaded) {
			Display.getCurrent().addListener(SWT.Dispose,  new Listener() {
				public void handleEvent(Event event) {
					App.release();
					App = null;
				}
			});

			NativeClearSessions = new Runnable() {
				public void run() {
					if (!LibraryLoaded) return;
					// TODO do it
				}
			};

			NativeGetCookie = new Runnable() {
				public void run() {
					if (!LibraryLoaded) return;
					// TODO use CookieUrl and CookieName, set value of CookieValue
				}
			};

			NativeSetCookie = new Runnable() {
				public void run() {
					if (!LibraryLoaded) return;
					// TODO set CookieValue on CookieUrl, set CookieResult to true if successful
				}
			};

			if (NativePendingCookies != null) {
				SetPendingCookies(NativePendingCookies);
				NativePendingCookies = null;
			}
		} else {
			if (App != null) {
				App.release();
				App = null;
			}
		}
	}


static cef_string_t CreateCEFString(String string) {
	char[] chars = new char[string.length()];
	string.getChars(0, string.length(), chars, 0);
	cef_string_t result = new cef_string_t();
	CEF3.cef_string_set(chars, chars.length, result, 1);
	return result;
}

static String ExtractCEFString(long /*int*/ pString) {
	if (pString == 0) {
		return "";
	}

	cef_string_t cefString = new cef_string_t();
	CEF3.memmove(cefString, pString, CEF3.cef_string_t_sizeof());
	int length = (int)/*64*/cefString.length;
	char[] chars = new char[length]; 
	OS.memmove(chars, cefString.str, length * 2);
	return new String(chars); 
}

static boolean IsInstalled() {
	if (!LibraryLoaded) return false;
	if (CEF3.cef_build_revision() != CEF3_SUPPORTED_REVISON) return false;
	return true;
}

public void create(Composite parent, int style) {
	cef_window_info_t windowInfo = new cef_window_info_t();
	int extStyle = OS.WS_EX_NOINHERITLAYOUT;
	if ((style & SWT.BORDER) != 0) extStyle |= OS.WS_EX_CLIENTEDGE;
	if ((style & SWT.RIGHT_TO_LEFT) != 0) extStyle |= OS.WS_EX_LAYOUTRTL;
	windowInfo.ex_style = extStyle; 
	windowInfo.style = OS.WS_CHILD | OS.WS_VISIBLE | OS.WS_CLIPSIBLINGS;
	windowInfo.x = windowInfo.width = OS.CW_USEDEFAULT;
	windowInfo.ex_style = 0; 
	windowInfo.window_name = CEFSTRING_EMPTY;
	windowInfo.parent_window = browser.handle;

	cef_browser_settings_t browserSettings = new cef_browser_settings_t();
	browserSettings.size = cef_browser_settings_t.sizeof;

	cef_string_t strUrl = CreateCEFString(ABOUT_BLANK);
	client = new CEFClient(this);
	client.add_ref();
	int rc = CEF3.cef_browser_host_create_browser(windowInfo, client.getAddress(), strUrl, browserSettings);
	if (rc == 0) {
		return;
	}

	creatingBrowser = true;

	Listener listener = new Listener() {
		public void handleEvent(Event event) {
			switch (event.type) {
				case SWT.Dispose: {
					/* make this handler run after other dispose listeners */
					if (ignoreDispose) {
						ignoreDispose = false;
						break;
					}
					ignoreDispose = true;
					browser.notifyListeners(event.type, event);
					event.type = SWT.NONE;
					onDispose(event);
					break;
				}
				case SWT.Resize: {
					onResize();
					break;
				}
			}
		}
	};
	browser.addListener(SWT.Dispose, listener);
	// browser.addListener(SWT.Resize, listener); // TODO when SWT.EMBEDDED style is removed
	browser.addListener(SWT.KeyDown, listener); /* needed for tabbing into the Browser */
}

public void createDownloadWindow(String filename, String url, int id) {
	CEFDownload download = new CEFDownload(filename, url, browser);
	downloads.put(new Integer(id), download);
}

public boolean back() {
	if (cefBrowser == null || cefBrowser.can_go_back() == 0) return false;
	cefBrowser.go_back();
	return true;
}

public boolean close() {
	if (cefBrowser == null) return false;

	// TODO
	return false;
}

void browserCreated(long /*int*/ handle) {
	cefBrowser = new CEFBrowser(handle);
	cefBrowser.add_ref(); // TODO release() when disposed
	creatingBrowser = false;

	CEFBrowserHost host = new CEFBrowserHost(cefBrowser.get_host());
	windowHandle = host.get_window_handle();

	/* if browser content has been provided by the client then set it now */
	if (pendingText != null) {
		setText((String)pendingText[0], ((Boolean)pendingText[1]).booleanValue());
	} else if (pendingUrl != null) {
		setUrl((String)pendingUrl[0], (String)pendingUrl[1], (String[])pendingUrl[2]);
	}
	pendingText = pendingUrl = null;
}

public Object evaluate (String script) throws SWTException {
	if (cefBrowser == null) return null;
	String string = eval(script);
	if (string == null) return null;
	if (!string.startsWith(STRING_RESULT)) {
		throw new SWTException(SWT.ERROR_FAILED_EVALUATE, string);
	}
	string = string.substring(STRING_RESULT.length());
	// TODO parse the JSON and return its Object
	return string;
}

public boolean execute(String script) {
	if (cefBrowser == null) return false;
	return eval(script) != null;
}

String eval(String script) {
	script = "'" + STRING_RESULT + "' + JSON.stringify(" + script + ")"; //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$

	cef_string_t strName = CreateCEFString(MSG_evaluate);
	long /*int*/ pMessage = CEF3.cef_process_message_create(strName);
	CEFProcessMessage message = new CEFProcessMessage(pMessage);
	long /*int*/ pArgs = message.get_argument_list();
	CEFListValue args = new CEFListValue(pArgs);
	cef_string_t strScript = CreateCEFString(script);
	args.set_string(0, strScript);

	// TODO always takes the first adapter, which can obviously be wrong
	CEFIPCSharedFile adapter = (CEFIPCSharedFile)ipcAdapters.elements().nextElement();
	if (adapter == null) return null; /* should not happen */
	final String[] response = new String[1];
	adapter.sendMessage(message, RESPONSE_TIMEOUT, response);
	message.release();
	if (response[0].equals(STRING_NULL)) return null;
	return response[0];
}

public boolean forward() {
	if (cefBrowser == null || cefBrowser.can_go_forward() == 0) return false;
	cefBrowser.go_forward();
	return true;
}

public String getBrowserType() {
	// TODO should this return "CEF3"?
	return "webkit"; //$NON-NLS-1$
}

public String getText() {
	if (cefBrowser == null) return "";

	// TODO
	return null;
}

public String getUrl() {
	if (cefBrowser == null) {
		/*
		 * If the browser is being created then return ABOUT_BLANK in order to be
		 * consistent with the other Browser implementations which auto-navigate
		 * to ABOUT_BLANK when opened.
		 */
		if (!creatingBrowser) return "";
		return ABOUT_BLANK;
	}

	long /*int*/ pFrame = cefBrowser.get_main_frame();
	if (pFrame == 0) {
		return null;
	}	
	CEFFrame frame = new CEFFrame(pFrame);
	long /*int*/ pUrl = frame.get_url();
	String javaStringUrl = ExtractCEFString(pUrl);
	CEF3.cef_string_userfree_free(pUrl);

	/*
	 * If the URI indicates that the page is being rendered from memory
	 * (via setText()) then set it to about:blank to be consistent with IE.
	 */
	if (javaStringUrl.equals (URI_FILEROOT)) {
		javaStringUrl = ABOUT_BLANK;
	} else {
		int length = URI_FILEROOT.length ();
		if (javaStringUrl.startsWith (URI_FILEROOT) && javaStringUrl.charAt (length) == '#') {
			javaStringUrl = ABOUT_BLANK + javaStringUrl.substring (length);
		}
	}
	return javaStringUrl;
}

public boolean isBackEnabled() {
	return cefBrowser != null && cefBrowser.can_go_back() != 0;
}

public boolean isForwardEnabled() {
	return cefBrowser != null && cefBrowser.can_go_forward() != 0;
}

int onContextMenu(int xCoord, int yCoord) {
	Event event = new Event();
	event.x = xCoord;
	event.y = yCoord;
	browser.notifyListeners (SWT.MenuDetect, event);
	if (event.doit) {
		Menu menu = browser.getMenu();
		if (menu != null && !menu.isDisposed()) {
			if (event.x != xCoord || event.y != yCoord) {
				menu.setLocation(event.x, event.y);
			}
			menu.setVisible(true);
		}
		else {
			return 0;
		}
	}
	return 1;
}

void onDispose(Event e) {
	htmlText = null;

	Enumeration elements = ipcAdapters.elements();
	while (elements.hasMoreElements()) {
		((CEFIPCSharedFile)elements.nextElement()).dispose();
	}
	ipcAdapters = null;
	
	downloads = null;

	if (client != null) {
		client.release();
		client = null;
	}

	if (cefBrowser != null) {
		cefBrowser.release();
		cefBrowser = null;
	}
}

void onDownloadProgress(long receivedBytes, long totalBytes, boolean completed, boolean inProgress, boolean cancelled, CEFDownloadItemCallback callback, int id) {
	CEFDownload download = (CEFDownload)downloads.get(new Integer(id));
	if (download == null) return;
	boolean done = download.updateStatus(receivedBytes, totalBytes, completed, inProgress, cancelled, callback);
	if (done) {
		downloads.remove(new Integer(id));
	}
}

void onIPCDispose(String id) {
	CEFIPCSharedFile adapter = (CEFIPCSharedFile)ipcAdapters.get(id);
	if (adapter != null) {
		adapter.dispose();
		ipcAdapters.remove(id);
	}
}

void onIPCInit(String id, String arg) {
	ipcAdapters.put(id, new CEFIPCSharedFile(cefBrowser, arg));
}

void onLoadComplete() {
	if (suppressNavEvents) {
		/* completed initial navigate to about:blank for setText() invocation */
		return;
	}

	ProgressEvent progress = new ProgressEvent(browser);
	progress.display = browser.getDisplay();
	progress.widget = browser;
	progress.current = MAX_PROGRESS;
	progress.total = MAX_PROGRESS;
	for (int i = 0; i < progressListeners.length; i++) {
		progressListeners[i].completed (progress);
	}
}

void onLocationChanged(String location, boolean top) {
	if (!suppressNavEvents) {
		Display display = browser.getDisplay();
		if (top) {
			ProgressEvent progress = new ProgressEvent(browser);
			progress.display = display;
			progress.widget = browser;
			progress.current = 1;
			progress.total = MAX_PROGRESS;
			for (int i = 0; i < progressListeners.length; i++) {
				progressListeners[i].changed(progress);
			}
			if (browser.isDisposed()) return;
	
			StatusTextEvent statusText = new StatusTextEvent(browser);
			statusText.display = display;
			statusText.widget = browser;
			statusText.text = location;
			for (int i = 0; i < statusTextListeners.length; i++) {
				statusTextListeners[i].changed(statusText);
			}
			if (browser.isDisposed()) return;
		}
	
		LocationEvent event = new LocationEvent(browser);
		event.display = display;
		event.widget = browser;
		event.location = location;
		event.top = top;
		for (int i = 0; i < locationListeners.length; i++) {
			locationListeners[i].changed(event);
		}
		if (browser.isDisposed()) return;
	}

	if (top && htmlText != null) {
		long /*int*/ pFrame = cefBrowser.get_main_frame();
		if (pFrame != 0) {
			CEFFrame frame = new CEFFrame(pFrame);
			cef_string_t strHtml = CreateCEFString(htmlText);
			cef_string_t strUrl = CreateCEFString(ABOUT_BLANK);
			frame.load_string(strHtml, strUrl);
			htmlText = null;
		}
	}
}

boolean onLocationChanging(String location) {
//	if (location.length () == 0) {
//		return false;
//	}
//	if (url.startsWith (WebKit.PROTOCOL_FILE) && webKit.getUrl ().startsWith (WebKit.ABOUT_BLANK) && webKit.untrustedText) {
//		/* indicates an attempt to access the local file system from untrusted content */
//		pdListener.ignore ();
//		return false;
//	}
	/*
	 * If the URI indicates that the page is being rendered from memory
	 * (via setText()) then set it to about:blank to be consistent with IE.
	 */
//	if (url.equals (WebKit.URI_FILEROOT)) {
//		url = WebKit.ABOUT_BLANK;
//	} else {
//		int length = WebKit.URI_FILEROOT.length ();
//		if (url.startsWith (WebKit.URI_FILEROOT) && url.charAt (length) == '#') {
//			url = WebKit.ABOUT_BLANK + url.substring (length);
//		}
//	}

	if (suppressNavEvents) {
		suppressNavEvents = false;
		if (location.equals(ABOUT_BLANK)) {
			/* 
			 * This is the second navigate to about:blank in response to a setText()
			 * invocation, so allow it silently.
			 */
			return true;
		}
		htmlText = null;
	}

	LocationEvent newEvent = new LocationEvent(browser);
	newEvent.display = browser.getDisplay();
	newEvent.widget = browser;
	newEvent.location = location;
	newEvent.doit = true;
	if (locationListeners != null) {
		for (int i = 0; i < locationListeners.length; i++) {
			locationListeners[i].changing(newEvent);
		}
	}
	if (browser.isDisposed()) return false;

	if (htmlText != null) {
		if (newEvent.doit && location.equals(ABOUT_BLANK)) {
			/* 
			 * This is the first of two navigates to about:blank in response to a setText()
			 * invocation, the subsequent Changed, Completed and Changing events should not be sent.
			 */
			suppressNavEvents = true;
		} else {
			htmlText = null;
		}
	}
	return newEvent.doit;
}

void onMessageReceived(long /*int*/ pMessage) {
	CEFProcessMessage message = new CEFProcessMessage(pMessage);
	long /*int*/ pName = message.get_name();
	String name = CEF.ExtractCEFString(pName);
	CEF3.cef_string_userfree_free(pName);

	long /*int*/ pArgs = message.get_argument_list();
	CEFListValue args = new CEFListValue(pArgs);
	long /*int*/ pArg = args.get_string(0);
	final String ipcId = CEF.ExtractCEFString(pArg);
	CEF3.cef_string_userfree_free(pArg);

	if (name.equals(MSG_init_ipc)) {
		pArg = args.get_string(1);
		String initString = CEF.ExtractCEFString(pArg);
		CEF3.cef_string_userfree_free(pArg);
		onIPCInit(ipcId, initString);
		return;
	} else if (name.equals(MSG_dispose_ipc)) {
		onIPCDispose(ipcId);
		return;
	}

	final CEFIPCSharedFile adapter = (CEFIPCSharedFile)ipcAdapters.get(ipcId);

	if (name.equals(MSG_on_before_navigation)) {
		pArg = args.get_string(1);
		final String url = CEF.ExtractCEFString(pArg);
		CEF3.cef_string_userfree_free(pArg);
		browser.getDisplay().asyncExec(new Runnable() {
			public void run() {
				if (browser.isDisposed()) return;
				boolean doit = onLocationChanging(url);
				adapter.sendResponse(String.valueOf(doit ? 1 : 0));
			}
		});
	}
}

void onResize() {
	Rectangle bounds = browser.getClientArea();
	OS.SetWindowPos(windowHandle, 0, bounds.x, bounds.y, bounds.width, bounds.height, OS.SWP_NOZORDER | OS.SWP_DRAWFRAME | OS.SWP_NOACTIVATE | OS.SWP_ASYNCWINDOWPOS);
}

void onStatusMessage(String status) {
	StatusTextEvent event = new StatusTextEvent(browser);
	event.display = browser.getDisplay ();
	event.widget = browser;
	event.text = status;
	for (int i = 0; i < statusTextListeners.length; i++) {
		statusTextListeners[i].changed(event);
	}
}

void onTitleChange(String title) {
	TitleEvent event = new TitleEvent(browser);
	event.display = browser.getDisplay();
	event.widget = browser;
	event.title = title;
	for (int i = 0; i < titleListeners.length; i++) {
		titleListeners[i].changed(event);
	}
}

public void refresh() {
	if (cefBrowser == null) return;
	htmlText = null;
	cefBrowser.reload();
}

public boolean setText(String html, boolean trusted) {
	if (cefBrowser == null) {
		if (!creatingBrowser) return false;
		pendingText = new Object[] {html, new Boolean(trusted)};
		pendingUrl = null;
		return true;
	}

	if (htmlText != null) {
		/*
		 * about:blank is already loading in response to a previous setText()
		 * invocation, so just change the text that will be set into it
		 */
		htmlText = html;
		return true;
	}

	long /*int*/ pFrame = cefBrowser.get_main_frame();
	if (pFrame == 0) {
		return false;
	}

	htmlText = html;
	CEFFrame frame = new CEFFrame(pFrame);
	cef_string_t strUrl = CreateCEFString(ABOUT_BLANK);
	frame.load_url(strUrl);
	return true;
}

public boolean setUrl(String url, String postData, String[] headers) {
	if (cefBrowser == null) {
		if (!creatingBrowser) return false;
		pendingText = null;
		pendingUrl = new Object[] {url, postData, headers};
		return true;
	}

	htmlText = null;

	// TODO postData, headers...
	long /*int*/ pFrame = cefBrowser.get_main_frame();
	if (pFrame == 0) {
		return false;
	}

	CEFFrame frame = new CEFFrame(pFrame);
	cef_string_t strUrl = CreateCEFString(url);
	frame.load_url(strUrl);
	return true;
}

public void stop() {
	htmlText = null;
	if (cefBrowser == null) {
		pendingText = pendingUrl = null;
		return;
	}

	cefBrowser.stop_load();
}

}
