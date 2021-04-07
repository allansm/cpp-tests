#include "class/io.h"
#include "class/files.h"
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
			        //char* title = new char[length+1];
				//GetWindowText(hwnd, title, length+1);
				//cout << getAppname(hwnd) << endl;
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
			        //char* title = new char[length+1];
				//GetWindowText(hwnd, title, length+1);
				//cout << getAppname(hwnd) << endl;
				//size++;
	}
	return list;
}


main(){
	//string command = Files::getFirstLine(".config");

	string* lines = Files::getLines(".config");

	for(int i=2;i<Files::countLines(".config");i++){
		cout << lines[i] << endl;
	}

	system(lines[0].c_str());
	system(lines[1].c_str());

	//HWND hwnd = GetForegroundWindow();
	
	/*HWND* list = getVisible();

	for(int i= 0;i<n();i++){
		cout << getAppname(list[i]) << endl;
	}*/
}

