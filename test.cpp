#include "class/io.h"
#include "class/files.h"
#include "class/util.h"

#include <windows.h>
#include <tchar.h>
#include <tlhelp32.h>
#include <psapi.h>



string getname(string appname){
	while(true){
		if(appname.find("\\") != -1){
			int i = appname.find("\\");
			i = (i==0)?1:i;
			appname.erase(0,i);
		}else{
			break;
		}
		appname = appname.substr(0,appname.find("."));
	}
	return appname;
}

bool isFocused(HWND hwnd,string name){
	DWORD dwPID;
	GetWindowThreadProcessId(hwnd, &dwPID);
	
	HANDLE Handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,FALSE,dwPID);
	if(Handle){
		CHAR Buffer[MAX_PATH];
		if( GetModuleFileNameEx(Handle,NULL,Buffer,MAX_PATH) ){
			string appname = getname(Buffer);

			if(appname == name){
				return true;
			}
		}
		CloseHandle(Handle);
	}
	return false;
}
bool isFocused(string name){
	HWND hwnd = GetForegroundWindow();
	return isFocused(hwnd,name);
}

string getAppname(HWND hwnd){
	DWORD dwPID;
	GetWindowThreadProcessId(hwnd, &dwPID);
	
	HANDLE Handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,FALSE,dwPID);
	if(Handle){
		CHAR Buffer[MAX_PATH];
		if( GetModuleFileNameEx(Handle,NULL,Buffer,MAX_PATH) ){
			string appname = getname(Buffer);

			return appname;
		}
		CloseHandle(Handle);
	}
	return "";
}

bool isMaximized(HWND hwnd){
	return IsZoomed(hwnd);
}

bool isMinimized(HWND hwnd){
	return IsIconic(hwnd);
}

int n(){
	int size = 0;
	for (HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT)){   
		if (!IsWindowVisible(hwnd))
			continue;
			int length = GetWindowTextLength(hwnd);
			if (length == 0)
				continue;
				size++;
	}

	return size;
}

HWND* getVisible(){
	HWND* list = new HWND[n()];
	int i = 0;
	for(HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT)){   
		if (!IsWindowVisible(hwnd))
			continue;
			int length = GetWindowTextLength(hwnd);
			if (length == 0)
				continue;
				list[i++] = hwnd;
	}
	return list;
}

bool isRunning(string name){
	for(HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT)){
		if(getAppname(hwnd) == name){
			return true;
		}
	}
	return false;
}


string* split(string line){
	return Util::split(line," : ");
}

void execute(string fname){
	string* lines = Files::getLines(fname.c_str());
	
	for(int i=0;i<Files::countLines(fname.c_str());i++){
		system(lines[i].c_str());
	}
}


bool execute(string name,string cond){
	if(cond == "focused"){
		if(isFocused(name)){
			return true;
		}
	}else if(cond == "running"){
		if(isRunning(name)){
			return true;
		}
	}else if(cond == "maximized"){
	
	}else if(cond == "minimized"){

	}
	return false;
}


main(){
	bool canExecute = false;
	bool swtch = true;

	while(true){
		string* lines = Files::getLines(".config");

		for(int i=1;i<Files::countLines(".config");i++){
			
			string* args = split(lines[i]);
			if(execute(args[0],args[1])){
				canExecute = true;
				break;
			}
		}
		if(canExecute){
			if(swtch){
				cout << "executing if" << endl;
				swtch = false;
				execute("if.txt");
			}
			canExecute = false;
		}else{
			cout << "executing else" << endl;
			swtch = true;
			execute("else.txt");
		}
		Sleep(Util::parseInt(lines[0]));
	}	
}

