#include "../class/io.h"
#include <windows.h>

void topmostConsole(){
	HWND wnd;
	wnd = FindWindowA("ConsoleWindowClass", NULL);
	SetWindowPos(wnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

main(){
	/*
	HWND wnd;
	wnd = FindWindowA("ConsoleWindowClass", NULL);
	SetWindowPos(wnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	*/
	topmostConsole();
}
