#include "class/io.h"
#include "class/files.h"
#include "class/util.h"
#include <string.h>

float getAvaibleMemory(){
	string cmd = "php \"php/avaibleMemory.php\" > avaible.txt";
	system(cmd.c_str());
	string avaible = Files::getFirstLine("avaible.txt");
	return Util::parseFloat(avaible);
}

float getRam(){
	return Util::parseFloat(Files::getFirstLine("ram.txt"));
}

void doActionsIf(){
	string* lines = Files::getLines("if.txt");
	int size = Files::countLines("if.txt");
	
	for(int i=0;i<size;i++){
		system(lines[i].c_str());
	}
}

void doActionsElse(){
	string* lines = Files::getLines("else.txt");
	int size = Files::countLines("else.txt");
	
	for(int i=0;i<size;i++){
		system(lines[i].c_str());
	}
}

void monitorate(float percent){
	bool flag = true;
	system("cls");
	float ram = getRam();
	float rpercent = (ram*percent);
	cout << getAvaibleMemory() << "mb\n";
	cout << getAvaibleMemory() << " " << rpercent << endl;
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
	float percent = Util::parseFloat(Files::getFirstLine("percent.txt"));
	//cout << "percent:";
	//cin >> percent;
	while(true){
		monitorate(percent);
		Sleep(1000);
	}
}

main(){
	run();
}