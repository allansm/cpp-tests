#include <optimizedclass/win.h>

void changeOpacity(HWND wnd,int opacity){
	SetWindowLong(wnd, GWL_EXSTYLE, GetWindowLong(wnd, GWL_EXSTYLE) & WS_EX_LAYERED);
	//SetLayeredWindowAttributes(wnd, RGB(154,255,214), 200, LWA_ALPHA);

							  //100%	
	//SetLayeredWindowAttributes(wnd, RGB(154,255,214), 255, LWA_ALPHA);
	SetLayeredWindowAttributes(wnd, RGB(154,255,214), opacity, LWA_ALPHA);	
}

main(){
	HWND wnd;
	wnd = GetConsoleWindow();
	changeOpacity(wnd,255);
}
