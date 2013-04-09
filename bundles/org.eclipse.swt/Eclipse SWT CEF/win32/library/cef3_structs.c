/*******************************************************************************
 * Copyright (c) 2000, 2013 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *    IBM Corporation - initial API and implementation
 *******************************************************************************/

#include "swt.h"
#include "cef3_structs.h"

#ifndef NO_cef_base_t
typedef struct cef_base_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID size, add_ref, release, get_refct;
} cef_base_t_FID_CACHE;

cef_base_t_FID_CACHE cef_base_tFc;

void cachecef_base_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_base_tFc.cached) return;
	cef_base_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_base_tFc.size = (*env)->GetFieldID(env, cef_base_tFc.clazz, "size", I_J);
	cef_base_tFc.add_ref = (*env)->GetFieldID(env, cef_base_tFc.clazz, "add_ref", I_J);
	cef_base_tFc.release = (*env)->GetFieldID(env, cef_base_tFc.clazz, "release", I_J);
	cef_base_tFc.get_refct = (*env)->GetFieldID(env, cef_base_tFc.clazz, "get_refct", I_J);
	cef_base_tFc.cached = 1;
}

cef_base_t *getcef_base_tFields(JNIEnv *env, jobject lpObject, cef_base_t *lpStruct)
{
	if (!cef_base_tFc.cached) cachecef_base_tFields(env, lpObject);
	lpStruct->size = (*env)->GetIntLongField(env, lpObject, cef_base_tFc.size);
	lpStruct->add_ref = (int (CEF_CALLBACK *)(struct _cef_base_t* self))(*env)->GetIntLongField(env, lpObject, cef_base_tFc.add_ref);
	lpStruct->release = (int (CEF_CALLBACK *)(struct _cef_base_t* self))(*env)->GetIntLongField(env, lpObject, cef_base_tFc.release);
	lpStruct->get_refct = (int (CEF_CALLBACK *)(struct _cef_base_t* self))(*env)->GetIntLongField(env, lpObject, cef_base_tFc.get_refct);
	return lpStruct;
}

void setcef_base_tFields(JNIEnv *env, jobject lpObject, cef_base_t *lpStruct)
{
	if (!cef_base_tFc.cached) cachecef_base_tFields(env, lpObject);
	(*env)->SetIntLongField(env, lpObject, cef_base_tFc.size, (jintLong)lpStruct->size);
	(*env)->SetIntLongField(env, lpObject, cef_base_tFc.add_ref, (jintLong)lpStruct->add_ref);
	(*env)->SetIntLongField(env, lpObject, cef_base_tFc.release, (jintLong)lpStruct->release);
	(*env)->SetIntLongField(env, lpObject, cef_base_tFc.get_refct, (jintLong)lpStruct->get_refct);
}
#endif

#ifndef NO_cef_before_download_callback_t
typedef struct cef_before_download_callback_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID cont;
} cef_before_download_callback_t_FID_CACHE;

cef_before_download_callback_t_FID_CACHE cef_before_download_callback_tFc;

void cachecef_before_download_callback_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_before_download_callback_tFc.cached) return;
	cachecef_base_tFields(env, lpObject);
	cef_before_download_callback_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_before_download_callback_tFc.cont = (*env)->GetFieldID(env, cef_before_download_callback_tFc.clazz, "cont", I_J);
	cef_before_download_callback_tFc.cached = 1;
}

cef_before_download_callback_t *getcef_before_download_callback_tFields(JNIEnv *env, jobject lpObject, cef_before_download_callback_t *lpStruct)
{
	if (!cef_before_download_callback_tFc.cached) cachecef_before_download_callback_tFields(env, lpObject);
	getcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	lpStruct->cont = (void (CEF_CALLBACK *)(struct _cef_before_download_callback_t* self, const cef_string_t* download_path, int show_dialog))(*env)->GetIntLongField(env, lpObject, cef_before_download_callback_tFc.cont);
	return lpStruct;
}

void setcef_before_download_callback_tFields(JNIEnv *env, jobject lpObject, cef_before_download_callback_t *lpStruct)
{
	if (!cef_before_download_callback_tFc.cached) cachecef_before_download_callback_tFields(env, lpObject);
	setcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	(*env)->SetIntLongField(env, lpObject, cef_before_download_callback_tFc.cont, (jintLong)lpStruct->cont);
}
#endif

#ifndef NO_cef_browser_host_t
typedef struct cef_browser_host_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID get_browser, parent_window_will_close, close_browser, set_focus, get_window_handle, get_opener_window_handle, get_client, get_dev_tools_url, get_zoom_level, set_zoom_level, run_file_dialog;
} cef_browser_host_t_FID_CACHE;

cef_browser_host_t_FID_CACHE cef_browser_host_tFc;

void cachecef_browser_host_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_browser_host_tFc.cached) return;
	cachecef_base_tFields(env, lpObject);
	cef_browser_host_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_browser_host_tFc.get_browser = (*env)->GetFieldID(env, cef_browser_host_tFc.clazz, "get_browser", I_J);
	cef_browser_host_tFc.parent_window_will_close = (*env)->GetFieldID(env, cef_browser_host_tFc.clazz, "parent_window_will_close", I_J);
	cef_browser_host_tFc.close_browser = (*env)->GetFieldID(env, cef_browser_host_tFc.clazz, "close_browser", I_J);
	cef_browser_host_tFc.set_focus = (*env)->GetFieldID(env, cef_browser_host_tFc.clazz, "set_focus", I_J);
	cef_browser_host_tFc.get_window_handle = (*env)->GetFieldID(env, cef_browser_host_tFc.clazz, "get_window_handle", I_J);
	cef_browser_host_tFc.get_opener_window_handle = (*env)->GetFieldID(env, cef_browser_host_tFc.clazz, "get_opener_window_handle", I_J);
	cef_browser_host_tFc.get_client = (*env)->GetFieldID(env, cef_browser_host_tFc.clazz, "get_client", I_J);
	cef_browser_host_tFc.get_dev_tools_url = (*env)->GetFieldID(env, cef_browser_host_tFc.clazz, "get_dev_tools_url", I_J);
	cef_browser_host_tFc.get_zoom_level = (*env)->GetFieldID(env, cef_browser_host_tFc.clazz, "get_zoom_level", I_J);
	cef_browser_host_tFc.set_zoom_level = (*env)->GetFieldID(env, cef_browser_host_tFc.clazz, "set_zoom_level", I_J);
	cef_browser_host_tFc.run_file_dialog = (*env)->GetFieldID(env, cef_browser_host_tFc.clazz, "run_file_dialog", I_J);
	cef_browser_host_tFc.cached = 1;
}

cef_browser_host_t *getcef_browser_host_tFields(JNIEnv *env, jobject lpObject, cef_browser_host_t *lpStruct)
{
	if (!cef_browser_host_tFc.cached) cachecef_browser_host_tFields(env, lpObject);
	getcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	lpStruct->get_browser = (struct _cef_browser_t* (CEF_CALLBACK *)(struct _cef_browser_host_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_host_tFc.get_browser);
	lpStruct->parent_window_will_close = (void (CEF_CALLBACK *)(struct _cef_browser_host_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_host_tFc.parent_window_will_close);
	lpStruct->close_browser = (void (CEF_CALLBACK *)(struct _cef_browser_host_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_host_tFc.close_browser);
	lpStruct->set_focus = (void (CEF_CALLBACK *)(struct _cef_browser_host_t* self, int enable))(*env)->GetIntLongField(env, lpObject, cef_browser_host_tFc.set_focus);
	lpStruct->get_window_handle = (cef_window_handle_t (CEF_CALLBACK *)(struct _cef_browser_host_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_host_tFc.get_window_handle);
	lpStruct->get_opener_window_handle = (cef_window_handle_t (CEF_CALLBACK *)(struct _cef_browser_host_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_host_tFc.get_opener_window_handle);
	lpStruct->get_client = (struct _cef_client_t* (CEF_CALLBACK *)(struct _cef_browser_host_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_host_tFc.get_client);
	lpStruct->get_dev_tools_url = (cef_string_userfree_t (CEF_CALLBACK *)(struct _cef_browser_host_t* self, int http_scheme))(*env)->GetIntLongField(env, lpObject, cef_browser_host_tFc.get_dev_tools_url);
	lpStruct->get_zoom_level = (double (CEF_CALLBACK *)(struct _cef_browser_host_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_host_tFc.get_zoom_level);
	lpStruct->set_zoom_level = (void (CEF_CALLBACK *)(struct _cef_browser_host_t* self, double zoomLevel))(*env)->GetIntLongField(env, lpObject, cef_browser_host_tFc.set_zoom_level);
	lpStruct->run_file_dialog = (void (CEF_CALLBACK *)(struct _cef_browser_host_t* self, enum cef_file_dialog_mode_t mode, const cef_string_t* title, const cef_string_t* default_file_name, cef_string_list_t accept_types, struct _cef_run_file_dialog_callback_t* callback))(*env)->GetIntLongField(env, lpObject, cef_browser_host_tFc.run_file_dialog);
	return lpStruct;
}

void setcef_browser_host_tFields(JNIEnv *env, jobject lpObject, cef_browser_host_t *lpStruct)
{
	if (!cef_browser_host_tFc.cached) cachecef_browser_host_tFields(env, lpObject);
	setcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	(*env)->SetIntLongField(env, lpObject, cef_browser_host_tFc.get_browser, (jintLong)lpStruct->get_browser);
	(*env)->SetIntLongField(env, lpObject, cef_browser_host_tFc.parent_window_will_close, (jintLong)lpStruct->parent_window_will_close);
	(*env)->SetIntLongField(env, lpObject, cef_browser_host_tFc.close_browser, (jintLong)lpStruct->close_browser);
	(*env)->SetIntLongField(env, lpObject, cef_browser_host_tFc.set_focus, (jintLong)lpStruct->set_focus);
	(*env)->SetIntLongField(env, lpObject, cef_browser_host_tFc.get_window_handle, (jintLong)lpStruct->get_window_handle);
	(*env)->SetIntLongField(env, lpObject, cef_browser_host_tFc.get_opener_window_handle, (jintLong)lpStruct->get_opener_window_handle);
	(*env)->SetIntLongField(env, lpObject, cef_browser_host_tFc.get_client, (jintLong)lpStruct->get_client);
	(*env)->SetIntLongField(env, lpObject, cef_browser_host_tFc.get_dev_tools_url, (jintLong)lpStruct->get_dev_tools_url);
	(*env)->SetIntLongField(env, lpObject, cef_browser_host_tFc.get_zoom_level, (jintLong)lpStruct->get_zoom_level);
	(*env)->SetIntLongField(env, lpObject, cef_browser_host_tFc.set_zoom_level, (jintLong)lpStruct->set_zoom_level);
	(*env)->SetIntLongField(env, lpObject, cef_browser_host_tFc.run_file_dialog, (jintLong)lpStruct->run_file_dialog);
}
#endif

#ifndef NO_cef_browser_settings_t
typedef struct cef_browser_settings_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID size, standard_font_family, fixed_font_family, serif_font_family, sans_serif_font_family, cursive_font_family, fantasy_font_family, default_font_size, default_fixed_font_size, minimum_font_size, minimum_logical_font_size, default_encoding, user_style_sheet_location, remote_fonts, javascript, javascript_open_windows, javascript_close_windows, javascript_access_clipboard, javascript_dom_paste, caret_browsing, java, plugins, universal_access_from_file_urls, file_access_from_file_urls, web_security, image_loading, image_shrink_standalone_to_fit, text_area_resize, page_cache, tab_to_links, author_and_user_styles, local_storage, databases, application_cache, webgl, accelerated_compositing, developer_tools;
} cef_browser_settings_t_FID_CACHE;

cef_browser_settings_t_FID_CACHE cef_browser_settings_tFc;

void cachecef_browser_settings_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_browser_settings_tFc.cached) return;
	cef_browser_settings_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_browser_settings_tFc.size = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "size", I_J);
	cef_browser_settings_tFc.standard_font_family = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "standard_font_family", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_browser_settings_tFc.fixed_font_family = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "fixed_font_family", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_browser_settings_tFc.serif_font_family = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "serif_font_family", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_browser_settings_tFc.sans_serif_font_family = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "sans_serif_font_family", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_browser_settings_tFc.cursive_font_family = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "cursive_font_family", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_browser_settings_tFc.fantasy_font_family = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "fantasy_font_family", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_browser_settings_tFc.default_font_size = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "default_font_size", "I");
	cef_browser_settings_tFc.default_fixed_font_size = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "default_fixed_font_size", "I");
	cef_browser_settings_tFc.minimum_font_size = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "minimum_font_size", "I");
	cef_browser_settings_tFc.minimum_logical_font_size = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "minimum_logical_font_size", "I");
	cef_browser_settings_tFc.default_encoding = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "default_encoding", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_browser_settings_tFc.user_style_sheet_location = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "user_style_sheet_location", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_browser_settings_tFc.remote_fonts = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "remote_fonts", "I");
	cef_browser_settings_tFc.javascript = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "javascript", "I");
	cef_browser_settings_tFc.javascript_open_windows = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "javascript_open_windows", "I");
	cef_browser_settings_tFc.javascript_close_windows = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "javascript_close_windows", "I");
	cef_browser_settings_tFc.javascript_access_clipboard = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "javascript_access_clipboard", "I");
	cef_browser_settings_tFc.javascript_dom_paste = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "javascript_dom_paste", "I");
	cef_browser_settings_tFc.caret_browsing = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "caret_browsing", "I");
	cef_browser_settings_tFc.java = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "java", "I");
	cef_browser_settings_tFc.plugins = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "plugins", "I");
	cef_browser_settings_tFc.universal_access_from_file_urls = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "universal_access_from_file_urls", "I");
	cef_browser_settings_tFc.file_access_from_file_urls = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "file_access_from_file_urls", "I");
	cef_browser_settings_tFc.web_security = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "web_security", "I");
	cef_browser_settings_tFc.image_loading = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "image_loading", "I");
	cef_browser_settings_tFc.image_shrink_standalone_to_fit = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "image_shrink_standalone_to_fit", "I");
	cef_browser_settings_tFc.text_area_resize = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "text_area_resize", "I");
	cef_browser_settings_tFc.page_cache = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "page_cache", "I");
	cef_browser_settings_tFc.tab_to_links = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "tab_to_links", "I");
	cef_browser_settings_tFc.author_and_user_styles = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "author_and_user_styles", "I");
	cef_browser_settings_tFc.local_storage = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "local_storage", "I");
	cef_browser_settings_tFc.databases = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "databases", "I");
	cef_browser_settings_tFc.application_cache = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "application_cache", "I");
	cef_browser_settings_tFc.webgl = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "webgl", "I");
	cef_browser_settings_tFc.accelerated_compositing = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "accelerated_compositing", "I");
	cef_browser_settings_tFc.developer_tools = (*env)->GetFieldID(env, cef_browser_settings_tFc.clazz, "developer_tools", "I");
	cef_browser_settings_tFc.cached = 1;
}

cef_browser_settings_t *getcef_browser_settings_tFields(JNIEnv *env, jobject lpObject, cef_browser_settings_t *lpStruct)
{
	if (!cef_browser_settings_tFc.cached) cachecef_browser_settings_tFields(env, lpObject);
	lpStruct->size = (*env)->GetIntLongField(env, lpObject, cef_browser_settings_tFc.size);
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.standard_font_family);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->standard_font_family);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.fixed_font_family);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->fixed_font_family);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.serif_font_family);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->serif_font_family);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.sans_serif_font_family);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->sans_serif_font_family);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.cursive_font_family);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->cursive_font_family);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.fantasy_font_family);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->fantasy_font_family);
	}
	lpStruct->default_font_size = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.default_font_size);
	lpStruct->default_fixed_font_size = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.default_fixed_font_size);
	lpStruct->minimum_font_size = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.minimum_font_size);
	lpStruct->minimum_logical_font_size = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.minimum_logical_font_size);
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.default_encoding);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->default_encoding);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.user_style_sheet_location);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->user_style_sheet_location);
	}
	lpStruct->remote_fonts = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.remote_fonts);
	lpStruct->javascript = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.javascript);
	lpStruct->javascript_open_windows = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.javascript_open_windows);
	lpStruct->javascript_close_windows = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.javascript_close_windows);
	lpStruct->javascript_access_clipboard = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.javascript_access_clipboard);
	lpStruct->javascript_dom_paste = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.javascript_dom_paste);
	lpStruct->caret_browsing = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.caret_browsing);
	lpStruct->java = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.java);
	lpStruct->plugins = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.plugins);
	lpStruct->universal_access_from_file_urls = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.universal_access_from_file_urls);
	lpStruct->file_access_from_file_urls = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.file_access_from_file_urls);
	lpStruct->web_security = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.web_security);
	lpStruct->image_loading = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.image_loading);
	lpStruct->image_shrink_standalone_to_fit = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.image_shrink_standalone_to_fit);
	lpStruct->text_area_resize = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.text_area_resize);
	lpStruct->page_cache = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.page_cache);
	lpStruct->tab_to_links = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.tab_to_links);
	lpStruct->author_and_user_styles = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.author_and_user_styles);
	lpStruct->local_storage = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.local_storage);
	lpStruct->databases = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.databases);
	lpStruct->application_cache = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.application_cache);
	lpStruct->webgl = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.webgl);
	lpStruct->accelerated_compositing = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.accelerated_compositing);
	lpStruct->developer_tools = (*env)->GetIntField(env, lpObject, cef_browser_settings_tFc.developer_tools);
	return lpStruct;
}

void setcef_browser_settings_tFields(JNIEnv *env, jobject lpObject, cef_browser_settings_t *lpStruct)
{
	if (!cef_browser_settings_tFc.cached) cachecef_browser_settings_tFields(env, lpObject);
	(*env)->SetIntLongField(env, lpObject, cef_browser_settings_tFc.size, (jintLong)lpStruct->size);
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.standard_font_family);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->standard_font_family);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.fixed_font_family);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->fixed_font_family);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.serif_font_family);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->serif_font_family);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.sans_serif_font_family);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->sans_serif_font_family);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.cursive_font_family);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->cursive_font_family);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.fantasy_font_family);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->fantasy_font_family);
	}
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.default_font_size, (jint)lpStruct->default_font_size);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.default_fixed_font_size, (jint)lpStruct->default_fixed_font_size);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.minimum_font_size, (jint)lpStruct->minimum_font_size);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.minimum_logical_font_size, (jint)lpStruct->minimum_logical_font_size);
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.default_encoding);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->default_encoding);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_browser_settings_tFc.user_style_sheet_location);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->user_style_sheet_location);
	}
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.remote_fonts, (jint)lpStruct->remote_fonts);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.javascript, (jint)lpStruct->javascript);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.javascript_open_windows, (jint)lpStruct->javascript_open_windows);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.javascript_close_windows, (jint)lpStruct->javascript_close_windows);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.javascript_access_clipboard, (jint)lpStruct->javascript_access_clipboard);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.javascript_dom_paste, (jint)lpStruct->javascript_dom_paste);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.caret_browsing, (jint)lpStruct->caret_browsing);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.java, (jint)lpStruct->java);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.plugins, (jint)lpStruct->plugins);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.universal_access_from_file_urls, (jint)lpStruct->universal_access_from_file_urls);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.file_access_from_file_urls, (jint)lpStruct->file_access_from_file_urls);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.web_security, (jint)lpStruct->web_security);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.image_loading, (jint)lpStruct->image_loading);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.image_shrink_standalone_to_fit, (jint)lpStruct->image_shrink_standalone_to_fit);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.text_area_resize, (jint)lpStruct->text_area_resize);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.page_cache, (jint)lpStruct->page_cache);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.tab_to_links, (jint)lpStruct->tab_to_links);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.author_and_user_styles, (jint)lpStruct->author_and_user_styles);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.local_storage, (jint)lpStruct->local_storage);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.databases, (jint)lpStruct->databases);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.application_cache, (jint)lpStruct->application_cache);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.webgl, (jint)lpStruct->webgl);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.accelerated_compositing, (jint)lpStruct->accelerated_compositing);
	(*env)->SetIntField(env, lpObject, cef_browser_settings_tFc.developer_tools, (jint)lpStruct->developer_tools);
}
#endif

#ifndef NO_cef_browser_t
typedef struct cef_browser_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID get_host, can_go_back, go_back, can_go_forward, go_forward, is_loading, reload, reload_ignore_cache, stop_load, get_identifier, is_same, is_popup, has_document, get_main_frame, get_focused_frame, get_frame_byident, get_frame, get_frame_count, get_frame_identifiers, get_frame_names, send_process_message;
} cef_browser_t_FID_CACHE;

cef_browser_t_FID_CACHE cef_browser_tFc;

void cachecef_browser_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_browser_tFc.cached) return;
	cachecef_base_tFields(env, lpObject);
	cef_browser_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_browser_tFc.get_host = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "get_host", I_J);
	cef_browser_tFc.can_go_back = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "can_go_back", I_J);
	cef_browser_tFc.go_back = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "go_back", I_J);
	cef_browser_tFc.can_go_forward = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "can_go_forward", I_J);
	cef_browser_tFc.go_forward = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "go_forward", I_J);
	cef_browser_tFc.is_loading = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "is_loading", I_J);
	cef_browser_tFc.reload = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "reload", I_J);
	cef_browser_tFc.reload_ignore_cache = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "reload_ignore_cache", I_J);
	cef_browser_tFc.stop_load = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "stop_load", I_J);
	cef_browser_tFc.get_identifier = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "get_identifier", I_J);
	cef_browser_tFc.is_same = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "is_same", I_J);
	cef_browser_tFc.is_popup = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "is_popup", I_J);
	cef_browser_tFc.has_document = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "has_document", I_J);
	cef_browser_tFc.get_main_frame = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "get_main_frame", I_J);
	cef_browser_tFc.get_focused_frame = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "get_focused_frame", I_J);
	cef_browser_tFc.get_frame_byident = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "get_frame_byident", I_J);
	cef_browser_tFc.get_frame = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "get_frame", I_J);
	cef_browser_tFc.get_frame_count = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "get_frame_count", I_J);
	cef_browser_tFc.get_frame_identifiers = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "get_frame_identifiers", I_J);
	cef_browser_tFc.get_frame_names = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "get_frame_names", I_J);
	cef_browser_tFc.send_process_message = (*env)->GetFieldID(env, cef_browser_tFc.clazz, "send_process_message", I_J);
	cef_browser_tFc.cached = 1;
}

cef_browser_t *getcef_browser_tFields(JNIEnv *env, jobject lpObject, cef_browser_t *lpStruct)
{
	if (!cef_browser_tFc.cached) cachecef_browser_tFields(env, lpObject);
	getcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	lpStruct->get_host = (struct _cef_browser_host_t* (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.get_host);
	lpStruct->can_go_back = (int (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.can_go_back);
	lpStruct->go_back = (void (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.go_back);
	lpStruct->can_go_forward = (int (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.can_go_forward);
	lpStruct->go_forward = (void (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.go_forward);
	lpStruct->is_loading = (int (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.is_loading);
	lpStruct->reload = (void (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.reload);
	lpStruct->reload_ignore_cache = (void (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.reload_ignore_cache);
	lpStruct->stop_load = (void (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.stop_load);
	lpStruct->get_identifier = (int (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.get_identifier);
	lpStruct->is_same = (int (CEF_CALLBACK *)(struct _cef_browser_t* self, struct _cef_browser_t* that))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.is_same);
	lpStruct->is_popup = (int (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.is_popup);
	lpStruct->has_document = (int (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.has_document);
	lpStruct->get_main_frame = (struct _cef_frame_t* (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.get_main_frame);
	lpStruct->get_focused_frame = (struct _cef_frame_t* (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.get_focused_frame);
	lpStruct->get_frame_byident = (struct _cef_frame_t* (CEF_CALLBACK *)(struct _cef_browser_t* self, int64 identifier))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.get_frame_byident);
	lpStruct->get_frame = (struct _cef_frame_t* (CEF_CALLBACK *)(struct _cef_browser_t* self, const cef_string_t* name))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.get_frame);
	lpStruct->get_frame_count = (size_t (CEF_CALLBACK *)(struct _cef_browser_t* self))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.get_frame_count);
	lpStruct->get_frame_identifiers = (void (CEF_CALLBACK *)(struct _cef_browser_t* self, size_t* identifiersCount, int64* identifiers))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.get_frame_identifiers);
	lpStruct->get_frame_names = (void (CEF_CALLBACK *)(struct _cef_browser_t* self, cef_string_list_t names))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.get_frame_names);
	lpStruct->send_process_message = (int (CEF_CALLBACK *)(struct _cef_browser_t* self, enum cef_process_id_t target_process, struct _cef_process_message_t* message))(*env)->GetIntLongField(env, lpObject, cef_browser_tFc.send_process_message);
	return lpStruct;
}

void setcef_browser_tFields(JNIEnv *env, jobject lpObject, cef_browser_t *lpStruct)
{
	if (!cef_browser_tFc.cached) cachecef_browser_tFields(env, lpObject);
	setcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.get_host, (jintLong)lpStruct->get_host);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.can_go_back, (jintLong)lpStruct->can_go_back);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.go_back, (jintLong)lpStruct->go_back);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.can_go_forward, (jintLong)lpStruct->can_go_forward);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.go_forward, (jintLong)lpStruct->go_forward);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.is_loading, (jintLong)lpStruct->is_loading);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.reload, (jintLong)lpStruct->reload);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.reload_ignore_cache, (jintLong)lpStruct->reload_ignore_cache);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.stop_load, (jintLong)lpStruct->stop_load);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.get_identifier, (jintLong)lpStruct->get_identifier);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.is_same, (jintLong)lpStruct->is_same);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.is_popup, (jintLong)lpStruct->is_popup);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.has_document, (jintLong)lpStruct->has_document);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.get_main_frame, (jintLong)lpStruct->get_main_frame);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.get_focused_frame, (jintLong)lpStruct->get_focused_frame);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.get_frame_byident, (jintLong)lpStruct->get_frame_byident);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.get_frame, (jintLong)lpStruct->get_frame);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.get_frame_count, (jintLong)lpStruct->get_frame_count);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.get_frame_identifiers, (jintLong)lpStruct->get_frame_identifiers);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.get_frame_names, (jintLong)lpStruct->get_frame_names);
	(*env)->SetIntLongField(env, lpObject, cef_browser_tFc.send_process_message, (jintLong)lpStruct->send_process_message);
}
#endif

#ifndef NO_cef_context_menu_params_t
typedef struct cef_context_menu_params_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID get_xcoord, get_ycoord, get_type_flags, get_link_url, get_unfiltered_link_url, get_source_url, is_image_blocked, get_page_url, get_frame_url, get_frame_charset, get_media_type, get_media_state_flags, get_selection_text, is_editable, is_speech_input_enabled, get_edit_state_flags;
} cef_context_menu_params_t_FID_CACHE;

cef_context_menu_params_t_FID_CACHE cef_context_menu_params_tFc;

void cachecef_context_menu_params_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_context_menu_params_tFc.cached) return;
	cachecef_base_tFields(env, lpObject);
	cef_context_menu_params_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_context_menu_params_tFc.get_xcoord = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "get_xcoord", I_J);
	cef_context_menu_params_tFc.get_ycoord = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "get_ycoord", I_J);
	cef_context_menu_params_tFc.get_type_flags = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "get_type_flags", I_J);
	cef_context_menu_params_tFc.get_link_url = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "get_link_url", I_J);
	cef_context_menu_params_tFc.get_unfiltered_link_url = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "get_unfiltered_link_url", I_J);
	cef_context_menu_params_tFc.get_source_url = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "get_source_url", I_J);
	cef_context_menu_params_tFc.is_image_blocked = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "is_image_blocked", I_J);
	cef_context_menu_params_tFc.get_page_url = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "get_page_url", I_J);
	cef_context_menu_params_tFc.get_frame_url = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "get_frame_url", I_J);
	cef_context_menu_params_tFc.get_frame_charset = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "get_frame_charset", I_J);
	cef_context_menu_params_tFc.get_media_type = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "get_media_type", I_J);
	cef_context_menu_params_tFc.get_media_state_flags = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "get_media_state_flags", I_J);
	cef_context_menu_params_tFc.get_selection_text = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "get_selection_text", I_J);
	cef_context_menu_params_tFc.is_editable = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "is_editable", I_J);
	cef_context_menu_params_tFc.is_speech_input_enabled = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "is_speech_input_enabled", I_J);
	cef_context_menu_params_tFc.get_edit_state_flags = (*env)->GetFieldID(env, cef_context_menu_params_tFc.clazz, "get_edit_state_flags", I_J);
	cef_context_menu_params_tFc.cached = 1;
}

cef_context_menu_params_t *getcef_context_menu_params_tFields(JNIEnv *env, jobject lpObject, cef_context_menu_params_t *lpStruct)
{
	if (!cef_context_menu_params_tFc.cached) cachecef_context_menu_params_tFields(env, lpObject);
	getcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	lpStruct->get_xcoord = (int (CEF_CALLBACK *)(struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_xcoord);
	lpStruct->get_ycoord = (int (CEF_CALLBACK *)(struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_ycoord);
	lpStruct->get_type_flags = (enum cef_context_menu_type_flags_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_type_flags);
	lpStruct->get_link_url = (cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_link_url);
	lpStruct->get_unfiltered_link_url = (cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_unfiltered_link_url);
	lpStruct->get_source_url = (cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_source_url);
	lpStruct->is_image_blocked = (int (CEF_CALLBACK *)(struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.is_image_blocked);
	lpStruct->get_page_url = (cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_page_url);
	lpStruct->get_frame_url = (cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_frame_url);
	lpStruct->get_frame_charset = (cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_frame_charset);
	lpStruct->get_media_type = (enum cef_context_menu_media_type_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_media_type);
	lpStruct->get_media_state_flags = (enum cef_context_menu_media_state_flags_t ( CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_media_state_flags);
	lpStruct->get_selection_text = (cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_selection_text);
	lpStruct->is_editable = (int (CEF_CALLBACK *)(struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.is_editable);
	lpStruct->is_speech_input_enabled = (int (CEF_CALLBACK *)(struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.is_speech_input_enabled);
	lpStruct->get_edit_state_flags = (enum cef_context_menu_edit_state_flags_t (CEF_CALLBACK *)(struct _cef_context_menu_params_t* self))(*env)->GetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_edit_state_flags);
	return lpStruct;
}

void setcef_context_menu_params_tFields(JNIEnv *env, jobject lpObject, cef_context_menu_params_t *lpStruct)
{
	if (!cef_context_menu_params_tFc.cached) cachecef_context_menu_params_tFields(env, lpObject);
	setcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_xcoord, (jintLong)lpStruct->get_xcoord);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_ycoord, (jintLong)lpStruct->get_ycoord);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_type_flags, (jintLong)lpStruct->get_type_flags);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_link_url, (jintLong)lpStruct->get_link_url);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_unfiltered_link_url, (jintLong)lpStruct->get_unfiltered_link_url);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_source_url, (jintLong)lpStruct->get_source_url);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.is_image_blocked, (jintLong)lpStruct->is_image_blocked);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_page_url, (jintLong)lpStruct->get_page_url);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_frame_url, (jintLong)lpStruct->get_frame_url);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_frame_charset, (jintLong)lpStruct->get_frame_charset);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_media_type, (jintLong)lpStruct->get_media_type);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_media_state_flags, (jintLong)lpStruct->get_media_state_flags);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_selection_text, (jintLong)lpStruct->get_selection_text);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.is_editable, (jintLong)lpStruct->is_editable);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.is_speech_input_enabled, (jintLong)lpStruct->is_speech_input_enabled);
	(*env)->SetIntLongField(env, lpObject, cef_context_menu_params_tFc.get_edit_state_flags, (jintLong)lpStruct->get_edit_state_flags);
}
#endif

#ifndef NO_cef_download_item_callback_t
typedef struct cef_download_item_callback_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID cancel;
} cef_download_item_callback_t_FID_CACHE;

cef_download_item_callback_t_FID_CACHE cef_download_item_callback_tFc;

void cachecef_download_item_callback_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_download_item_callback_tFc.cached) return;
	cachecef_base_tFields(env, lpObject);
	cef_download_item_callback_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_download_item_callback_tFc.cancel = (*env)->GetFieldID(env, cef_download_item_callback_tFc.clazz, "cancel", I_J);
	cef_download_item_callback_tFc.cached = 1;
}

cef_download_item_callback_t *getcef_download_item_callback_tFields(JNIEnv *env, jobject lpObject, cef_download_item_callback_t *lpStruct)
{
	if (!cef_download_item_callback_tFc.cached) cachecef_download_item_callback_tFields(env, lpObject);
	getcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	lpStruct->cancel = (void (CEF_CALLBACK *)(struct _cef_download_item_callback_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_callback_tFc.cancel);
	return lpStruct;
}

void setcef_download_item_callback_tFields(JNIEnv *env, jobject lpObject, cef_download_item_callback_t *lpStruct)
{
	if (!cef_download_item_callback_tFc.cached) cachecef_download_item_callback_tFields(env, lpObject);
	setcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_callback_tFc.cancel, (jintLong)lpStruct->cancel);
}
#endif

#ifndef NO_cef_download_item_t
typedef struct cef_download_item_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID is_valid, is_in_progress, is_complete, is_canceled, get_current_speed, get_percent_complete, get_total_bytes, get_received_bytes, get_start_time, get_end_time, get_full_path, get_id, get_url, get_suggested_file_name, get_content_disposition, get_mime_type;
} cef_download_item_t_FID_CACHE;

cef_download_item_t_FID_CACHE cef_download_item_tFc;

void cachecef_download_item_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_download_item_tFc.cached) return;
	cachecef_base_tFields(env, lpObject);
	cef_download_item_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_download_item_tFc.is_valid = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "is_valid", I_J);
	cef_download_item_tFc.is_in_progress = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "is_in_progress", I_J);
	cef_download_item_tFc.is_complete = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "is_complete", I_J);
	cef_download_item_tFc.is_canceled = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "is_canceled", I_J);
	cef_download_item_tFc.get_current_speed = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "get_current_speed", I_J);
	cef_download_item_tFc.get_percent_complete = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "get_percent_complete", I_J);
	cef_download_item_tFc.get_total_bytes = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "get_total_bytes", I_J);
	cef_download_item_tFc.get_received_bytes = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "get_received_bytes", I_J);
	cef_download_item_tFc.get_start_time = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "get_start_time", I_J);
	cef_download_item_tFc.get_end_time = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "get_end_time", I_J);
	cef_download_item_tFc.get_full_path = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "get_full_path", I_J);
	cef_download_item_tFc.get_id = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "get_id", I_J);
	cef_download_item_tFc.get_url = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "get_url", I_J);
	cef_download_item_tFc.get_suggested_file_name = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "get_suggested_file_name", I_J);
	cef_download_item_tFc.get_content_disposition = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "get_content_disposition", I_J);
	cef_download_item_tFc.get_mime_type = (*env)->GetFieldID(env, cef_download_item_tFc.clazz, "get_mime_type", I_J);
	cef_download_item_tFc.cached = 1;
}

cef_download_item_t *getcef_download_item_tFields(JNIEnv *env, jobject lpObject, cef_download_item_t *lpStruct)
{
	if (!cef_download_item_tFc.cached) cachecef_download_item_tFields(env, lpObject);
	getcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	lpStruct->is_valid = (int (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.is_valid);
	lpStruct->is_in_progress = (int (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.is_in_progress);
	lpStruct->is_complete = (int (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.is_complete);
	lpStruct->is_canceled = (int (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.is_canceled);
	lpStruct->get_current_speed = (int64 (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.get_current_speed);
	lpStruct->get_percent_complete = (int (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.get_percent_complete);
	lpStruct->get_total_bytes = (int64 (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.get_total_bytes);
	lpStruct->get_received_bytes = (int64 (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.get_received_bytes);
	lpStruct->get_start_time = (cef_time_t (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.get_start_time);
	lpStruct->get_end_time = (cef_time_t (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.get_end_time);
	lpStruct->get_full_path = (cef_string_userfree_t (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.get_full_path);
	lpStruct->get_id = (int32 (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.get_id);
	lpStruct->get_url = (cef_string_userfree_t (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.get_url);
	lpStruct->get_suggested_file_name = (cef_string_userfree_t (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.get_suggested_file_name);
	lpStruct->get_content_disposition = (cef_string_userfree_t (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.get_content_disposition);
	lpStruct->get_mime_type = (cef_string_userfree_t (CEF_CALLBACK *)(struct _cef_download_item_t* self))(*env)->GetIntLongField(env, lpObject, cef_download_item_tFc.get_mime_type);
	return lpStruct;
}

void setcef_download_item_tFields(JNIEnv *env, jobject lpObject, cef_download_item_t *lpStruct)
{
	if (!cef_download_item_tFc.cached) cachecef_download_item_tFields(env, lpObject);
	setcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.is_valid, (jintLong)lpStruct->is_valid);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.is_in_progress, (jintLong)lpStruct->is_in_progress);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.is_complete, (jintLong)lpStruct->is_complete);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.is_canceled, (jintLong)lpStruct->is_canceled);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.get_current_speed, (jintLong)lpStruct->get_current_speed);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.get_percent_complete, (jintLong)lpStruct->get_percent_complete);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.get_total_bytes, (jintLong)lpStruct->get_total_bytes);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.get_received_bytes, (jintLong)lpStruct->get_received_bytes);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.get_start_time, (jintLong)lpStruct->get_start_time);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.get_end_time, (jintLong)lpStruct->get_end_time);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.get_full_path, (jintLong)lpStruct->get_full_path);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.get_id, (jintLong)lpStruct->get_id);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.get_url, (jintLong)lpStruct->get_url);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.get_suggested_file_name, (jintLong)lpStruct->get_suggested_file_name);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.get_content_disposition, (jintLong)lpStruct->get_content_disposition);
	(*env)->SetIntLongField(env, lpObject, cef_download_item_tFc.get_mime_type, (jintLong)lpStruct->get_mime_type);
}
#endif

#ifndef NO_cef_frame_t
typedef struct cef_frame_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID is_valid, undo, redo, cut, copy, paste, del, select_all, view_source, get_source, get_text, load_request, load_url, load_string, execute_java_script, is_main, is_focused, get_name, get_identifier, get_parent, get_url, get_browser, get_v8context, visit_dom;
} cef_frame_t_FID_CACHE;

cef_frame_t_FID_CACHE cef_frame_tFc;

void cachecef_frame_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_frame_tFc.cached) return;
	cachecef_base_tFields(env, lpObject);
	cef_frame_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_frame_tFc.is_valid = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "is_valid", I_J);
	cef_frame_tFc.undo = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "undo", I_J);
	cef_frame_tFc.redo = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "redo", I_J);
	cef_frame_tFc.cut = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "cut", I_J);
	cef_frame_tFc.copy = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "copy", I_J);
	cef_frame_tFc.paste = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "paste", I_J);
	cef_frame_tFc.del = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "del", I_J);
	cef_frame_tFc.select_all = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "select_all", I_J);
	cef_frame_tFc.view_source = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "view_source", I_J);
	cef_frame_tFc.get_source = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "get_source", I_J);
	cef_frame_tFc.get_text = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "get_text", I_J);
	cef_frame_tFc.load_request = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "load_request", I_J);
	cef_frame_tFc.load_url = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "load_url", I_J);
	cef_frame_tFc.load_string = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "load_string", I_J);
	cef_frame_tFc.execute_java_script = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "execute_java_script", I_J);
	cef_frame_tFc.is_main = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "is_main", I_J);
	cef_frame_tFc.is_focused = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "is_focused", I_J);
	cef_frame_tFc.get_name = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "get_name", I_J);
	cef_frame_tFc.get_identifier = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "get_identifier", I_J);
	cef_frame_tFc.get_parent = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "get_parent", I_J);
	cef_frame_tFc.get_url = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "get_url", I_J);
	cef_frame_tFc.get_browser = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "get_browser", I_J);
	cef_frame_tFc.get_v8context = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "get_v8context", I_J);
	cef_frame_tFc.visit_dom = (*env)->GetFieldID(env, cef_frame_tFc.clazz, "visit_dom", I_J);
	cef_frame_tFc.cached = 1;
}

cef_frame_t *getcef_frame_tFields(JNIEnv *env, jobject lpObject, cef_frame_t *lpStruct)
{
	if (!cef_frame_tFc.cached) cachecef_frame_tFields(env, lpObject);
	getcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	lpStruct->is_valid = (int (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.is_valid);
	lpStruct->undo = (void (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.undo);
	lpStruct->redo = (void (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.redo);
	lpStruct->cut = (void (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.cut);
	lpStruct->copy = (void (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.copy);
	lpStruct->paste = (void (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.paste);
	lpStruct->del = (void (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.del);
	lpStruct->select_all = (void (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.select_all);
	lpStruct->view_source = (void (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.view_source);
	lpStruct->get_source = (void (CEF_CALLBACK *)(struct _cef_frame_t* self, struct _cef_string_visitor_t* visitor))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.get_source);
	lpStruct->get_text = (void (CEF_CALLBACK *)(struct _cef_frame_t* self, struct _cef_string_visitor_t* visitor))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.get_text);
	lpStruct->load_request = (void (CEF_CALLBACK *)(struct _cef_frame_t* self, struct _cef_request_t* request))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.load_request);
	lpStruct->load_url = (void (CEF_CALLBACK *)(struct _cef_frame_t* self, const cef_string_t* url))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.load_url);
	lpStruct->load_string = (void (CEF_CALLBACK *)(struct _cef_frame_t* self, const cef_string_t* string_val, const cef_string_t* url))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.load_string);
	lpStruct->execute_java_script = (void (CEF_CALLBACK *)(struct _cef_frame_t* self, const cef_string_t* code, const cef_string_t* script_url, int start_line))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.execute_java_script);
	lpStruct->is_main = (int (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.is_main);
	lpStruct->is_focused = (int (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.is_focused);
	lpStruct->get_name = (cef_string_userfree_t (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.get_name);
	lpStruct->get_identifier = (int64 (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.get_identifier);
	lpStruct->get_parent = (struct _cef_frame_t* (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.get_parent);
	lpStruct->get_url = (cef_string_userfree_t (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.get_url);
	lpStruct->get_browser = (struct _cef_browser_t* (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.get_browser);
	lpStruct->get_v8context = (struct _cef_v8context_t* (CEF_CALLBACK *)(struct _cef_frame_t* self))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.get_v8context);
	lpStruct->visit_dom = (void (CEF_CALLBACK *)(struct _cef_frame_t* self, struct _cef_domvisitor_t* visitor))(*env)->GetIntLongField(env, lpObject, cef_frame_tFc.visit_dom);
	return lpStruct;
}

void setcef_frame_tFields(JNIEnv *env, jobject lpObject, cef_frame_t *lpStruct)
{
	if (!cef_frame_tFc.cached) cachecef_frame_tFields(env, lpObject);
	setcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.is_valid, (jintLong)lpStruct->is_valid);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.undo, (jintLong)lpStruct->undo);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.redo, (jintLong)lpStruct->redo);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.cut, (jintLong)lpStruct->cut);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.copy, (jintLong)lpStruct->copy);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.paste, (jintLong)lpStruct->paste);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.del, (jintLong)lpStruct->del);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.select_all, (jintLong)lpStruct->select_all);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.view_source, (jintLong)lpStruct->view_source);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.get_source, (jintLong)lpStruct->get_source);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.get_text, (jintLong)lpStruct->get_text);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.load_request, (jintLong)lpStruct->load_request);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.load_url, (jintLong)lpStruct->load_url);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.load_string, (jintLong)lpStruct->load_string);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.execute_java_script, (jintLong)lpStruct->execute_java_script);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.is_main, (jintLong)lpStruct->is_main);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.is_focused, (jintLong)lpStruct->is_focused);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.get_name, (jintLong)lpStruct->get_name);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.get_identifier, (jintLong)lpStruct->get_identifier);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.get_parent, (jintLong)lpStruct->get_parent);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.get_url, (jintLong)lpStruct->get_url);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.get_browser, (jintLong)lpStruct->get_browser);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.get_v8context, (jintLong)lpStruct->get_v8context);
	(*env)->SetIntLongField(env, lpObject, cef_frame_tFc.visit_dom, (jintLong)lpStruct->visit_dom);
}
#endif

#ifndef NO_cef_list_value_t
typedef struct cef_list_value_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID is_valid, is_owned, is_read_only, copy, set_size, get_size, clear, remove, get_type, get_bool, get_int, get_double, get_string, get_binary, get_dictionary, get_list, set_null, set_bool, set_int, set_double, set_string, set_binary, set_dictionary, set_list;
} cef_list_value_t_FID_CACHE;

cef_list_value_t_FID_CACHE cef_list_value_tFc;

void cachecef_list_value_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_list_value_tFc.cached) return;
	cachecef_base_tFields(env, lpObject);
	cef_list_value_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_list_value_tFc.is_valid = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "is_valid", I_J);
	cef_list_value_tFc.is_owned = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "is_owned", I_J);
	cef_list_value_tFc.is_read_only = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "is_read_only", I_J);
	cef_list_value_tFc.copy = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "copy", I_J);
	cef_list_value_tFc.set_size = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "set_size", I_J);
	cef_list_value_tFc.get_size = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "get_size", I_J);
	cef_list_value_tFc.clear = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "clear", I_J);
	cef_list_value_tFc.remove = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "remove", I_J);
	cef_list_value_tFc.get_type = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "get_type", I_J);
	cef_list_value_tFc.get_bool = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "get_bool", I_J);
	cef_list_value_tFc.get_int = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "get_int", I_J);
	cef_list_value_tFc.get_double = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "get_double", I_J);
	cef_list_value_tFc.get_string = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "get_string", I_J);
	cef_list_value_tFc.get_binary = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "get_binary", I_J);
	cef_list_value_tFc.get_dictionary = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "get_dictionary", I_J);
	cef_list_value_tFc.get_list = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "get_list", I_J);
	cef_list_value_tFc.set_null = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "set_null", I_J);
	cef_list_value_tFc.set_bool = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "set_bool", I_J);
	cef_list_value_tFc.set_int = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "set_int", I_J);
	cef_list_value_tFc.set_double = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "set_double", I_J);
	cef_list_value_tFc.set_string = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "set_string", I_J);
	cef_list_value_tFc.set_binary = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "set_binary", I_J);
	cef_list_value_tFc.set_dictionary = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "set_dictionary", I_J);
	cef_list_value_tFc.set_list = (*env)->GetFieldID(env, cef_list_value_tFc.clazz, "set_list", I_J);
	cef_list_value_tFc.cached = 1;
}

cef_list_value_t *getcef_list_value_tFields(JNIEnv *env, jobject lpObject, cef_list_value_t *lpStruct)
{
	if (!cef_list_value_tFc.cached) cachecef_list_value_tFields(env, lpObject);
	getcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	lpStruct->is_valid = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.is_valid);
	lpStruct->is_owned = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.is_owned);
	lpStruct->is_read_only = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.is_read_only);
	lpStruct->copy = (struct _cef_list_value_t* (CEF_CALLBACK *)(struct _cef_list_value_t* self))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.copy);
	lpStruct->set_size = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self, size_t size))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.set_size);
	lpStruct->get_size = (size_t (CEF_CALLBACK *)(struct _cef_list_value_t* self))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.get_size);
	lpStruct->clear = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.clear);
	lpStruct->remove = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.remove);
	lpStruct->get_type = (enum cef_value_type_t (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.get_type);
	lpStruct->get_bool = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.get_bool);
	lpStruct->get_int = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.get_int);
	lpStruct->get_double = (double (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.get_double);
	lpStruct->get_string = (cef_string_userfree_t (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.get_string);
	lpStruct->get_binary = (struct _cef_binary_value_t* (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.get_binary);
	lpStruct->get_dictionary = (struct _cef_dictionary_value_t* (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.get_dictionary);
	lpStruct->get_list = (struct _cef_list_value_t* (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.get_list);
	lpStruct->set_null = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.set_null);
	lpStruct->set_bool = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index, int value))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.set_bool);
	lpStruct->set_int = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index, int value))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.set_int);
	lpStruct->set_double = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index, double value))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.set_double);
	lpStruct->set_string = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index, const cef_string_t* value))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.set_string);
	lpStruct->set_binary = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index, struct _cef_binary_value_t* value))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.set_binary);
	lpStruct->set_dictionary = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index, struct _cef_dictionary_value_t* value))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.set_dictionary);
	lpStruct->set_list = (int (CEF_CALLBACK *)(struct _cef_list_value_t* self, int index, struct _cef_list_value_t* value))(*env)->GetIntLongField(env, lpObject, cef_list_value_tFc.set_list);
	return lpStruct;
}

void setcef_list_value_tFields(JNIEnv *env, jobject lpObject, cef_list_value_t *lpStruct)
{
	if (!cef_list_value_tFc.cached) cachecef_list_value_tFields(env, lpObject);
	setcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.is_valid, (jintLong)lpStruct->is_valid);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.is_owned, (jintLong)lpStruct->is_owned);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.is_read_only, (jintLong)lpStruct->is_read_only);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.copy, (jintLong)lpStruct->copy);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.set_size, (jintLong)lpStruct->set_size);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.get_size, (jintLong)lpStruct->get_size);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.clear, (jintLong)lpStruct->clear);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.remove, (jintLong)lpStruct->remove);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.get_type, (jintLong)lpStruct->get_type);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.get_bool, (jintLong)lpStruct->get_bool);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.get_int, (jintLong)lpStruct->get_int);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.get_double, (jintLong)lpStruct->get_double);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.get_string, (jintLong)lpStruct->get_string);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.get_binary, (jintLong)lpStruct->get_binary);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.get_dictionary, (jintLong)lpStruct->get_dictionary);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.get_list, (jintLong)lpStruct->get_list);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.set_null, (jintLong)lpStruct->set_null);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.set_bool, (jintLong)lpStruct->set_bool);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.set_int, (jintLong)lpStruct->set_int);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.set_double, (jintLong)lpStruct->set_double);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.set_string, (jintLong)lpStruct->set_string);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.set_binary, (jintLong)lpStruct->set_binary);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.set_dictionary, (jintLong)lpStruct->set_dictionary);
	(*env)->SetIntLongField(env, lpObject, cef_list_value_tFc.set_list, (jintLong)lpStruct->set_list);
}
#endif

#ifndef NO_cef_main_args_t
typedef struct cef_main_args_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID instance;
} cef_main_args_t_FID_CACHE;

cef_main_args_t_FID_CACHE cef_main_args_tFc;

void cachecef_main_args_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_main_args_tFc.cached) return;
	cef_main_args_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_main_args_tFc.instance = (*env)->GetFieldID(env, cef_main_args_tFc.clazz, "instance", I_J);
	cef_main_args_tFc.cached = 1;
}

cef_main_args_t *getcef_main_args_tFields(JNIEnv *env, jobject lpObject, cef_main_args_t *lpStruct)
{
	if (!cef_main_args_tFc.cached) cachecef_main_args_tFields(env, lpObject);
	lpStruct->instance = (HINSTANCE)(*env)->GetIntLongField(env, lpObject, cef_main_args_tFc.instance);
	return lpStruct;
}

void setcef_main_args_tFields(JNIEnv *env, jobject lpObject, cef_main_args_t *lpStruct)
{
	if (!cef_main_args_tFc.cached) cachecef_main_args_tFields(env, lpObject);
	(*env)->SetIntLongField(env, lpObject, cef_main_args_tFc.instance, (jintLong)lpStruct->instance);
}
#endif

#ifndef NO_cef_menu_model_t
typedef struct cef_menu_model_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID clear, get_count, add_separator, add_item, add_check_item, add_radio_item, add_sub_menu, insert_separator_at, insert_item_at, insert_check_item_at, insert_radio_item_at, insert_sub_menu_at, remove, remove_at, get_index_of, get_command_id_at, set_command_id_at, get_label, get_label_at, set_label, set_label_at, get_type, get_type_at, get_group_id, get_group_id_at, set_group_id, set_group_id_at, get_sub_menu, get_sub_menu_at, is_visible, is_visible_at, set_visible, set_visible_at, is_enabled, is_enabled_at, set_enabled, set_enabled_at, is_checked, is_checked_at, set_checked, set_checked_at, has_accelerator, has_accelerator_at, set_accelerator, set_accelerator_at, remove_accelerator, remove_accelerator_at, get_accelerator, get_accelerator_at;
} cef_menu_model_t_FID_CACHE;

cef_menu_model_t_FID_CACHE cef_menu_model_tFc;

void cachecef_menu_model_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_menu_model_tFc.cached) return;
	cachecef_base_tFields(env, lpObject);
	cef_menu_model_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_menu_model_tFc.clear = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "clear", I_J);
	cef_menu_model_tFc.get_count = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "get_count", I_J);
	cef_menu_model_tFc.add_separator = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "add_separator", I_J);
	cef_menu_model_tFc.add_item = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "add_item", I_J);
	cef_menu_model_tFc.add_check_item = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "add_check_item", I_J);
	cef_menu_model_tFc.add_radio_item = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "add_radio_item", I_J);
	cef_menu_model_tFc.add_sub_menu = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "add_sub_menu", I_J);
	cef_menu_model_tFc.insert_separator_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "insert_separator_at", I_J);
	cef_menu_model_tFc.insert_item_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "insert_item_at", I_J);
	cef_menu_model_tFc.insert_check_item_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "insert_check_item_at", I_J);
	cef_menu_model_tFc.insert_radio_item_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "insert_radio_item_at", I_J);
	cef_menu_model_tFc.insert_sub_menu_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "insert_sub_menu_at", I_J);
	cef_menu_model_tFc.remove = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "remove", I_J);
	cef_menu_model_tFc.remove_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "remove_at", I_J);
	cef_menu_model_tFc.get_index_of = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "get_index_of", I_J);
	cef_menu_model_tFc.get_command_id_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "get_command_id_at", I_J);
	cef_menu_model_tFc.set_command_id_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "set_command_id_at", I_J);
	cef_menu_model_tFc.get_label = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "get_label", I_J);
	cef_menu_model_tFc.get_label_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "get_label_at", I_J);
	cef_menu_model_tFc.set_label = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "set_label", I_J);
	cef_menu_model_tFc.set_label_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "set_label_at", I_J);
	cef_menu_model_tFc.get_type = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "get_type", I_J);
	cef_menu_model_tFc.get_type_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "get_type_at", I_J);
	cef_menu_model_tFc.get_group_id = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "get_group_id", I_J);
	cef_menu_model_tFc.get_group_id_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "get_group_id_at", I_J);
	cef_menu_model_tFc.set_group_id = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "set_group_id", I_J);
	cef_menu_model_tFc.set_group_id_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "set_group_id_at", I_J);
	cef_menu_model_tFc.get_sub_menu = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "get_sub_menu", I_J);
	cef_menu_model_tFc.get_sub_menu_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "get_sub_menu_at", I_J);
	cef_menu_model_tFc.is_visible = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "is_visible", I_J);
	cef_menu_model_tFc.is_visible_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "is_visible_at", I_J);
	cef_menu_model_tFc.set_visible = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "set_visible", I_J);
	cef_menu_model_tFc.set_visible_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "set_visible_at", I_J);
	cef_menu_model_tFc.is_enabled = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "is_enabled", I_J);
	cef_menu_model_tFc.is_enabled_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "is_enabled_at", I_J);
	cef_menu_model_tFc.set_enabled = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "set_enabled", I_J);
	cef_menu_model_tFc.set_enabled_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "set_enabled_at", I_J);
	cef_menu_model_tFc.is_checked = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "is_checked", I_J);
	cef_menu_model_tFc.is_checked_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "is_checked_at", I_J);
	cef_menu_model_tFc.set_checked = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "set_checked", I_J);
	cef_menu_model_tFc.set_checked_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "set_checked_at", I_J);
	cef_menu_model_tFc.has_accelerator = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "has_accelerator", I_J);
	cef_menu_model_tFc.has_accelerator_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "has_accelerator_at", I_J);
	cef_menu_model_tFc.set_accelerator = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "set_accelerator", I_J);
	cef_menu_model_tFc.set_accelerator_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "set_accelerator_at", I_J);
	cef_menu_model_tFc.remove_accelerator = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "remove_accelerator", I_J);
	cef_menu_model_tFc.remove_accelerator_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "remove_accelerator_at", I_J);
	cef_menu_model_tFc.get_accelerator = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "get_accelerator", I_J);
	cef_menu_model_tFc.get_accelerator_at = (*env)->GetFieldID(env, cef_menu_model_tFc.clazz, "get_accelerator_at", I_J);
	cef_menu_model_tFc.cached = 1;
}

cef_menu_model_t *getcef_menu_model_tFields(JNIEnv *env, jobject lpObject, cef_menu_model_t *lpStruct)
{
	if (!cef_menu_model_tFc.cached) cachecef_menu_model_tFields(env, lpObject);
	getcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	lpStruct->clear = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.clear);
	lpStruct->get_count = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.get_count);
	lpStruct->add_separator = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.add_separator);
	lpStruct->add_item = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, const cef_string_t* label))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.add_item);
	lpStruct->add_check_item = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, const cef_string_t* label))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.add_check_item);
	lpStruct->add_radio_item = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, const cef_string_t* label, int group_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.add_radio_item);
	lpStruct->add_sub_menu = (struct _cef_menu_model_t* (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int command_id, const cef_string_t* label))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.add_sub_menu);
	lpStruct->insert_separator_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.insert_separator_at);
	lpStruct->insert_item_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int command_id, const cef_string_t* label))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.insert_item_at);
	lpStruct->insert_check_item_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int command_id, const cef_string_t* label))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.insert_check_item_at);
	lpStruct->insert_radio_item_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int command_id, const cef_string_t* label, int group_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.insert_radio_item_at);
	lpStruct->insert_sub_menu_at = (struct _cef_menu_model_t* (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int index, int command_id, const cef_string_t* label))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.insert_sub_menu_at);
	lpStruct->remove = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.remove);
	lpStruct->remove_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.remove_at);
	lpStruct->get_index_of = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.get_index_of);
	lpStruct->get_command_id_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.get_command_id_at);
	lpStruct->set_command_id_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int command_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.set_command_id_at);
	lpStruct->get_label = (cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int command_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.get_label);
	lpStruct->get_label_at = (cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.get_label_at);
	lpStruct->set_label = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, const cef_string_t* label))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.set_label);
	lpStruct->set_label_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, const cef_string_t* label))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.set_label_at);
	lpStruct->get_type = (enum cef_menu_item_type_t (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int command_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.get_type);
	lpStruct->get_type_at = (enum cef_menu_item_type_t (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.get_type_at);
	lpStruct->get_group_id = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.get_group_id);
	lpStruct->get_group_id_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.get_group_id_at);
	lpStruct->set_group_id = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, int group_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.set_group_id);
	lpStruct->set_group_id_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int group_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.set_group_id_at);
	lpStruct->get_sub_menu = (struct _cef_menu_model_t* (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int command_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.get_sub_menu);
	lpStruct->get_sub_menu_at = (struct _cef_menu_model_t* (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.get_sub_menu_at);
	lpStruct->is_visible = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.is_visible);
	lpStruct->is_visible_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.is_visible_at);
	lpStruct->set_visible = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, int visible))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.set_visible);
	lpStruct->set_visible_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int visible))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.set_visible_at);
	lpStruct->is_enabled = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.is_enabled);
	lpStruct->is_enabled_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.is_enabled_at);
	lpStruct->set_enabled = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, int enabled))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.set_enabled);
	lpStruct->set_enabled_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int enabled))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.set_enabled_at);
	lpStruct->is_checked = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.is_checked);
	lpStruct->is_checked_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.is_checked_at);
	lpStruct->set_checked = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, int checked))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.set_checked);
	lpStruct->set_checked_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int checked))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.set_checked_at);
	lpStruct->has_accelerator = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.has_accelerator);
	lpStruct->has_accelerator_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.has_accelerator_at);
	lpStruct->set_accelerator = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, int key_code, int shift_pressed, int ctrl_pressed, int alt_pressed))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.set_accelerator);
	lpStruct->set_accelerator_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int key_code, int shift_pressed, int ctrl_pressed, int alt_pressed))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.set_accelerator_at);
	lpStruct->remove_accelerator = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.remove_accelerator);
	lpStruct->remove_accelerator_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.remove_accelerator_at);
	lpStruct->get_accelerator = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, int* key_code, int* shift_pressed, int* ctrl_pressed, int* alt_pressed))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.get_accelerator);
	lpStruct->get_accelerator_at = (int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int* key_code, int* shift_pressed, int* ctrl_pressed, int* alt_pressed))(*env)->GetIntLongField(env, lpObject, cef_menu_model_tFc.get_accelerator_at);
	return lpStruct;
}

void setcef_menu_model_tFields(JNIEnv *env, jobject lpObject, cef_menu_model_t *lpStruct)
{
	if (!cef_menu_model_tFc.cached) cachecef_menu_model_tFields(env, lpObject);
	setcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.clear, (jintLong)lpStruct->clear);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.get_count, (jintLong)lpStruct->get_count);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.add_separator, (jintLong)lpStruct->add_separator);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.add_item, (jintLong)lpStruct->add_item);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.add_check_item, (jintLong)lpStruct->add_check_item);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.add_radio_item, (jintLong)lpStruct->add_radio_item);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.add_sub_menu, (jintLong)lpStruct->add_sub_menu);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.insert_separator_at, (jintLong)lpStruct->insert_separator_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.insert_item_at, (jintLong)lpStruct->insert_item_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.insert_check_item_at, (jintLong)lpStruct->insert_check_item_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.insert_radio_item_at, (jintLong)lpStruct->insert_radio_item_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.insert_sub_menu_at, (jintLong)lpStruct->insert_sub_menu_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.remove, (jintLong)lpStruct->remove);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.remove_at, (jintLong)lpStruct->remove_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.get_index_of, (jintLong)lpStruct->get_index_of);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.get_command_id_at, (jintLong)lpStruct->get_command_id_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.set_command_id_at, (jintLong)lpStruct->set_command_id_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.get_label, (jintLong)lpStruct->get_label);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.get_label_at, (jintLong)lpStruct->get_label_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.set_label, (jintLong)lpStruct->set_label);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.set_label_at, (jintLong)lpStruct->set_label_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.get_type, (jintLong)lpStruct->get_type);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.get_type_at, (jintLong)lpStruct->get_type_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.get_group_id, (jintLong)lpStruct->get_group_id);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.get_group_id_at, (jintLong)lpStruct->get_group_id_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.set_group_id, (jintLong)lpStruct->set_group_id);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.set_group_id_at, (jintLong)lpStruct->set_group_id_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.get_sub_menu, (jintLong)lpStruct->get_sub_menu);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.get_sub_menu_at, (jintLong)lpStruct->get_sub_menu_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.is_visible, (jintLong)lpStruct->is_visible);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.is_visible_at, (jintLong)lpStruct->is_visible_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.set_visible, (jintLong)lpStruct->set_visible);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.set_visible_at, (jintLong)lpStruct->set_visible_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.is_enabled, (jintLong)lpStruct->is_enabled);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.is_enabled_at, (jintLong)lpStruct->is_enabled_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.set_enabled, (jintLong)lpStruct->set_enabled);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.set_enabled_at, (jintLong)lpStruct->set_enabled_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.is_checked, (jintLong)lpStruct->is_checked);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.is_checked_at, (jintLong)lpStruct->is_checked_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.set_checked, (jintLong)lpStruct->set_checked);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.set_checked_at, (jintLong)lpStruct->set_checked_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.has_accelerator, (jintLong)lpStruct->has_accelerator);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.has_accelerator_at, (jintLong)lpStruct->has_accelerator_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.set_accelerator, (jintLong)lpStruct->set_accelerator);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.set_accelerator_at, (jintLong)lpStruct->set_accelerator_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.remove_accelerator, (jintLong)lpStruct->remove_accelerator);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.remove_accelerator_at, (jintLong)lpStruct->remove_accelerator_at);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.get_accelerator, (jintLong)lpStruct->get_accelerator);
	(*env)->SetIntLongField(env, lpObject, cef_menu_model_tFc.get_accelerator_at, (jintLong)lpStruct->get_accelerator_at);
}
#endif

#ifndef NO_cef_process_message_t
typedef struct cef_process_message_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID is_valid, is_read_only, copy, get_name, get_argument_list;
} cef_process_message_t_FID_CACHE;

cef_process_message_t_FID_CACHE cef_process_message_tFc;

void cachecef_process_message_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_process_message_tFc.cached) return;
	cachecef_base_tFields(env, lpObject);
	cef_process_message_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_process_message_tFc.is_valid = (*env)->GetFieldID(env, cef_process_message_tFc.clazz, "is_valid", I_J);
	cef_process_message_tFc.is_read_only = (*env)->GetFieldID(env, cef_process_message_tFc.clazz, "is_read_only", I_J);
	cef_process_message_tFc.copy = (*env)->GetFieldID(env, cef_process_message_tFc.clazz, "copy", I_J);
	cef_process_message_tFc.get_name = (*env)->GetFieldID(env, cef_process_message_tFc.clazz, "get_name", I_J);
	cef_process_message_tFc.get_argument_list = (*env)->GetFieldID(env, cef_process_message_tFc.clazz, "get_argument_list", I_J);
	cef_process_message_tFc.cached = 1;
}

cef_process_message_t *getcef_process_message_tFields(JNIEnv *env, jobject lpObject, cef_process_message_t *lpStruct)
{
	if (!cef_process_message_tFc.cached) cachecef_process_message_tFields(env, lpObject);
	getcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	lpStruct->is_valid = (int (CEF_CALLBACK *)(struct _cef_process_message_t* self))(*env)->GetIntLongField(env, lpObject, cef_process_message_tFc.is_valid);
	lpStruct->is_read_only = (int (CEF_CALLBACK *)(struct _cef_process_message_t* self))(*env)->GetIntLongField(env, lpObject, cef_process_message_tFc.is_read_only);
	lpStruct->copy = (struct _cef_process_message_t* (CEF_CALLBACK *)(struct _cef_process_message_t* self))(*env)->GetIntLongField(env, lpObject, cef_process_message_tFc.copy);
	lpStruct->get_name = (cef_string_userfree_t (CEF_CALLBACK *)(struct _cef_process_message_t* self))(*env)->GetIntLongField(env, lpObject, cef_process_message_tFc.get_name);
	lpStruct->get_argument_list = (struct _cef_list_value_t* (CEF_CALLBACK *)(struct _cef_process_message_t* self))(*env)->GetIntLongField(env, lpObject, cef_process_message_tFc.get_argument_list);
	return lpStruct;
}

void setcef_process_message_tFields(JNIEnv *env, jobject lpObject, cef_process_message_t *lpStruct)
{
	if (!cef_process_message_tFc.cached) cachecef_process_message_tFields(env, lpObject);
	setcef_base_tFields(env, lpObject, (cef_base_t *)lpStruct);
	(*env)->SetIntLongField(env, lpObject, cef_process_message_tFc.is_valid, (jintLong)lpStruct->is_valid);
	(*env)->SetIntLongField(env, lpObject, cef_process_message_tFc.is_read_only, (jintLong)lpStruct->is_read_only);
	(*env)->SetIntLongField(env, lpObject, cef_process_message_tFc.copy, (jintLong)lpStruct->copy);
	(*env)->SetIntLongField(env, lpObject, cef_process_message_tFc.get_name, (jintLong)lpStruct->get_name);
	(*env)->SetIntLongField(env, lpObject, cef_process_message_tFc.get_argument_list, (jintLong)lpStruct->get_argument_list);
}
#endif

#ifndef NO_cef_settings_t
typedef struct cef_settings_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID size, single_process, browser_subprocess_path, multi_threaded_message_loop, command_line_args_disabled, cache_path, user_agent, product_version, locale, log_file, log_severity, release_dcheck_enabled, javascript_flags, resources_dir_path, locales_dir_path, pack_loading_disabled, remote_debugging_port, uncaught_exception_stack_size, context_safety_implementation;
} cef_settings_t_FID_CACHE;

cef_settings_t_FID_CACHE cef_settings_tFc;

void cachecef_settings_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_settings_tFc.cached) return;
	cef_settings_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_settings_tFc.size = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "size", I_J);
	cef_settings_tFc.single_process = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "single_process", "I");
	cef_settings_tFc.browser_subprocess_path = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "browser_subprocess_path", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_settings_tFc.multi_threaded_message_loop = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "multi_threaded_message_loop", "I");
	cef_settings_tFc.command_line_args_disabled = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "command_line_args_disabled", "I");
	cef_settings_tFc.cache_path = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "cache_path", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_settings_tFc.user_agent = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "user_agent", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_settings_tFc.product_version = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "product_version", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_settings_tFc.locale = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "locale", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_settings_tFc.log_file = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "log_file", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_settings_tFc.log_severity = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "log_severity", "I");
	cef_settings_tFc.release_dcheck_enabled = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "release_dcheck_enabled", "I");
	cef_settings_tFc.javascript_flags = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "javascript_flags", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_settings_tFc.resources_dir_path = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "resources_dir_path", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_settings_tFc.locales_dir_path = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "locales_dir_path", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_settings_tFc.pack_loading_disabled = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "pack_loading_disabled", "I");
	cef_settings_tFc.remote_debugging_port = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "remote_debugging_port", "I");
	cef_settings_tFc.uncaught_exception_stack_size = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "uncaught_exception_stack_size", "I");
	cef_settings_tFc.context_safety_implementation = (*env)->GetFieldID(env, cef_settings_tFc.clazz, "context_safety_implementation", "I");
	cef_settings_tFc.cached = 1;
}

cef_settings_t *getcef_settings_tFields(JNIEnv *env, jobject lpObject, cef_settings_t *lpStruct)
{
	if (!cef_settings_tFc.cached) cachecef_settings_tFields(env, lpObject);
	lpStruct->size = (*env)->GetIntLongField(env, lpObject, cef_settings_tFc.size);
	lpStruct->single_process = (*env)->GetIntField(env, lpObject, cef_settings_tFc.single_process);
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.browser_subprocess_path);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->browser_subprocess_path);
	}
	lpStruct->multi_threaded_message_loop = (*env)->GetIntField(env, lpObject, cef_settings_tFc.multi_threaded_message_loop);
	lpStruct->command_line_args_disabled = (*env)->GetIntField(env, lpObject, cef_settings_tFc.command_line_args_disabled);
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.cache_path);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->cache_path);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.user_agent);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->user_agent);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.product_version);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->product_version);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.locale);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->locale);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.log_file);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->log_file);
	}
	lpStruct->log_severity = (*env)->GetIntField(env, lpObject, cef_settings_tFc.log_severity);
	lpStruct->release_dcheck_enabled = (*env)->GetIntField(env, lpObject, cef_settings_tFc.release_dcheck_enabled);
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.javascript_flags);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->javascript_flags);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.resources_dir_path);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->resources_dir_path);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.locales_dir_path);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->locales_dir_path);
	}
	lpStruct->pack_loading_disabled = (*env)->GetIntField(env, lpObject, cef_settings_tFc.pack_loading_disabled);
	lpStruct->remote_debugging_port = (*env)->GetIntField(env, lpObject, cef_settings_tFc.remote_debugging_port);
	lpStruct->uncaught_exception_stack_size = (*env)->GetIntField(env, lpObject, cef_settings_tFc.uncaught_exception_stack_size);
	lpStruct->context_safety_implementation = (*env)->GetIntField(env, lpObject, cef_settings_tFc.context_safety_implementation);
	return lpStruct;
}

void setcef_settings_tFields(JNIEnv *env, jobject lpObject, cef_settings_t *lpStruct)
{
	if (!cef_settings_tFc.cached) cachecef_settings_tFields(env, lpObject);
	(*env)->SetIntLongField(env, lpObject, cef_settings_tFc.size, (jintLong)lpStruct->size);
	(*env)->SetIntField(env, lpObject, cef_settings_tFc.single_process, (jint)lpStruct->single_process);
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.browser_subprocess_path);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->browser_subprocess_path);
	}
	(*env)->SetIntField(env, lpObject, cef_settings_tFc.multi_threaded_message_loop, (jint)lpStruct->multi_threaded_message_loop);
	(*env)->SetIntField(env, lpObject, cef_settings_tFc.command_line_args_disabled, (jint)lpStruct->command_line_args_disabled);
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.cache_path);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->cache_path);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.user_agent);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->user_agent);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.product_version);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->product_version);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.locale);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->locale);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.log_file);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->log_file);
	}
	(*env)->SetIntField(env, lpObject, cef_settings_tFc.log_severity, (jint)lpStruct->log_severity);
	(*env)->SetIntField(env, lpObject, cef_settings_tFc.release_dcheck_enabled, (jint)lpStruct->release_dcheck_enabled);
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.javascript_flags);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->javascript_flags);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.resources_dir_path);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->resources_dir_path);
	}
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_settings_tFc.locales_dir_path);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->locales_dir_path);
	}
	(*env)->SetIntField(env, lpObject, cef_settings_tFc.pack_loading_disabled, (jint)lpStruct->pack_loading_disabled);
	(*env)->SetIntField(env, lpObject, cef_settings_tFc.remote_debugging_port, (jint)lpStruct->remote_debugging_port);
	(*env)->SetIntField(env, lpObject, cef_settings_tFc.uncaught_exception_stack_size, (jint)lpStruct->uncaught_exception_stack_size);
	(*env)->SetIntField(env, lpObject, cef_settings_tFc.context_safety_implementation, (jint)lpStruct->context_safety_implementation);
}
#endif

#ifndef NO_cef_string_t
typedef struct cef_string_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID str, length, dtor;
} cef_string_t_FID_CACHE;

cef_string_t_FID_CACHE cef_string_tFc;

void cachecef_string_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_string_tFc.cached) return;
	cef_string_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_string_tFc.str = (*env)->GetFieldID(env, cef_string_tFc.clazz, "str", I_J);
	cef_string_tFc.length = (*env)->GetFieldID(env, cef_string_tFc.clazz, "length", I_J);
	cef_string_tFc.dtor = (*env)->GetFieldID(env, cef_string_tFc.clazz, "dtor", I_J);
	cef_string_tFc.cached = 1;
}

cef_string_t *getcef_string_tFields(JNIEnv *env, jobject lpObject, cef_string_t *lpStruct)
{
	if (!cef_string_tFc.cached) cachecef_string_tFields(env, lpObject);
	lpStruct->str = (void *)(*env)->GetIntLongField(env, lpObject, cef_string_tFc.str);
	lpStruct->length = (*env)->GetIntLongField(env, lpObject, cef_string_tFc.length);
	lpStruct->dtor = (void (__cdecl *)(void *))(*env)->GetIntLongField(env, lpObject, cef_string_tFc.dtor);
	return lpStruct;
}

void setcef_string_tFields(JNIEnv *env, jobject lpObject, cef_string_t *lpStruct)
{
	if (!cef_string_tFc.cached) cachecef_string_tFields(env, lpObject);
	(*env)->SetIntLongField(env, lpObject, cef_string_tFc.str, (jintLong)lpStruct->str);
	(*env)->SetIntLongField(env, lpObject, cef_string_tFc.length, (jintLong)lpStruct->length);
	(*env)->SetIntLongField(env, lpObject, cef_string_tFc.dtor, (jintLong)lpStruct->dtor);
}
#endif

#ifndef NO_cef_window_info_t
typedef struct cef_window_info_t_FID_CACHE {
	int cached;
	jclass clazz;
	jfieldID ex_style, window_name, style, x, y, width, height, parent_window, menu, window_rendering_disabled, transparent_painting, window;
} cef_window_info_t_FID_CACHE;

cef_window_info_t_FID_CACHE cef_window_info_tFc;

void cachecef_window_info_tFields(JNIEnv *env, jobject lpObject)
{
	if (cef_window_info_tFc.cached) return;
	cef_window_info_tFc.clazz = (*env)->GetObjectClass(env, lpObject);
	cef_window_info_tFc.ex_style = (*env)->GetFieldID(env, cef_window_info_tFc.clazz, "ex_style", "I");
	cef_window_info_tFc.window_name = (*env)->GetFieldID(env, cef_window_info_tFc.clazz, "window_name", "Lorg/eclipse/swt/internal/cef3/cef_string_t;");
	cef_window_info_tFc.style = (*env)->GetFieldID(env, cef_window_info_tFc.clazz, "style", "I");
	cef_window_info_tFc.x = (*env)->GetFieldID(env, cef_window_info_tFc.clazz, "x", "I");
	cef_window_info_tFc.y = (*env)->GetFieldID(env, cef_window_info_tFc.clazz, "y", "I");
	cef_window_info_tFc.width = (*env)->GetFieldID(env, cef_window_info_tFc.clazz, "width", "I");
	cef_window_info_tFc.height = (*env)->GetFieldID(env, cef_window_info_tFc.clazz, "height", "I");
	cef_window_info_tFc.parent_window = (*env)->GetFieldID(env, cef_window_info_tFc.clazz, "parent_window", I_J);
	cef_window_info_tFc.menu = (*env)->GetFieldID(env, cef_window_info_tFc.clazz, "menu", I_J);
	cef_window_info_tFc.window_rendering_disabled = (*env)->GetFieldID(env, cef_window_info_tFc.clazz, "window_rendering_disabled", "I");
	cef_window_info_tFc.transparent_painting = (*env)->GetFieldID(env, cef_window_info_tFc.clazz, "transparent_painting", "I");
	cef_window_info_tFc.window = (*env)->GetFieldID(env, cef_window_info_tFc.clazz, "window", I_J);
	cef_window_info_tFc.cached = 1;
}

cef_window_info_t *getcef_window_info_tFields(JNIEnv *env, jobject lpObject, cef_window_info_t *lpStruct)
{
	if (!cef_window_info_tFc.cached) cachecef_window_info_tFields(env, lpObject);
	lpStruct->ex_style = (*env)->GetIntField(env, lpObject, cef_window_info_tFc.ex_style);
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_window_info_tFc.window_name);
	if (lpObject1 != NULL) getcef_string_tFields(env, lpObject1, &lpStruct->window_name);
	}
	lpStruct->style = (*env)->GetIntField(env, lpObject, cef_window_info_tFc.style);
	lpStruct->x = (*env)->GetIntField(env, lpObject, cef_window_info_tFc.x);
	lpStruct->y = (*env)->GetIntField(env, lpObject, cef_window_info_tFc.y);
	lpStruct->width = (*env)->GetIntField(env, lpObject, cef_window_info_tFc.width);
	lpStruct->height = (*env)->GetIntField(env, lpObject, cef_window_info_tFc.height);
	lpStruct->parent_window = (cef_window_handle_t)(*env)->GetIntLongField(env, lpObject, cef_window_info_tFc.parent_window);
	lpStruct->menu = (HMENU)(*env)->GetIntLongField(env, lpObject, cef_window_info_tFc.menu);
	lpStruct->window_rendering_disabled = (*env)->GetIntField(env, lpObject, cef_window_info_tFc.window_rendering_disabled);
	lpStruct->transparent_painting = (*env)->GetIntField(env, lpObject, cef_window_info_tFc.transparent_painting);
	lpStruct->window = (cef_window_handle_t)(*env)->GetIntLongField(env, lpObject, cef_window_info_tFc.window);
	return lpStruct;
}

void setcef_window_info_tFields(JNIEnv *env, jobject lpObject, cef_window_info_t *lpStruct)
{
	if (!cef_window_info_tFc.cached) cachecef_window_info_tFields(env, lpObject);
	(*env)->SetIntField(env, lpObject, cef_window_info_tFc.ex_style, (jint)lpStruct->ex_style);
	{
	jobject lpObject1 = (*env)->GetObjectField(env, lpObject, cef_window_info_tFc.window_name);
	if (lpObject1 != NULL) setcef_string_tFields(env, lpObject1, &lpStruct->window_name);
	}
	(*env)->SetIntField(env, lpObject, cef_window_info_tFc.style, (jint)lpStruct->style);
	(*env)->SetIntField(env, lpObject, cef_window_info_tFc.x, (jint)lpStruct->x);
	(*env)->SetIntField(env, lpObject, cef_window_info_tFc.y, (jint)lpStruct->y);
	(*env)->SetIntField(env, lpObject, cef_window_info_tFc.width, (jint)lpStruct->width);
	(*env)->SetIntField(env, lpObject, cef_window_info_tFc.height, (jint)lpStruct->height);
	(*env)->SetIntLongField(env, lpObject, cef_window_info_tFc.parent_window, (jintLong)lpStruct->parent_window);
	(*env)->SetIntLongField(env, lpObject, cef_window_info_tFc.menu, (jintLong)lpStruct->menu);
	(*env)->SetIntField(env, lpObject, cef_window_info_tFc.window_rendering_disabled, (jint)lpStruct->window_rendering_disabled);
	(*env)->SetIntField(env, lpObject, cef_window_info_tFc.transparent_painting, (jint)lpStruct->transparent_painting);
	(*env)->SetIntLongField(env, lpObject, cef_window_info_tFc.window, (jintLong)lpStruct->window);
}
#endif

