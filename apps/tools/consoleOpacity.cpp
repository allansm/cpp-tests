#include <optimizedclass/win.h>
#include <optimizedclass/util.h>
#include <sstream>
int getPercent(char *argv[]){
	float arg;
	float max = 255.0;
	stringstream ss;
	ss << argv[1];
	ss >> arg;
	float per = (max/100.0);
	int percent = per*arg;

	return percent;
}

main(int argc,char *argv[]){
	HWND wnd;
	wnd = GetConsoleWindow();

	/*float arg;
	float max = 255.0;
	stringstream ss;
	ss << argv[1];
	ss >> arg;
	float per = (max/100.0);
	int percent = per*arg;*/
	int percent = getPercent(argv);

	Win().changeOpacity(wnd,percent);
}
