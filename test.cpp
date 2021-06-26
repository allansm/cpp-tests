#include "optimizedclass/win.h"
#include "optimizedclass/util.h"
#include "class/io.h"

main(){
	Win p;
	Util u;
	for(HWND win : p.getAll()){
		string app = p.getAppname(win);
		if(app != "" && p.isFocused(app))
			u.println(app+".exe");
	}
}
