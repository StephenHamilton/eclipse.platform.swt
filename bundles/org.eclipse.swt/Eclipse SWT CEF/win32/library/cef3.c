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
#include "cef3_stats.h"

#ifndef CEF3_NATIVE
#define CEF3_NATIVE(func) Java_org_eclipse_swt_internal_cef3_CEF3_##func
#endif

#if (!defined(NO_callFuncInt__II) && !defined(JNI64)) || (!defined(NO_callFuncInt__JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT jint JNICALL CEF3_NATIVE(callFuncInt__II)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1)
#else
JNIEXPORT jint JNICALL CEF3_NATIVE(callFuncInt__JJ)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1)
#endif
{
	jint rc = 0;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, callFuncInt__II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, callFuncInt__JJ_FUNC);
#endif
	rc = (jint)((jint (CEF_CALLBACK*)())arg0)(arg1);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, callFuncInt__II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, callFuncInt__JJ_FUNC);
#endif
	return rc;
}
#endif

#if (!defined(NO_callFuncInt__IIII) && !defined(JNI64)) || (!defined(NO_callFuncInt__JJII) && defined(JNI64))
#ifndef JNI64
JNIEXPORT jint JNICALL CEF3_NATIVE(callFuncInt__IIII)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jint arg2, jint arg3)
#else
JNIEXPORT jint JNICALL CEF3_NATIVE(callFuncInt__JJII)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jint arg2, jint arg3)
#endif
{
	jint rc = 0;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, callFuncInt__IIII_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, callFuncInt__JJII_FUNC);
#endif
	rc = (jint)((jint (CEF_CALLBACK*)())arg0)(arg1, arg2, arg3);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, callFuncInt__IIII_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, callFuncInt__JJII_FUNC);
#endif
	return rc;
}
#endif

#if (!defined(NO_callFuncInt__IIIJ) && !defined(JNI64)) || (!defined(NO_callFuncInt__JJIJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT jint JNICALL CEF3_NATIVE(callFuncInt__IIIJ)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jint arg2, jlong arg3)
#else
JNIEXPORT jint JNICALL CEF3_NATIVE(callFuncInt__JJIJ)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jint arg2, jlong arg3)
#endif
{
	jint rc = 0;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, callFuncInt__IIIJ_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, callFuncInt__JJIJ_FUNC);
#endif
	rc = (jint)((jint (CEF_CALLBACK*)())arg0)(arg1, arg2, arg3);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, callFuncInt__IIIJ_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, callFuncInt__JJIJ_FUNC);
#endif
	return rc;
}
#endif

#if (!defined(NO_callFuncInt__IIILorg_eclipse_swt_internal_cef3_cef_1string_1t_2) && !defined(JNI64)) || (!defined(NO_callFuncInt__JJILorg_eclipse_swt_internal_cef3_cef_1string_1t_2) && defined(JNI64))
#ifndef JNI64
JNIEXPORT jint JNICALL CEF3_NATIVE(callFuncInt__IIILorg_eclipse_swt_internal_cef3_cef_1string_1t_2)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jint arg2, jobject arg3)
#else
JNIEXPORT jint JNICALL CEF3_NATIVE(callFuncInt__JJILorg_eclipse_swt_internal_cef3_cef_1string_1t_2)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jint arg2, jobject arg3)
#endif
{
	cef_string_t _arg3, *lparg3=NULL;
	jint rc = 0;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, callFuncInt__IIILorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, callFuncInt__JJILorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC);
#endif
	if (arg3) if ((lparg3 = getcef_string_tFields(env, arg3, &_arg3)) == NULL) goto fail;
	rc = (jint)((jint (CEF_CALLBACK*)())arg0)(arg1, arg2, lparg3);
fail:
	if (arg3 && lparg3) setcef_string_tFields(env, arg3, lparg3);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, callFuncInt__IIILorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, callFuncInt__JJILorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC);
#endif
	return rc;
}
#endif

#ifndef NO_callFuncLong
JNIEXPORT jlong JNICALL CEF3_NATIVE(callFuncLong)
	(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1)
{
	jlong rc = 0;
	CEF3_NATIVE_ENTER(env, that, callFuncLong_FUNC);
	rc = (jlong)((jlong (CEF_CALLBACK*)())arg0)(arg1);
	CEF3_NATIVE_EXIT(env, that, callFuncLong_FUNC);
	return rc;
}
#endif

#if (!defined(NO_callFuncPtr__II) && !defined(JNI64)) || (!defined(NO_callFuncPtr__JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT jintLong JNICALL CEF3_NATIVE(callFuncPtr__II)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1)
#else
JNIEXPORT jintLong JNICALL CEF3_NATIVE(callFuncPtr__JJ)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1)
#endif
{
	jintLong rc = 0;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, callFuncPtr__II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, callFuncPtr__JJ_FUNC);
#endif
	rc = (jintLong)((jintLong (CEF_CALLBACK*)())arg0)(arg1);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, callFuncPtr__II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, callFuncPtr__JJ_FUNC);
#endif
	return rc;
}
#endif

#if (!defined(NO_callFuncPtr__III) && !defined(JNI64)) || (!defined(NO_callFuncPtr__JJI) && defined(JNI64))
#ifndef JNI64
JNIEXPORT jintLong JNICALL CEF3_NATIVE(callFuncPtr__III)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jint arg2)
#else
JNIEXPORT jintLong JNICALL CEF3_NATIVE(callFuncPtr__JJI)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jint arg2)
#endif
{
	jintLong rc = 0;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, callFuncPtr__III_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, callFuncPtr__JJI_FUNC);
#endif
	rc = (jintLong)((jintLong (CEF_CALLBACK*)())arg0)(arg1, arg2);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, callFuncPtr__III_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, callFuncPtr__JJI_FUNC);
#endif
	return rc;
}
#endif

#if (!defined(NO_callFuncVoid__II) && !defined(JNI64)) || (!defined(NO_callFuncVoid__JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__II)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__JJ)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1)
#endif
{
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__JJ_FUNC);
#endif
	((void (CEF_CALLBACK*)())arg0)(arg1);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__JJ_FUNC);
#endif
}
#endif

#if (!defined(NO_callFuncVoid__IIIII) && !defined(JNI64)) || (!defined(NO_callFuncVoid__JJIII) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__IIIII)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jint arg2, jint arg3, jint arg4)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__JJIII)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jint arg2, jint arg3, jint arg4)
#endif
{
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__IIIII_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__JJIII_FUNC);
#endif
	((void (CEF_CALLBACK*)())arg0)(arg1, arg2, arg3, arg4);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__IIIII_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__JJIII_FUNC);
#endif
}
#endif

#if (!defined(NO_callFuncVoid__IIJJI) && !defined(JNI64)) || (!defined(NO_callFuncVoid__JJJJI) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__IIJJI)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jlong arg2, jlong arg3, jint arg4)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__JJJJI)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jlong arg2, jlong arg3, jint arg4)
#endif
{
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__IIJJI_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__JJJJI_FUNC);
#endif
	((void (CEF_CALLBACK*)())arg0)(arg1, arg2, arg3, arg4);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__IIJJI_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__JJJJI_FUNC);
#endif
}
#endif

#if (!defined(NO_callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2) && !defined(JNI64)) || (!defined(NO_callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jobject arg2)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jobject arg2)
#endif
{
	cef_string_t _arg2, *lparg2=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC);
#endif
	if (arg2) if ((lparg2 = getcef_string_tFields(env, arg2, &_arg2)) == NULL) goto fail;
	((void (CEF_CALLBACK*)())arg0)(arg1, lparg2);
fail:
	if (arg2 && lparg2) setcef_string_tFields(env, arg2, lparg2);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC);
#endif
}
#endif

#if (!defined(NO_callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2I) && !defined(JNI64)) || (!defined(NO_callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2I) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2I)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jobject arg2, jint arg3)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2I)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jobject arg2, jint arg3)
#endif
{
	cef_string_t _arg2, *lparg2=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2I_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2I_FUNC);
#endif
	if (arg2) if ((lparg2 = getcef_string_tFields(env, arg2, &_arg2)) == NULL) goto fail;
	((void (CEF_CALLBACK*)())arg0)(arg1, lparg2, arg3);
fail:
	if (arg2 && lparg2) setcef_string_tFields(env, arg2, lparg2);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2I_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2I_FUNC);
#endif
}
#endif

#if (!defined(NO_callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2) && !defined(JNI64)) || (!defined(NO_callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jobject arg2, jobject arg3)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jobject arg2, jobject arg3)
#endif
{
	cef_string_t _arg2, *lparg2=NULL;
	cef_string_t _arg3, *lparg3=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC);
#endif
	if (arg2) if ((lparg2 = getcef_string_tFields(env, arg2, &_arg2)) == NULL) goto fail;
	if (arg3) if ((lparg3 = getcef_string_tFields(env, arg3, &_arg3)) == NULL) goto fail;
	((void (CEF_CALLBACK*)())arg0)(arg1, lparg2, lparg3);
fail:
	if (arg3 && lparg3) setcef_string_tFields(env, arg3, lparg3);
	if (arg2 && lparg2) setcef_string_tFields(env, arg2, lparg2);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC);
#endif
}
#endif

#if (!defined(NO_callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2I) && !defined(JNI64)) || (!defined(NO_callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2I) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2I)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jobject arg2, jobject arg3, jint arg4)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2I)(JNIEnv *env, jclass that, jintLong arg0, jintLong arg1, jobject arg2, jobject arg3, jint arg4)
#endif
{
	cef_string_t _arg2, *lparg2=NULL;
	cef_string_t _arg3, *lparg3=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2I_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2I_FUNC);
#endif
	if (arg2) if ((lparg2 = getcef_string_tFields(env, arg2, &_arg2)) == NULL) goto fail;
	if (arg3) if ((lparg3 = getcef_string_tFields(env, arg3, &_arg3)) == NULL) goto fail;
	((void (CEF_CALLBACK*)())arg0)(arg1, lparg2, lparg3, arg4);
fail:
	if (arg3 && lparg3) setcef_string_tFields(env, arg3, lparg3);
	if (arg2 && lparg2) setcef_string_tFields(env, arg2, lparg2);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2I_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2I_FUNC);
#endif
}
#endif

#ifndef NO_cef_1base_1t_1sizeof
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1base_1t_1sizeof)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1base_1t_1sizeof_FUNC);
	rc = (jint)cef_base_t_sizeof();
	CEF3_NATIVE_EXIT(env, that, cef_1base_1t_1sizeof_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1before_1download_1callback_1t_1sizeof
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1before_1download_1callback_1t_1sizeof)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1before_1download_1callback_1t_1sizeof_FUNC);
	rc = (jint)cef_before_download_callback_t_sizeof();
	CEF3_NATIVE_EXIT(env, that, cef_1before_1download_1callback_1t_1sizeof_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1browser_1host_1create_1browser
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1browser_1host_1create_1browser)
	(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jobject arg2, jobject arg3)
{
	cef_window_info_t _arg0, *lparg0=NULL;
	cef_string_t _arg2, *lparg2=NULL;
	cef_browser_settings_t _arg3, *lparg3=NULL;
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1browser_1host_1create_1browser_FUNC);
	if (arg0) if ((lparg0 = getcef_window_info_tFields(env, arg0, &_arg0)) == NULL) goto fail;
	if (arg2) if ((lparg2 = getcef_string_tFields(env, arg2, &_arg2)) == NULL) goto fail;
	if (arg3) if ((lparg3 = getcef_browser_settings_tFields(env, arg3, &_arg3)) == NULL) goto fail;
	rc = (jint)cef_browser_host_create_browser(lparg0, (struct _cef_client_t*)arg1, (const cef_string_t*)lparg2, lparg3);
fail:
	if (arg3 && lparg3) setcef_browser_settings_tFields(env, arg3, lparg3);
	if (arg2 && lparg2) setcef_string_tFields(env, arg2, lparg2);
	if (arg0 && lparg0) setcef_window_info_tFields(env, arg0, lparg0);
	CEF3_NATIVE_EXIT(env, that, cef_1browser_1host_1create_1browser_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1browser_1host_1t_1sizeof
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1browser_1host_1t_1sizeof)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1browser_1host_1t_1sizeof_FUNC);
	rc = (jint)cef_browser_host_t_sizeof();
	CEF3_NATIVE_EXIT(env, that, cef_1browser_1host_1t_1sizeof_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1browser_1settings_1t_1sizeof
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1browser_1settings_1t_1sizeof)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1browser_1settings_1t_1sizeof_FUNC);
	rc = (jint)cef_browser_settings_t_sizeof();
	CEF3_NATIVE_EXIT(env, that, cef_1browser_1settings_1t_1sizeof_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1browser_1t_1sizeof
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1browser_1t_1sizeof)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1browser_1t_1sizeof_FUNC);
	rc = (jint)cef_browser_t_sizeof();
	CEF3_NATIVE_EXIT(env, that, cef_1browser_1t_1sizeof_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1build_1revision
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1build_1revision)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1build_1revision_FUNC);
	rc = (jint)cef_build_revision();
	CEF3_NATIVE_EXIT(env, that, cef_1build_1revision_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1context_1menu_1params_1t_1sizeof
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1context_1menu_1params_1t_1sizeof)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1context_1menu_1params_1t_1sizeof_FUNC);
	rc = (jint)cef_context_menu_params_t_sizeof();
	CEF3_NATIVE_EXIT(env, that, cef_1context_1menu_1params_1t_1sizeof_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1download_1item_1callback_1t_1sizeof
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1download_1item_1callback_1t_1sizeof)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1download_1item_1callback_1t_1sizeof_FUNC);
	rc = (jint)cef_download_item_callback_t_sizeof();
	CEF3_NATIVE_EXIT(env, that, cef_1download_1item_1callback_1t_1sizeof_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1download_1item_1t_1sizeof
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1download_1item_1t_1sizeof)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1download_1item_1t_1sizeof_FUNC);
	rc = (jint)cef_download_item_t_sizeof();
	CEF3_NATIVE_EXIT(env, that, cef_1download_1item_1t_1sizeof_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1execute_1process
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1execute_1process)
	(JNIEnv *env, jclass that, jobject arg0, jintLong arg1)
{
	cef_main_args_t _arg0, *lparg0=NULL;
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1execute_1process_FUNC);
	if (arg0) if ((lparg0 = getcef_main_args_tFields(env, arg0, &_arg0)) == NULL) goto fail;
	rc = (jint)cef_execute_process(lparg0, (struct _cef_app_t*)arg1);
fail:
	if (arg0 && lparg0) setcef_main_args_tFields(env, arg0, lparg0);
	CEF3_NATIVE_EXIT(env, that, cef_1execute_1process_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1frame_1t_1sizeof
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1frame_1t_1sizeof)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1frame_1t_1sizeof_FUNC);
	rc = (jint)cef_frame_t_sizeof();
	CEF3_NATIVE_EXIT(env, that, cef_1frame_1t_1sizeof_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1initialize
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1initialize)
	(JNIEnv *env, jclass that, jobject arg0, jobject arg1, jintLong arg2)
{
	cef_main_args_t _arg0, *lparg0=NULL;
	cef_settings_t _arg1, *lparg1=NULL;
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1initialize_FUNC);
	if (arg0) if ((lparg0 = getcef_main_args_tFields(env, arg0, &_arg0)) == NULL) goto fail;
	if (arg1) if ((lparg1 = getcef_settings_tFields(env, arg1, &_arg1)) == NULL) goto fail;
	rc = (jint)cef_initialize(lparg0, lparg1, (struct _cef_app_t*)arg2);
fail:
	if (arg1 && lparg1) setcef_settings_tFields(env, arg1, lparg1);
	if (arg0 && lparg0) setcef_main_args_tFields(env, arg0, lparg0);
	CEF3_NATIVE_EXIT(env, that, cef_1initialize_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1list_1value_1t_1sizeof
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1list_1value_1t_1sizeof)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1list_1value_1t_1sizeof_FUNC);
	rc = (jint)cef_list_value_t_sizeof();
	CEF3_NATIVE_EXIT(env, that, cef_1list_1value_1t_1sizeof_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1process_1message_1create
JNIEXPORT jintLong JNICALL CEF3_NATIVE(cef_1process_1message_1create)
	(JNIEnv *env, jclass that, jobject arg0)
{
	cef_string_t _arg0, *lparg0=NULL;
	jintLong rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1process_1message_1create_FUNC);
	if (arg0) if ((lparg0 = getcef_string_tFields(env, arg0, &_arg0)) == NULL) goto fail;
	rc = (jintLong)cef_process_message_create((cef_string_t*)lparg0);
fail:
	if (arg0 && lparg0) setcef_string_tFields(env, arg0, lparg0);
	CEF3_NATIVE_EXIT(env, that, cef_1process_1message_1create_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1process_1message_1t_1sizeof
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1process_1message_1t_1sizeof)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1process_1message_1t_1sizeof_FUNC);
	rc = (jint)cef_process_message_t_sizeof();
	CEF3_NATIVE_EXIT(env, that, cef_1process_1message_1t_1sizeof_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1settings_1t_1sizeof
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1settings_1t_1sizeof)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1settings_1t_1sizeof_FUNC);
	rc = (jint)cef_settings_t_sizeof();
	CEF3_NATIVE_EXIT(env, that, cef_1settings_1t_1sizeof_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1string_1set
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1string_1set)
	(JNIEnv *env, jclass that, jcharArray arg0, jintLong arg1, jobject arg2, jint arg3)
{
	jchar *lparg0=NULL;
	cef_string_t _arg2, *lparg2=NULL;
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1string_1set_FUNC);
	if (arg0) if ((lparg0 = (*env)->GetCharArrayElements(env, arg0, NULL)) == NULL) goto fail;
	if (arg2) if ((lparg2 = getcef_string_tFields(env, arg2, &_arg2)) == NULL) goto fail;
	rc = (jint)cef_string_set((void*)lparg0, arg1, (cef_string_t*)lparg2, arg3);
fail:
	if (arg2 && lparg2) setcef_string_tFields(env, arg2, lparg2);
	if (arg0 && lparg0) (*env)->ReleaseCharArrayElements(env, arg0, lparg0, 0);
	CEF3_NATIVE_EXIT(env, that, cef_1string_1set_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1string_1t_1sizeof
JNIEXPORT jint JNICALL CEF3_NATIVE(cef_1string_1t_1sizeof)
	(JNIEnv *env, jclass that)
{
	jint rc = 0;
	CEF3_NATIVE_ENTER(env, that, cef_1string_1t_1sizeof_FUNC);
	rc = (jint)cef_string_t_sizeof();
	CEF3_NATIVE_EXIT(env, that, cef_1string_1t_1sizeof_FUNC);
	return rc;
}
#endif

#ifndef NO_cef_1string_1userfree_1free
JNIEXPORT void JNICALL CEF3_NATIVE(cef_1string_1userfree_1free)
	(JNIEnv *env, jclass that, jintLong arg0)
{
	CEF3_NATIVE_ENTER(env, that, cef_1string_1userfree_1free_FUNC);
	cef_string_userfree_free((cef_string_userfree_t)arg0);
	CEF3_NATIVE_EXIT(env, that, cef_1string_1userfree_1free_FUNC);
}
#endif

#if (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1base_1t_2II) && !defined(JNI64)) || (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1base_1t_2JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1base_1t_2II)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1base_1t_2JJ)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#endif
{
	cef_base_t _arg0, *lparg0=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1base_1t_2II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1base_1t_2JJ_FUNC);
#endif
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setcef_base_tFields(env, arg0, lparg0);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1base_1t_2II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1base_1t_2JJ_FUNC);
#endif
}
#endif

#if (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1before_1download_1callback_1t_2II) && !defined(JNI64)) || (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1before_1download_1callback_1t_2JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1before_1download_1callback_1t_2II)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1before_1download_1callback_1t_2JJ)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#endif
{
	cef_before_download_callback_t _arg0, *lparg0=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1before_1download_1callback_1t_2II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1before_1download_1callback_1t_2JJ_FUNC);
#endif
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setcef_before_download_callback_tFields(env, arg0, lparg0);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1before_1download_1callback_1t_2II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1before_1download_1callback_1t_2JJ_FUNC);
#endif
}
#endif

#if (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1host_1t_2II) && !defined(JNI64)) || (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1host_1t_2JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1host_1t_2II)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1host_1t_2JJ)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#endif
{
	cef_browser_host_t _arg0, *lparg0=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1host_1t_2II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1host_1t_2JJ_FUNC);
#endif
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setcef_browser_host_tFields(env, arg0, lparg0);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1host_1t_2II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1host_1t_2JJ_FUNC);
#endif
}
#endif

#if (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1t_2II) && !defined(JNI64)) || (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1t_2JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1t_2II)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1t_2JJ)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#endif
{
	cef_browser_t _arg0, *lparg0=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1t_2II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1t_2JJ_FUNC);
#endif
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setcef_browser_tFields(env, arg0, lparg0);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1t_2II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1t_2JJ_FUNC);
#endif
}
#endif

#if (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1context_1menu_1params_1t_2II) && !defined(JNI64)) || (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1context_1menu_1params_1t_2JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1context_1menu_1params_1t_2II)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1context_1menu_1params_1t_2JJ)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#endif
{
	cef_context_menu_params_t _arg0, *lparg0=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1context_1menu_1params_1t_2II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1context_1menu_1params_1t_2JJ_FUNC);
#endif
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setcef_context_menu_params_tFields(env, arg0, lparg0);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1context_1menu_1params_1t_2II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1context_1menu_1params_1t_2JJ_FUNC);
#endif
}
#endif

#if (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1callback_1t_2II) && !defined(JNI64)) || (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1callback_1t_2JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1callback_1t_2II)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1callback_1t_2JJ)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#endif
{
	cef_download_item_callback_t _arg0, *lparg0=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1callback_1t_2II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1callback_1t_2JJ_FUNC);
#endif
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setcef_download_item_callback_tFields(env, arg0, lparg0);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1callback_1t_2II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1callback_1t_2JJ_FUNC);
#endif
}
#endif

#if (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1t_2II) && !defined(JNI64)) || (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1t_2JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1t_2II)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1t_2JJ)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#endif
{
	cef_download_item_t _arg0, *lparg0=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1t_2II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1t_2JJ_FUNC);
#endif
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setcef_download_item_tFields(env, arg0, lparg0);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1t_2II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1t_2JJ_FUNC);
#endif
}
#endif

#if (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1frame_1t_2II) && !defined(JNI64)) || (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1frame_1t_2JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1frame_1t_2II)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1frame_1t_2JJ)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#endif
{
	cef_frame_t _arg0, *lparg0=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1frame_1t_2II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1frame_1t_2JJ_FUNC);
#endif
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setcef_frame_tFields(env, arg0, lparg0);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1frame_1t_2II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1frame_1t_2JJ_FUNC);
#endif
}
#endif

#if (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1list_1value_1t_2II) && !defined(JNI64)) || (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1list_1value_1t_2JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1list_1value_1t_2II)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1list_1value_1t_2JJ)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#endif
{
	cef_list_value_t _arg0, *lparg0=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1list_1value_1t_2II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1list_1value_1t_2JJ_FUNC);
#endif
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setcef_list_value_tFields(env, arg0, lparg0);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1list_1value_1t_2II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1list_1value_1t_2JJ_FUNC);
#endif
}
#endif

#if (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1menu_1model_1t_2II) && !defined(JNI64)) || (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1menu_1model_1t_2JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1menu_1model_1t_2II)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1menu_1model_1t_2JJ)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#endif
{
	cef_menu_model_t _arg0, *lparg0=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1menu_1model_1t_2II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1menu_1model_1t_2JJ_FUNC);
#endif
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setcef_menu_model_tFields(env, arg0, lparg0);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1menu_1model_1t_2II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1menu_1model_1t_2JJ_FUNC);
#endif
}
#endif

#if (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1process_1message_1t_2II) && !defined(JNI64)) || (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1process_1message_1t_2JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1process_1message_1t_2II)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1process_1message_1t_2JJ)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#endif
{
	cef_process_message_t _arg0, *lparg0=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1process_1message_1t_2II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1process_1message_1t_2JJ_FUNC);
#endif
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setcef_process_message_tFields(env, arg0, lparg0);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1process_1message_1t_2II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1process_1message_1t_2JJ_FUNC);
#endif
}
#endif

#if (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2II) && !defined(JNI64)) || (!defined(NO_memmove__Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2JJ) && defined(JNI64))
#ifndef JNI64
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2II)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#else
JNIEXPORT void JNICALL CEF3_NATIVE(memmove__Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2JJ)(JNIEnv *env, jclass that, jobject arg0, jintLong arg1, jintLong arg2)
#endif
{
	cef_string_t _arg0, *lparg0=NULL;
#ifndef JNI64
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2II_FUNC);
#else
	CEF3_NATIVE_ENTER(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2JJ_FUNC);
#endif
	if (arg0) if ((lparg0 = &_arg0) == NULL) goto fail;
	memmove((void *)lparg0, (const void *)arg1, (size_t)arg2);
fail:
	if (arg0 && lparg0) setcef_string_tFields(env, arg0, lparg0);
#ifndef JNI64
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2II_FUNC);
#else
	CEF3_NATIVE_EXIT(env, that, memmove__Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2JJ_FUNC);
#endif
}
#endif

