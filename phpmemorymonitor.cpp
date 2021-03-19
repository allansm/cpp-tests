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
	system("cls");
	float ram = getRam();
	cout << getAvaibleMemory() << "mb\n";
	if(getAvaibleMemory() < (ram*percent)){
		doActionsIf();
	}else{
		doActionsElse();
	}
}

void run(){
	float percent;
	cout << "percent:";
	cin >> percent;
	while(true){
		monitorate(percent);
		Sleep(1000);
	}
}

main(){
	run();
}