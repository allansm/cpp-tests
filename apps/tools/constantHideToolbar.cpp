#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
using namespace std;
void HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}
void run(){
    cout << "hiding.\n";
    system("TaskBarHider.exe -hide");
    cout << "waiting..\n";
    Sleep(1000);
    run();
}

main(){
    HideConsole();
    Sleep(60000);
    run();
}
