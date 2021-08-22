#include <class/io.h>
#include <windows.h>

main(){
	HWND wnd;
	wnd = GetConsoleWindow();
	LONG lStyle = GetWindowLong(wnd, GWL_STYLE);
	//lStyle &= ~(SW_MAXIMIZE);//~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
	lStyle &= ~WS_BORDER;
	lStyle &= ~WS_DLGFRAME;
	lStyle &= ~WS_THICKFRAME;
	SetWindowLong(wnd, GWL_STYLE, lStyle);
	ShowWindow(wnd,SW_SHOWMAXIMIZED);
}
