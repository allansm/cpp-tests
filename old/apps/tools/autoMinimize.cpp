#include <class/io.h>
#include <optimizedclass/win.h>
#include <optimizedclass/util.h>

main(int argc,char *argv[]){
	while(true){
		for(HWND win : Win().getVisible()){	
			if(!Win().isFocused(Win().getAppname(win))){
				if(!Win().isTopmost(win)){
					if(!Win().isMinimized(win)){
						if(!Win().isMaximized(win)){
							Win().minimize(win);
						}
					}
				}
			}
		}
		Sleep(10000);
	}
}
