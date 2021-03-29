#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

int minute = 60000;

void HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void run(){
	system("sc stop wuauserv");
	std::cout << "waiting 1 minutes\n";
	Sleep(2000);
	run();
}

int main(){
    HideConsole();
	run();
	return 0;
}
