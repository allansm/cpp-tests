#include <windows.h>
#include <tchar.h>
#include <tlhelp32.h>
#include <psapi.h>

class Proc{

	public : static string getname(string appname){
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

	public : static bool isFocused(HWND hwnd,string name){
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

	public : static bool isFocused(string name){
		HWND hwnd = GetForegroundWindow();
		return isFocused(hwnd,name);
	}

	public : static string getAppname(HWND hwnd){
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

	public : static bool isMaximized(HWND hwnd){
		return IsZoomed(hwnd);
	}

	public : static bool isMinimized(HWND hwnd){
		return IsIconic(hwnd);
	}

	public : static int n(){
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

	public : static HWND* getVisible(){
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

	public : static bool isRunning(string name){
		for(HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT)){
			if(getAppname(hwnd) == name){
				return true;
			}
		}
		return false;
	}
};
