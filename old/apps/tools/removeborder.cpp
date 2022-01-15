#include <class/io.h>
#include <windows.h>

void removeBorders(){
	HWND wnd;
	wnd = GetConsoleWindow();
	LONG lStyle = GetWindowLong(wnd, GWL_STYLE);
	lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
	SetWindowLong(wnd, GWL_STYLE, lStyle);
}

main(){
	removeBorders();
}
