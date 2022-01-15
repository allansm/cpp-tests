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
	string cmd = "wmic OS get FreePhysicalMemory > .ram";
	system(cmd.c_str());
	string avaible = Files::getLines(".ram")[1];
	avaible = getDigits(avaible);
	return Util::parseFloat(avaible)/1000;
}

float getRam(){
	return Util::parseFloat(Files::getFirstLine("ram.txt"));
}

main(){
	cout << getAvaibleMemory();
	remove(".ram");
}
