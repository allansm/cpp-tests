#include <class/io.h>
#include <optimizedclass/win.h>
#include <optimizedclass/util.h>

main(int argc,char *argv[]){
	for(HWND win : Win().getAll()){	
		Util().println(Win().getAppname(win));
	}
}
