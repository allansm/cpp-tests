#include <windows.h>
#include <iostream>

using namespace std;

main(){
	HWND wnd;
	wnd = GetConsoleWindow();	
	ShowWindow(wnd,SW_MINIMIZE);
}
