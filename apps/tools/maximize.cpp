#include <class/io.h>
#include <windows.h>

void maximize(HWND wnd){
	LONG lStyle = GetWindowLong(wnd, GWL_STYLE);
	lStyle &= ~WS_BORDER;
	lStyle &= ~WS_DLGFRAME;
	lStyle &= ~WS_THICKFRAME;
	SetWindowLong(wnd, GWL_STYLE, lStyle);
	ShowWindow(wnd,SW_SHOWMAXIMIZED);
}

main(){
	HWND wnd;
	wnd = GetConsoleWindow();
	
	maximize(wnd);
}
