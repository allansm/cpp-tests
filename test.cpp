#include "optimizedclass/proc.h"
#include "optimizedclass/util.h"
#include "class/io.h"

main(){
	/*Proc p;
	vector<HWND> procs = p.getVisible();

	for(HWND tmp : procs){
		cout << p.getAppname(tmp) << endl;
	}*/
	
	/*string text;
	
	cout << "input:";
	getline(cin,text);

	cout << text;*/

	Util u;

	string name = u.input("name:");
	string message = "your name is "+name;
	
	u.print(message);
}
