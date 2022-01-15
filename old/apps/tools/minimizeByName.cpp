#include <win.cpp>
#include <util.cpp>

main(int argc,char *argv[]){
	for(HWND win : Win().getAll()){
		if(Win().getAppname(win) == argv[1]){
			Win().minimize(win);
		}
	}
}
