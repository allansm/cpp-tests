#include "class/io.h"
#include "class/proc.h"

//using namespace std;

main(){
	//string test = "c:\\app\\app.exe";
	//cout << Proc::getname(test);
	HWND* procs = Proc::getVisible();
	
	for(int i=0;i<Proc::n();i++){
		cout << Proc::getAppname(procs[i]) << endl;
	}
}
