#include <optimizedclass/win.h>
#include <optimizedclass/util.h>

main(int argc,char *argv[]){
	for(HWND win : Win().getAll()){
		if(Win().getAppname(win) == argv[1]){
			Win().minimize(win);
		}
	}
}
