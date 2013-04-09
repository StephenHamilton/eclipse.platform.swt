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
package org.eclipse.swt.internal.cef3;

import org.eclipse.swt.internal.*;


public class CEF3 extends C {

	public static final int PID_RENDERER = 1;

/**
 * @param client cast=(struct _cef_client_t*)
 * @param url cast=(const cef_string_t*)
 */
public static final native int cef_browser_host_create_browser(cef_window_info_t windowInfo, long /*int*/ client, cef_string_t url, cef_browser_settings_t settings);

public static final native int cef_build_revision();

/** @param application cast=(struct _cef_app_t*) */
public static final native int cef_execute_process(cef_main_args_t args, long /*int*/ application);

/** @param application cast=(struct _cef_app_t*) */
public static final native int cef_initialize(cef_main_args_t args, cef_settings_t settings, long /*int*/ application);

/** @param name cast=(cef_string_t*) */
public static final native long /*int*/ cef_process_message_create(cef_string_t name);

/**
 * @param src cast=(void*)
 * @param output cast=(cef_string_t*)
 */
public static final native int cef_string_set(char[] src, long /*int*/ src_len, cef_string_t output, int copy);

/** @param str cast=(cef_string_userfree_t) */
public static final native void cef_string_userfree_free(long /*int*/ str);

/**
 * @param dest cast=(void *),flags=no_in critical
 * @param src cast=(const void *)
 * @param size cast=(size_t)
 */
public static final native void memmove(cef_base_t dest, long /*int*/ src, long /*int*/ size);

/**
 * @param dest cast=(void *),flags=no_in critical
 * @param src cast=(const void *)
 * @param size cast=(size_t)
 */
public static final native void memmove(cef_browser_t dest, long /*int*/ src, long /*int*/ size);

/**
 * @param dest cast=(void *),flags=no_in critical
 * @param src cast=(const void *)
 * @param size cast=(size_t)
 */
public static final native void memmove(cef_browser_host_t dest, long /*int*/ src, long /*int*/ size);

/**
 * @param dest cast=(void *),flags=no_in critical
 * @param src cast=(const void *)
 * @param size cast=(size_t)
 */
public static final native void memmove(cef_before_download_callback_t dest, long /*int*/ src, long /*int*/ size);

/**
 * @param dest cast=(void *),flags=no_in critical
 * @param src cast=(const void *)
 * @param size cast=(size_t)
 */
public static final native void memmove(cef_context_menu_params_t dest, long /*int*/ src, long /*int*/ size);

/**
 * @param dest cast=(void *),flags=no_in critical
 * @param src cast=(const void *)
 * @param size cast=(size_t)
 */
public static final native void memmove(cef_download_item_t dest, long /*int*/ src, long /*int*/ size);

/**
 * @param dest cast=(void *),flags=no_in critical
 * @param src cast=(const void *)
 * @param size cast=(size_t)
 */
public static final native void memmove(cef_download_item_callback_t dest, long /*int*/ src, long /*int*/ size);
/**
 * @param dest cast=(void *),flags=no_in critical
 * @param src cast=(const void *)
 * @param size cast=(size_t)
 */
public static final native void memmove(cef_frame_t dest, long /*int*/ src, long /*int*/ size);

/**
 * @param dest cast=(void *),flags=no_in critical
 * @param src cast=(const void *)
 * @param size cast=(size_t)
 */
public static final native void memmove(cef_list_value_t dest, long /*int*/ src, long /*int*/ size);

/**
 * @param dest cast=(void *),flags=no_in critical
 * @param src cast=(const void *)
 * @param size cast=(size_t)
 */
public static final native void memmove(cef_menu_model_t dest, long /*int*/ src, long /*int*/ size);

/**
 * @param dest cast=(void *),flags=no_in critical
 * @param src cast=(const void *)
 * @param size cast=(size_t)
 */
public static final native void memmove(cef_process_message_t dest, long /*int*/ src, long /*int*/ size);

/**
 * @param dest cast=(void *),flags=no_in critical
 * @param src cast=(const void *)
 * @param size cast=(size_t)
 */
public static final native void memmove(cef_string_t dest, long /*int*/ src, long /*int*/ size);


/* function ptr invocations */

/** @method convention=CEF_CALLBACK */
public static final native int callFuncInt(long /*int*/ address, long /*int*/ arg0);
/** @method convention=CEF_CALLBACK */
public static final native int callFuncInt(long /*int*/ address, long /*int*/ arg0, int arg1, int arg2);
/** @method convention=CEF_CALLBACK */
public static final native int callFuncInt(long /*int*/ address, long /*int*/ arg0, int arg1, long arg2);
/** @method convention=CEF_CALLBACK */
public static final native int callFuncInt(long /*int*/ address, long /*int*/ arg0, int arg1, cef_string_t arg2);
/** @method convention=CEF_CALLBACK */
public static final native long callFuncLong(long /*int*/ address, long /*int*/ arg0);
/** @method convention=CEF_CALLBACK */
public static final native long /*int*/ callFuncPtr(long /*int*/ address, long /*int*/ arg0);
/** @method convention=CEF_CALLBACK */
public static final native long /*int*/ callFuncPtr(long /*int*/ address, long /*int*/ arg0, int arg1);
/** @method convention=CEF_CALLBACK */
public static final native void callFuncVoid(long /*int*/ address, long /*int*/ arg0);
/** @method convention=CEF_CALLBACK */
public static final native void callFuncVoid(long /*int*/ address, long /*int*/ arg0, cef_string_t arg1);
/** @method convention=CEF_CALLBACK */
public static final native void callFuncVoid(long /*int*/ address, long /*int*/ arg0, cef_string_t arg1, int arg2);
/** @method convention=CEF_CALLBACK */
public static final native void callFuncVoid(long /*int*/ address, long /*int*/ arg0, cef_string_t arg1, cef_string_t arg2);
/** @method convention=CEF_CALLBACK */
public static final native void callFuncVoid(long /*int*/ address, long /*int*/ arg0, int arg1, int arg2, int arg3);
/** @method convention=CEF_CALLBACK */
public static final native void callFuncVoid(long /*int*/ address, long /*int*/ arg0, long arg1, long arg2, int arg3);
/** @method convention=CEF_CALLBACK */
public static final native void callFuncVoid(long /*int*/ address, long /*int*/ arg0, cef_string_t arg1, cef_string_t arg2, int arg3);


/* 64 bit */

public static final native int cef_base_t_sizeof();
public static final native int cef_browser_t_sizeof();
public static final native int cef_browser_host_t_sizeof();
public static final native int cef_browser_settings_t_sizeof();
public static final native int cef_before_download_callback_t_sizeof();
public static final native int cef_context_menu_params_t_sizeof();
public static final native int cef_download_item_t_sizeof();
public static final native int cef_download_item_callback_t_sizeof();
public static final native int cef_frame_t_sizeof();
public static final native int cef_list_value_t_sizeof();
public static final native int cef_process_message_t_sizeof();
public static final native int cef_settings_t_sizeof();
public static final native int cef_string_t_sizeof();

}
