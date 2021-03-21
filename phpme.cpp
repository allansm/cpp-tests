#include "class/io.h"

string getAppName(char* arg){
	string appname = arg;
	while(true){
		if(appname.find("\\") != -1){
			int i = appname.find("\\");
			i = (i==0)?1:i;
			appname.erase(0,i);
		}else{
			break;
		}
	}
	appname = appname.substr(0,appname.find("."));
	return appname;
}

int main(int argc, char* argv[]){
	string appname = getAppName(argv[0]);
	string php = "php "+appname+".php";
	system(php.c_str());
}