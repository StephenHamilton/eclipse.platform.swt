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

#ifdef NATIVE_STATS
extern int CEF3_nativeFunctionCount;
extern int CEF3_nativeFunctionCallCount[];
extern char* CEF3_nativeFunctionNames[];
#define CEF3_NATIVE_ENTER(env, that, func) CEF3_nativeFunctionCallCount[func]++;
#define CEF3_NATIVE_EXIT(env, that, func) 
#else
#ifndef CEF3_NATIVE_ENTER
#define CEF3_NATIVE_ENTER(env, that, func) 
#endif
#ifndef CEF3_NATIVE_EXIT
#define CEF3_NATIVE_EXIT(env, that, func) 
#endif
#endif

typedef enum {
#ifndef JNI64
	callFuncInt__II_FUNC,
#else
	callFuncInt__JJ_FUNC,
#endif
#ifndef JNI64
	callFuncInt__IIII_FUNC,
#else
	callFuncInt__JJII_FUNC,
#endif
#ifndef JNI64
	callFuncInt__IIIJ_FUNC,
#else
	callFuncInt__JJIJ_FUNC,
#endif
#ifndef JNI64
	callFuncInt__IIILorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC,
#else
	callFuncInt__JJILorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC,
#endif
	callFuncLong_FUNC,
#ifndef JNI64
	callFuncPtr__II_FUNC,
#else
	callFuncPtr__JJ_FUNC,
#endif
#ifndef JNI64
	callFuncPtr__III_FUNC,
#else
	callFuncPtr__JJI_FUNC,
#endif
#ifndef JNI64
	callFuncVoid__II_FUNC,
#else
	callFuncVoid__JJ_FUNC,
#endif
#ifndef JNI64
	callFuncVoid__IIIII_FUNC,
#else
	callFuncVoid__JJIII_FUNC,
#endif
#ifndef JNI64
	callFuncVoid__IIJJI_FUNC,
#else
	callFuncVoid__JJJJI_FUNC,
#endif
#ifndef JNI64
	callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC,
#else
	callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC,
#endif
#ifndef JNI64
	callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2I_FUNC,
#else
	callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2I_FUNC,
#endif
#ifndef JNI64
	callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC,
#else
	callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2_FUNC,
#endif
#ifndef JNI64
	callFuncVoid__IILorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2I_FUNC,
#else
	callFuncVoid__JJLorg_eclipse_swt_internal_cef3_cef_1string_1t_2Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2I_FUNC,
#endif
	cef_1base_1t_1sizeof_FUNC,
	cef_1before_1download_1callback_1t_1sizeof_FUNC,
	cef_1browser_1host_1create_1browser_FUNC,
	cef_1browser_1host_1t_1sizeof_FUNC,
	cef_1browser_1settings_1t_1sizeof_FUNC,
	cef_1browser_1t_1sizeof_FUNC,
	cef_1build_1revision_FUNC,
	cef_1context_1menu_1params_1t_1sizeof_FUNC,
	cef_1download_1item_1callback_1t_1sizeof_FUNC,
	cef_1download_1item_1t_1sizeof_FUNC,
	cef_1execute_1process_FUNC,
	cef_1frame_1t_1sizeof_FUNC,
	cef_1initialize_FUNC,
	cef_1list_1value_1t_1sizeof_FUNC,
	cef_1process_1message_1create_FUNC,
	cef_1process_1message_1t_1sizeof_FUNC,
	cef_1settings_1t_1sizeof_FUNC,
	cef_1string_1set_FUNC,
	cef_1string_1t_1sizeof_FUNC,
	cef_1string_1userfree_1free_FUNC,
#ifndef JNI64
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1base_1t_2II_FUNC,
#else
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1base_1t_2JJ_FUNC,
#endif
#ifndef JNI64
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1before_1download_1callback_1t_2II_FUNC,
#else
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1before_1download_1callback_1t_2JJ_FUNC,
#endif
#ifndef JNI64
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1host_1t_2II_FUNC,
#else
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1host_1t_2JJ_FUNC,
#endif
#ifndef JNI64
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1t_2II_FUNC,
#else
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1browser_1t_2JJ_FUNC,
#endif
#ifndef JNI64
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1context_1menu_1params_1t_2II_FUNC,
#else
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1context_1menu_1params_1t_2JJ_FUNC,
#endif
#ifndef JNI64
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1callback_1t_2II_FUNC,
#else
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1callback_1t_2JJ_FUNC,
#endif
#ifndef JNI64
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1t_2II_FUNC,
#else
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1download_1item_1t_2JJ_FUNC,
#endif
#ifndef JNI64
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1frame_1t_2II_FUNC,
#else
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1frame_1t_2JJ_FUNC,
#endif
#ifndef JNI64
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1list_1value_1t_2II_FUNC,
#else
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1list_1value_1t_2JJ_FUNC,
#endif
#ifndef JNI64
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1menu_1model_1t_2II_FUNC,
#else
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1menu_1model_1t_2JJ_FUNC,
#endif
#ifndef JNI64
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1process_1message_1t_2II_FUNC,
#else
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1process_1message_1t_2JJ_FUNC,
#endif
#ifndef JNI64
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2II_FUNC,
#else
	memmove__Lorg_eclipse_swt_internal_cef3_cef_1string_1t_2JJ_FUNC,
#endif
} CEF3_FUNCS;
