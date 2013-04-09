package org.eclipse.swt.internal.cef3;

public class CEFMenuModel extends CEFBase {
	cef_menu_model_t struct;

	public CEFMenuModel(long /*int*/ address) {
		super(address);
		struct = new cef_menu_model_t();
		CEF3.memmove(struct, address, cef_context_menu_params_t.sizeof);
	}
	
	public int clear() {
		return CEF3.callFuncInt(struct.clear, address);
	}
}
