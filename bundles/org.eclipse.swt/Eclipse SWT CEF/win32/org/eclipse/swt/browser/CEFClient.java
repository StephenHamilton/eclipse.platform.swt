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

import org.eclipse.swt.graphics.Device;
import org.eclipse.swt.internal.cef3.*;

public class CEFClient {
	CEF host;
	CEF3Object object;
	CEFContextMenuHandler contextMenuHandler;
	CEFDisplayHandler displayHandler;
	CEFDownloadHandler downloadHandler;
	CEFFocusHandler focusHandler;
	CEFLifeSpanHandler lifeSpanHandler;
	CEFLoadHandler loadHandler;
	CEFRequestHandler requestHandler;
	int refCount = 1;

public CEFClient(CEF host) {
	super();
	this.host = host;
	object = new CEF3Object (new int[] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3}) {
		public long /*int*/ method0(long /*int*/[] args) {return add_ref();}
		public long /*int*/ method1(long /*int*/[] args) {return CEFClient.this.release();}
		public long /*int*/ method2(long /*int*/[] args) {return get_refct();}
		public long /*int*/ method3(long /*int*/[] args) {return get_context_menu_handler();}
		public long /*int*/ method4(long /*int*/[] args) {return get_dialog_handler();}
		public long /*int*/ method5(long /*int*/[] args) {return get_display_handler();}
		public long /*int*/ method6(long /*int*/[] args) {return get_download_handler();}
		public long /*int*/ method7(long /*int*/[] args) {return get_focus_handler();}
		public long /*int*/ method8(long /*int*/[] args) {return get_geolocation_handler();}
		public long /*int*/ method9(long /*int*/[] args) {return get_jsdialog_handler();}
		public long /*int*/ method10(long /*int*/[] args) {return get_keyboard_handler();}
		public long /*int*/ method11(long /*int*/[] args) {return get_life_span_handler();}
		public long /*int*/ method12(long /*int*/[] args) {return get_load_handler();}
		public long /*int*/ method13(long /*int*/[] args) {return get_render_handler();}
		public long /*int*/ method14(long /*int*/[] args) {return get_request_handler();}
		public long /*int*/ method15(long /*int*/[] args) {return on_process_message_received(args[0], args[1], args[2]);}
	};
}

long /*int*/ getAddress () {
	return object.getAddress ();
}

/* cef_base_t */

synchronized int add_ref() {
	refCount++;
	return refCount;
}

synchronized int get_refct() {
	return refCount;
}

synchronized int release() {
	if (--refCount == 0) {
		if (Device.DEBUG) System.out.println("release: CEFClient");
		if (contextMenuHandler != null) {
			contextMenuHandler.release();
			contextMenuHandler = null;
		}
		if (displayHandler != null) {
			displayHandler.release();
			displayHandler = null;
		}
		if (downloadHandler != null) {
			downloadHandler.release();
			downloadHandler = null;
		}
		if (focusHandler != null) {
			focusHandler.release();
			focusHandler = null;
		}
		if (lifeSpanHandler != null) {
			lifeSpanHandler.release();
			lifeSpanHandler = null;
		}
		if (loadHandler != null) {
			loadHandler.release();
			loadHandler = null;
		}
		if (requestHandler != null) {
			requestHandler.release();
			requestHandler = null;
		}
		if (object != null) {
			object.dispose ();
		}
		object = null;
	}
	return refCount;
}

/* cef_client_t */

long /*int*/ get_context_menu_handler() {
	if (Device.DEBUG) System.out.println("get_context_menu_handler (impl)");
	if (contextMenuHandler == null) {
		contextMenuHandler = new CEFContextMenuHandler(host);
	}
	contextMenuHandler.add_ref();
	return contextMenuHandler.getAddress();
}

long /*int*/ get_dialog_handler() {
	if (Device.DEBUG) System.out.println("get_dialog_handler");
	return 0;
}

long /*int*/ get_display_handler() {
	if (Device.DEBUG) System.out.println("get_display_handler (impl)");
	if (displayHandler == null) {
		displayHandler = new CEFDisplayHandler(host);
	}
	displayHandler.add_ref();
	return displayHandler.getAddress();
}

long /*int*/ get_download_handler() {
	if (Device.DEBUG) System.out.println("get_download_handler (impl)");
	if (downloadHandler == null) {
		downloadHandler = new CEFDownloadHandler(host);
	}
	downloadHandler.add_ref();
	return downloadHandler.getAddress();
}

long /*int*/ get_focus_handler() {
	if (Device.DEBUG) System.out.println("get_focus_handler (impl)");
	if (focusHandler == null) {
		focusHandler = new CEFFocusHandler();
	}
	focusHandler.add_ref();
	return focusHandler.getAddress();
}

long /*int*/ get_geolocation_handler() {
	if (Device.DEBUG) System.out.println("get_geolocation_handler");
	return 0;
}

long /*int*/ get_jsdialog_handler() {
	if (Device.DEBUG) System.out.println("get_jsdialog_handler");
	return 0;
}

long /*int*/ get_keyboard_handler() {
	if (Device.DEBUG) System.out.println("get_keyboard_handler (TODO)");
	return 0;
}

long /*int*/ get_life_span_handler() {
	if (Device.DEBUG) System.out.println("get_life_span_handler (impl)");
	if (lifeSpanHandler == null) {
		lifeSpanHandler = new CEFLifeSpanHandler(host);
	}
	lifeSpanHandler.add_ref();
	return lifeSpanHandler.getAddress();
}

long /*int*/ get_load_handler() {
	if (Device.DEBUG) System.out.println("get_load_handler (impl)");
	if (loadHandler == null) {
		loadHandler = new CEFLoadHandler(host);
	}
	loadHandler.add_ref();
	return loadHandler.getAddress();
}

long /*int*/ get_render_handler() {
	if (Device.DEBUG) System.out.println("get_render_handler");
	return 0;
}

long /*int*/ get_request_handler() {
	if (Device.DEBUG) System.out.println("get_request_handler (impl)");
	if (requestHandler == null) {
		requestHandler = new CEFRequestHandler();
	}
	requestHandler.add_ref();
	return requestHandler.getAddress();
}

long /*int*/ on_process_message_received(long /*int*/ browser, long /*int*/ source_process, long /*int*/ message) {
	if (Device.DEBUG) System.out.println("on_process_message_received (impl)");
	host.onMessageReceived(message);
	new CEFBase(browser).release();
	new CEFBase(message).release();
	return 1;
}

}
