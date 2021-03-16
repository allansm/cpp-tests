#include "class/files.h"
#include "class/io.h"

void genUrl(){
	string* paths = Files::getLines("localfiles.txt");
	int i =0;
	try{
		while(true){
			string dir = "dir /s /B \""+paths[i++]+"\" >> url.txt";
			system(dir.c_str());
		}
	}catch(const exception &e){}
}

/*void test(){
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
		//string log = "echo "+file+" >> .log";
		//system(log.c_str());
	}
}*/

void run(){
	while(true){
		if(Files::getFirstLine("url.txt") == ""){
			genUrl();
		}
		if(Files::getFirstLine("file") == ""){
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
				string cmd = "echo "+file+" > file";
				system(cmd.c_str());
				//string log = "echo "+file+" >> .log";
				//system(log.c_str());
			}else{
				string random = Files::getRandomLine("url.txt");
				Files::removeLine("url.txt",random);
				string cmd = "echo "+random+" > file";
				system(cmd.c_str());
			}
		}
		Sleep(100);
	}
}

main(){
	run();
}