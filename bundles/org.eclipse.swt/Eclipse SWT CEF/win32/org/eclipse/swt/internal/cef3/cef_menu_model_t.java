package org.eclipse.swt.internal.cef3;

public class cef_menu_model_t extends cef_base_t {
/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self))" */
public long /*int*/ clear;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self))" */
public long /*int*/ get_count;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self))" */
public long /*int*/ add_separator;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, const cef_string_t* label))" */
public long /*int*/ add_item;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, const cef_string_t* label))" */
public long /*int*/ add_check_item;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, const cef_string_t* label, int group_id))" */
public long /*int*/ add_radio_item;

/** @field cast="(struct _cef_menu_model_t* (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int command_id, const cef_string_t* label))" */
public long /*int*/ add_sub_menu;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))" */
public long /*int*/ insert_separator_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int command_id, const cef_string_t* label))" */
public long /*int*/ insert_item_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int command_id, const cef_string_t* label))" */
public long /*int*/ insert_check_item_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int command_id, const cef_string_t* label, int group_id))" */
public long /*int*/ insert_radio_item_at;

/** @field cast="(struct _cef_menu_model_t* (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int index, int command_id, const cef_string_t* label))" */
public long /*int*/ insert_sub_menu_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))" */
public long /*int*/ remove;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))" */
public long /*int*/ remove_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))" */
public long /*int*/ get_index_of;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))" */
public long /*int*/ get_command_id_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int command_id))" */
public long /*int*/ set_command_id_at;

/** @field cast="(cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int command_id))" */
public long /*int*/ get_label;

/** @field cast="(cef_string_userfree_t (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int index))" */
public long /*int*/ get_label_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, const cef_string_t* label))" */
public long /*int*/ set_label;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, const cef_string_t* label))" */
public long /*int*/ set_label_at;

/** @field cast="(enum cef_menu_item_type_t (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int command_id))" */
public long /*int*/ get_type;

/** @field cast="(enum cef_menu_item_type_t (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int index))" */
public long /*int*/ get_type_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))" */
public long /*int*/ get_group_id;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))" */
public long /*int*/ get_group_id_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, int group_id))" */
public long /*int*/ set_group_id;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int group_id))" */
public long /*int*/ set_group_id_at;

/** @field cast="(struct _cef_menu_model_t* (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int command_id))" */
public long /*int*/ get_sub_menu;

/** @field cast="(struct _cef_menu_model_t* (CEF_CALLBACK *)( struct _cef_menu_model_t* self, int index))" */
public long /*int*/ get_sub_menu_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))" */
public long /*int*/ is_visible;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))" */
public long /*int*/ is_visible_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, int visible))" */
public long /*int*/ set_visible;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int visible))" */
public long /*int*/ set_visible_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))" */
public long /*int*/ is_enabled;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))" */
public long /*int*/ is_enabled_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, int enabled))" */
public long /*int*/ set_enabled;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int enabled))" */
public long /*int*/ set_enabled_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))" */
public long /*int*/ is_checked;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))" */
public long /*int*/ is_checked_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, int checked))" */
public long /*int*/ set_checked;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int checked))" */
public long /*int*/ set_checked_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))" */
public long /*int*/ has_accelerator;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))" */
public long /*int*/ has_accelerator_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, int key_code, int shift_pressed, int ctrl_pressed, int alt_pressed))" */
public long /*int*/ set_accelerator;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int key_code, int shift_pressed, int ctrl_pressed, int alt_pressed))" */
public long /*int*/ set_accelerator_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id))" */
public long /*int*/ remove_accelerator;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index))" */
public long /*int*/ remove_accelerator_at;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int command_id, int* key_code, int* shift_pressed, int* ctrl_pressed, int* alt_pressed))" */
public long /*int*/ get_accelerator;

/** @field cast="(int (CEF_CALLBACK *)(struct _cef_menu_model_t* self, int index, int* key_code, int* shift_pressed, int* ctrl_pressed, int* alt_pressed))" */
public long /*int*/ get_accelerator_at;
}
