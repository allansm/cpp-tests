#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>

using namespace std;

main(){
	string cmd = "ffplay -an -x 360 -y 200 -left 0 -top 0 -alwaysontop -noborder -autoexit http://localhost/stream/test2";
	//cin >> cmd;
	while(true){
		system(cmd.c_str());
		Sleep(1);
	}
}