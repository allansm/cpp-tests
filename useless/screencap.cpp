#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

main(){
    stringstream ss;
    string ip;
    cout << "set ip:";
    cin >> ip;
    ss << "adb -s " << ip << " exec-out screencap -p > screen.jpg";
    while(true){
        system(ss.str().c_str());
        cout << "capture\n";
        Sleep(1);
    }
}
