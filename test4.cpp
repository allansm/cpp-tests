#include <optimizedclass/win.h>
#include <optimizedclass/util.h>

bool isTopmost(HWND wnd){
	if (::GetWindowLong(wnd, GWL_EXSTYLE) & WS_EX_TOPMOST){
		return true;
	}else{
		return false;
	}
	
}

main(){
	HWND wnd = GetConsoleWindow();

	/*if (::GetWindowLong(wnd, GWL_EXSTYLE) & WS_EX_TOPMOST){
		Util().print("yes");		
	}else{
		Util().print("no");
	}*/

	if(isTopmost(wnd)){
		Util().print("yes");	
	}else{
		Util().print("no");
	}
}
