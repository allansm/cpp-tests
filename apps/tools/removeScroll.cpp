#include <optimizedclass/win.h>

main(){
	HWND x = GetConsoleWindow();
	while(true){
		Win().hideScrollbar(x);
		Sleep(100);
	}
}
