#include <optimizedclass/win.h>

main(){
	HWND wnd;
	wnd = GetConsoleWindow();
	
	Win().maximize(wnd);
}
