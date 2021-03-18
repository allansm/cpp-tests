#include "class/files.h"
#include "class/io.h"

void genUrl(){
	string* paths = Files::getLines("localfiles.txt");
	int i =0;
	try{
		while(true){
			cout << paths[i] << " >> " << "url.txt";
			string dir = "dir /s /B \""+paths[i++]+"\" >> url.txt";
			system(dir.c_str());
		}
	}catch(const exception &e){}
}

void run(){
	cout << "starting manager...\n";
	while(true){
		if(Files::getFirstLine("url.txt") == ""){
			genUrl();
		}
		if(Files::getFirstLine("file") == ""){
			cout << "setting file...\n";
			string ext =  Files::getFirstLine("extensions.txt");
			string command = "dir /B "+ext+" > currentfiles";
			ext = Files::getFirstLine("extension.txt");
			system(command.c_str());
			string file = Files::getFirstLine("currentfiles");
			int i = file.find(ext);
			//system("echo 0 > next.txt");
			if(i > 0){
				Sleep(1);
				string cmd = "echo \""+file+"\" > file";
				//cout << "writing:" << cmd << endl;
				system(cmd.c_str());
			}else{
				system("echo 0 > next.txt");
				string random = Files::getRandomLine("url.txt");
				Files::removeLine("url.txt",random);
				string cmd = "echo \""+random+"\" > file";
				//cout << "writing:" << cmd << endl;
				system(cmd.c_str());
			}
		}
		Sleep(100);
	}
}

main(){
	run();
}