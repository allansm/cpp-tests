#include "class/files.h"
#include "class/io.h"
#include "class/time.h"

string lastfile = "nofile";

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

bool isAvaible(){
	string ext =  Files::getFirstLine("extensions.txt");
	string command = "dir /B "+ext+" > currentfiles";
	ext = Files::getFirstLine("extension.txt");
	system(command.c_str());
	string file = Files::getFirstLine("currentfiles");
	if(file != Files::getFirstLine("file")){
		int i = file.find(ext);
		
		return i != -1;
	}
	return false;
}
int nfile(){
	int lines = Files::countLines("currentFiles");
	cout << lines << endl;
	return lines;
}

bool isNotTemp(){
	string file = Files::getFirstLine("currentfiles");
	int i = file.find("temp");
	if(i != -1){
		remove(file.c_str());
	}
	return i == -1;
}

long int start;

bool isStuck(){
	int elapsed = Time::toSec(Time::elapsedTime(start));
	if(elapsed > 300){
		return true;
	}
	return false;
}

void run(){
	start = Time::currentTimeToMs();
	cout << "starting manager...\n";
	while(true){
		if(Files::getFirstLine("url.txt") == ""){
			genUrl();
		}
		//string file = Files::getFirstLine("currentfiles");
		if(Files::getFirstLine("file") == ""){
			cout << "setting file...\n";
			
			//system("echo 0 > next.txt");
			if(isAvaible() && isNotTemp()){
				if((nfile() < 2)){
					system("echo 0 > next.txt");
				}
				start = Time::currentTimeToMs();
				Sleep(1);
				string file = Files::getFirstLine("currentfiles");
				string cmd = "echo \""+file+"\" > file";
				//cout << "writing:" << cmd << endl;
				system(cmd.c_str());
			}else{
				if((nfile() < 2)){
					system("echo 0 > next.txt");
				}
				start = Time::currentTimeToMs();
				string random = Files::getRandomLine("url.txt");
				Files::removeLine("url.txt",random);
				string cmd = "echo \""+random+"\" > file";
				//cout << "writing:" << cmd << endl;
				system(cmd.c_str());
			}
		}else if(isAvaible() && isNotTemp()){
			//system("echo 0 > next.txt");
			Sleep(1);
			string file = Files::getFirstLine("currentfiles");
			string cmd = "echo \""+file+"\" > file";
			//cout << "writing:" << cmd << endl;
			system(cmd.c_str());
		}
		if(isStuck() && (nfile() < 2)){
			system("echo 0 > next.txt");
			start = Time::currentTimeToMs();
		}
		Sleep(100);
	}
}

main(){
	run();
}