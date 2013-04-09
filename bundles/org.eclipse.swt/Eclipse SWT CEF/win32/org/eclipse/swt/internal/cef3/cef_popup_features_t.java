package org.eclipse.swt.internal.cef3;

public class cef_popup_features_t {
	  public int x;
	  public int xSet;
	  public int y;
	  public int ySet;
	  public int width;
	  public int widthSet;
	  public int height;
	  public int heightSet;

	  public int menuBarVisible;
	  public int statusBarVisible;
	  public int toolBarVisible;
	  public int locationBarVisible;
	  public int scrollbarsVisible;
	  public int resizable;

	  public int fullscreen;
	  public int dialog;
	  /** @field cast=(cef_string_list_t) */
	  public long /*int*/ additionalFeatures;
	  public static final int sizeof = CEF3.cef_popup_features_t_sizeof();

}
