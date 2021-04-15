#include "class/io.h"
#include "class/proc.h"

//using namespace std;

void old(){
	//string test = "c:\\app\\app.exe";
	//cout << Proc::getname(test);
	HWND* procs = Proc::getVisible();
	
	for(int i=0;i<Proc::n();i++){
		cout << Proc::getAppname(procs[i]) << endl;
	}

}

main(){
	while(true){
		string cmd;

		cout << "cmd>";
		cin >> cmd;

		system(cmd.c_str());

	}
}
