#include <windows.h>
#include <tchar.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <vector>
#include <string>

using namespace std;

class Win{
	public:
		Win();
		
		vector<HWND> getVisible();
		vector<HWND> getAll();
		
		string getAppname(HWND hwnd);

		bool isRunning(string name);
		bool isRunning(HWND proc);
		bool isFocused(string name);
		bool isFocused(HWND hwnd,string name);
		bool isMaximized(HWND hwnd);
		bool isMinimized(HWND hwnd);
		bool isTopmost(HWND wnd);

		void topmost(HWND wnd);
		void removeBorders(HWND wnd);
		void hideScrollbar(HWND wnd);
		void maximize(HWND wnd);
		void minimize(HWND wnd);		
};

Win::Win(){

}

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

bool Win::isFocused(HWND hwnd,string name){
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

bool Win::isFocused(string name){
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

string Win::getAppname(HWND hwnd){
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

bool Win::isMaximized(HWND hwnd){
	return IsZoomed(hwnd);
}

bool Win::isMinimized(HWND hwnd){
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

vector<HWND> Win::getVisible(){
	vector<HWND> list;
	for(HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT)){   
		if (!IsWindowVisible(hwnd))
			continue;
			int length = GetWindowTextLength(hwnd);
			if (length == 0)
				continue;
				list.push_back(hwnd);
	}
	return list;
}

vector<HWND> Win::getAll(){
	vector<HWND> list;
	for(HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT)){
		int length = GetWindowTextLength(hwnd);
		if (length == 0)
			continue;
			list.push_back(hwnd);
	}
	return list;
}

bool Win::isRunning(string name){
	for(HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT)){
		if(getAppname(hwnd) == name){
			return true;
		}
	}
	return false;
}

bool Win::isRunning(HWND proc){
	for(HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT)){
		if(hwnd == proc){
			return true;
		}
	}
	return false;
}

bool Win::isTopmost(HWND wnd){
	if (::GetWindowLong(wnd, GWL_EXSTYLE) & WS_EX_TOPMOST){
		return true;
	}else{
		return false;
	}
	
}

void Win::topmost(HWND wnd){
	SetWindowPos(wnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

void Win::removeBorders(HWND wnd){
	LONG lStyle = GetWindowLong(wnd, GWL_STYLE);
	lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
	SetWindowLong(wnd, GWL_STYLE, lStyle);
}

void Win::hideScrollbar(HWND wnd){
	ShowScrollBar(wnd, SB_BOTH, FALSE);	
}

void Win::maximize(HWND wnd){
	LONG lStyle = GetWindowLong(wnd, GWL_STYLE);
	lStyle &= ~WS_BORDER;
	lStyle &= ~WS_DLGFRAME;
	lStyle &= ~WS_THICKFRAME;
	SetWindowLong(wnd, GWL_STYLE, lStyle);
	ShowWindow(wnd,SW_SHOWMAXIMIZED);
}

void Win::minimize(HWND wnd){
	ShowWindow(wnd,SW_MINIMIZE);
}
