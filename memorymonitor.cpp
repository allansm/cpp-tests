#include "class/io.h"
#include "class/files.h"
#include "class/util.h"
#include <string.h>

string removeBlank(string str){
	int size = str.length();
	string ret = "";
	for(int i=0;i<size;i++){
		if(str.at(i) != ' '){
			ret+=str.at(i);
		}
	}
	return ret;
}

string getDigits(string str){
	int size = str.length();
	string ret = "";
	for(int i=0;i<size;i++){
		if(isdigit(str.at(i))){
			ret+=str.at(i);
		}
	}
	return ret;
}

float getAvaibleMemory(){
	string cmd = "wmic OS get FreePhysicalMemory > avaible.txt";
	system(cmd.c_str());
	string avaible = Files::getLines("avaible.txt")[1];
	avaible = getDigits(avaible);
	return Util::parseFloat(avaible)/1000;
}

float getRam(){
	return Util::parseFloat(Files::getFirstLine("ram.txt"));
}

void doActionsIf(){
	string* lines = Files::getLines("if.txt");
	int size = Files::countLines("if.txt");
	
	for(int i=0;i<size;i++){
		cout << "executing:" << lines[i] << endl;
		system(lines[i].c_str());
	}
}

void doActionsElse(){
	string* lines = Files::getLines("else.txt");
	int size = Files::countLines("else.txt");
	
	for(int i=0;i<size;i++){
		cout << "executing:" << lines[i] << endl;
		system(lines[i].c_str());
	}
}
bool flag = true;

void monitorate(float percent){	
	system("cls");
	float ram = getRam();
	float rpercent = (ram*percent);
	cout << "avaible:" <<getAvaibleMemory() << "mb\n";
	cout << "min:" <<rpercent << "mb\n";
	if(getAvaibleMemory() < rpercent){
		if(flag){
			flag = false;
			doActionsIf();
		}
	}else{
		if(!flag){
			flag = true;
			doActionsElse();
		}
	}
}

void run(){
	while(true){
		float percent = Util::parseFloat(Files::getFirstLine("percent.txt"));
		monitorate(percent);
		Sleep(5000);
	}
}

main(){
	run();
}