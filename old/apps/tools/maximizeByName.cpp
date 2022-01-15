#include <cpp-lib/win.h>
#include <cpp-lib/util.h>

main(int argc,char *argv[]){
	for(HWND win : Win().getAll()){
		if(Win().getAppname(win) == argv[1]){
			Win().maximize(win);
		}
	}
}
