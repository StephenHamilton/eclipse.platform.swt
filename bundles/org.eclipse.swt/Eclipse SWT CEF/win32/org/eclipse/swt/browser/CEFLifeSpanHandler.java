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
import org.eclipse.swt.graphics.Point;
import org.eclipse.swt.internal.cef3.*;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Widget;

public class CEFLifeSpanHandler {
	CEF3Object object;
	int refCount = 1;
	CEF host;

public CEFLifeSpanHandler(CEF host) {
	super();
	this.host = host;
	object = new CEF3Object (new int[] {0, 0, 0, 9, 1, 1, 1, 1}) {
		public long /*int*/ method0(long /*int*/[] args) {return add_ref();}
		public long /*int*/ method1(long /*int*/[] args) {return CEFLifeSpanHandler.this.release();}
		public long /*int*/ method2(long /*int*/[] args) {return get_refct();}
		public long /*int*/ method3(long /*int*/[] args) {return on_before_popup(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8]);}
		public long /*int*/ method4(long /*int*/[] args) {return on_after_created(args[0]);}
		public long /*int*/ method5(long /*int*/[] args) {return run_modal(args[0]);}
		public long /*int*/ method6(long /*int*/[] args) {return do_close(args[0]);}
		public long /*int*/ method7(long /*int*/[] args) {return on_before_close(args[0]);}
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
		if (Device.DEBUG) System.out.println("release: CEFLifeSpanHandler");
		if (object != null) {
			object.dispose ();
		}
		object = null;
	}
	return refCount;
}

/* cef_life_span_handler_t */

long /*int*/ on_before_popup(long /*int*/ browser, long /*int*/ frame, final long /*int*/ target_url, long /*int*/ target_frame_name, long /*int*/ pPopupFeatures, long /*int*/ windowInfo, long /*int*/ client, long /*int*/ settings, long /*int*/ no_javascript_access) {
	if (Device.DEBUG) System.out.println("on_before_popup (impl)");
	final cef_popup_features_t popupFeatures = new cef_popup_features_t();
	CEF3.memmove(popupFeatures, pPopupFeatures, cef_popup_features_t.sizeof);
	final int result[] = new int[1];
	result[0] = 0;
	host.browser.getDisplay().syncExec(new Runnable() {
		public void run() {
			if (host.browser.isDisposed()) return;
			result[0] = host.onWindowOpen(target_url, popupFeatures);
		}
	});
	
	new CEFBase(browser).release();
	new CEFBase(frame).release();
	// does client need to be released too?
	// Probably not, it is not a direct reference (it is a **cef_client_t, possibly a list of them?)
	// The reference is held elsewhere.
	return result[0];
}

long /*int*/ on_after_created(long /*int*/ browser) {
	if (Device.DEBUG) System.out.println("on_after_created (impl)");
	if (host != null) {
		host.browserCreated(browser);
	}
	new CEFBase(browser).release();
	return 0;
}

long /*int*/ run_modal(long /*int*/ browser) {
	if (Device.DEBUG) System.out.println("run_modal");
	new CEFBase(browser).release();
	return 0;
}

long /*int*/ do_close(long /*int*/ pBrowser) {
	/* possibly useful */
	if (Device.DEBUG) System.out.println("do_close");
	CEFBrowser cefBrowser = new CEFBrowser(pBrowser);
	final Browser browser = CEF.findBrowser(cefBrowser);
	final CEF webBrowser = ((CEF)browser.webBrowser);
	browser.getDisplay().asyncExec(new Runnable() {
		public void run() {
			if (browser.isDisposed()) return;
			webBrowser.onWindowClose();
		}
	});
	cefBrowser.release();
	// Not sure if I need to release the host at some point.
	// There is no rule for structs that are returned by a method.
	return 1;
}

long /*int*/ on_before_close(long /*int*/ browser) {
	if (Device.DEBUG) System.out.println("on_before_close");
	new CEFBase(browser).release();
	return 0;
}

}
