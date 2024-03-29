#include <allansm/io.hpp>
#include <win.cpp>
#include <util.cpp>
#include <sstream>

int getPercent(char *argv[]){
	float arg;
	float max = 255.0;
	stringstream ss;
	ss << argv[2];
	ss >> arg;
	float per = (max/100.0);
	int percent = per*arg;

	return percent;
}

main(int argc,char *argv[]){
	int percent = getPercent(argv);

	for(HWND win : Win().getAll()){
		if(Win().getAppname(win) == argv[1]){
			println("changed: "+Win().getAppname(win));
			Win().changeOpacity(win,percent);
		}
	}
}
