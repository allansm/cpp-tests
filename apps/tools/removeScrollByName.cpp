#include <class/io.h>
#include <optimizedclass/win.h>
#include <optimizedclass/util.h>

main(int argc,char *argv[]){
	while(true){
		for(HWND win : Win().getAll()){
			if(Win().getAppname(win) == argv[1]){
				Win().hideScrollbar(win);
			}
		}
		Sleep(100);
	}
}
