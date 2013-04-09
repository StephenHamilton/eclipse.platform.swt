package org.eclipse.swt.internal.cef3;

public class cef_context_menu_params_t extends cef_base_t {

	/** @field cast="(int (CEF_CALLBACK *)(struct _cef_context_menu_params_t* self))" */
	public long /*int*/ get_xcoord;

	/** @field cast="(int (CEF_CALLBACK *)(struct _cef_context_menu_params_t* self))" */
	public long /*int*/ get_ycoord;

	/** @field cast="(enum cef_context_menu_type_flags_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))" */
	public long /*int*/ get_type_flags;

	/** @field cast="(cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))" */
	public long /*int*/ get_link_url;

	/** @field cast="(cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))" */
	public long /*int*/ get_unfiltered_link_url;

	/** @field cast="(cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))" */
	public long /*int*/ get_source_url;

	/** @field cast="(int (CEF_CALLBACK *)(struct _cef_context_menu_params_t* self))" */
	public long /*int*/ is_image_blocked;

	/** @field cast="(cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))" */
	public long /*int*/ get_page_url;

	/** @field cast="(cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))" */
	public long /*int*/ get_frame_url;

	/** @field cast="(cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))" */
	public long /*int*/ get_frame_charset;

	/** @field cast="(enum cef_context_menu_media_type_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))" */
	public long /*int*/ get_media_type;

	/** @field cast="(enum cef_context_menu_media_state_flags_t ( CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))" */
	public long /*int*/ get_media_state_flags;

	/** @field cast="(cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_context_menu_params_t* self))" */
	public long /*int*/ get_selection_text;

	/** @field cast="(int (CEF_CALLBACK *)(struct _cef_context_menu_params_t* self))" */
	public long /*int*/ is_editable;

	/** @field cast="(int (CEF_CALLBACK *)(struct _cef_context_menu_params_t* self))" */
	public long /*int*/ is_speech_input_enabled;

	/** @field cast="(enum cef_context_menu_edit_state_flags_t (CEF_CALLBACK *)(struct _cef_context_menu_params_t* self))" */
	public long /*int*/ get_edit_state_flags;
	
	public static final int sizeof = CEF3.cef_context_menu_params_t_sizeof();

}
