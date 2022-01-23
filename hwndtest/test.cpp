#include <windows.h>

main(){
	HWND hwnd = GetConsoleWindow();
	if( hwnd != NULL ){ MoveWindow(hwnd ,0,0 ,400,400 ,TRUE); }
}
