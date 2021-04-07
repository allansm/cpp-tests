#include "class/io.h"
#include <windows.h>
#include <tchar.h>

void test(HWND hWnd){
	TCHAR buffer[MAX_PATH] = {0};
	DWORD dwProcId = 0; 

	GetWindowThreadProcessId(hWnd, &dwProcId);   

	HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ , FALSE, dwProcId);    
	GetModuleFileName((HMODULE)hProc, buffer, MAX_PATH);
	
	cout << buffer << endl;


	CloseHandle(hProc);
}

main(){
	while(true){
		TCHAR wnd_title[256];
		HWND hwnd = GetForegroundWindow();
		GetWindowTextA(hwnd, wnd_title, 256);
		
		test(hwnd);
		
		//DWORD dwPID;
		//GetWindowThreadProcessId(hwnd, &dwPID);
		
		/*HANDLE Handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,FALSE,dwPID);
		if(Handle){
			TCHAR Buffer[MAX_PATH];
			if( GetModuleFileNameEx(Handle,0,Buffer,MAX_PATH) ){
				cout << Buffer << endl;
				//_tprintf(_T("Path: %s"), Buffer);
				// At this point, buffer contains the full path to the executable
			}
			CloseHandle(Handle);
		}*/
	}
}
