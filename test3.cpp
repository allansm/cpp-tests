#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "class/files.h"
#include <string.h>

using namespace std;

void play(){
	string ext =  Files::getFirstLine("extensions.txt");
	string command = "dir /B "+ext+" > currentfiles";
    system(command.c_str());
	string file = Files::getFirstLine("currentfiles");
	int i = file.find(".opus");
	system("echo 0 > next.txt");
	if(i > 0){
		string cmd = "ffplay -autoexit -nodisp \""+file;
		system(cmd.c_str());
		remove(file.c_str());
	}
	cout << "waiting file" << "\n";
	system("cls");
}

main(){
	while(true){
		play();
	}
}