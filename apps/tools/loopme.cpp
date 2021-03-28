#include "class/io.h"
#include "class/files.h"
#include "class/util.h"

using namespace std;

int main(int argc, char* argv[]){
	int n;
	cout << "line:";
	cin >> n;
	string appname = argv[0];
	while(true){
		if(appname.find("\\") != -1){
			int i = appname.find("\\");
			i = (i==0)?1:i;
			appname.erase(0,i);
			cout << appname << endl;
		}else{
			break;
		}
	}
	appname = appname.substr(0,appname.find("."));
	string file = appname+".txt";
	cout << file << endl;
	string cmd = Files::getLine(file.c_str(),n);
	
	while(true){
		system(cmd.c_str());
		Sleep(1);
	}
}