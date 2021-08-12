//#define WIN32_LEAN_AND_MEAN
//#define _WIN32_WINNT 0x0500
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>
#include <iostream>
using namespace std;

void *test(void *x){
	cout << "working";
	/*HWND win = *((HWND *) &x);
	while(true){
			}*/	cout << "im hiding\n";
	return 0;
}

main(){
	HWND x = GetConsoleWindow();
	while(true){
		ShowScrollBar(x, SB_BOTH, FALSE);
		Sleep(100);
	}
}
