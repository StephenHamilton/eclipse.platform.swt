package org.eclipse.swt.internal.cef3;

public class CEFContextMenuParams extends CEFBase {
	cef_context_menu_params_t struct;

	public CEFContextMenuParams(long /*int*/ address) {
		super(address);
		struct = new cef_context_menu_params_t();
		CEF3.memmove(struct, address, cef_context_menu_params_t.sizeof);
	}
	
	public int getXCoord() {
		return CEF3.callFuncInt(struct.get_xcoord, address);
	}
	
	public int getYCoord() {
		return CEF3.callFuncInt(struct.get_ycoord, address);
	}
}
