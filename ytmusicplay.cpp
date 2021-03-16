#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "class/files.h"
#include <string.h>

using namespace std;

void play(){
	string ext =  Files::getFirstLine("extensions.txt");
	string command = "dir /B "+ext+" > currentfiles";
	ext = Files::getFirstLine("extension.txt");
    system(command.c_str());
	string file = Files::getFirstLine("currentfiles");
	int i = file.find(ext);
	system("echo 0 > next.txt");
	if(i > 0){
		Sleep(1);
		system("echo 0 > next.txt");
		string log = "echo "+file+" >> .log";
		system(log.c_str());
		string cmd = "ffplay -autoexit -nodisp \""+file;
		system(cmd.c_str());
		remove(file.c_str());
	}
	cout << "waiting file" << "\n";
	//system("cls");
}

main(){
	system("start /B filefeed");
	system("start /B autoytdl");
	while(true){
		play();
	}
}