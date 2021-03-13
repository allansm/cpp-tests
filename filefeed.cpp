#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "class/files.h"
#include "class/util.h"

using namespace std;

void feed(){
	string line = Files::getFirstLine("feed.txt");
	string a = Util::split(line," > ",0);
	string b = Util::split(line," > ",1);
	
	if(Files::getFirstLine(b.c_str()) == ""){
	
		string line;
		//int size = Files::countLines(b.c_str());
		//string lines[size];
		//int count = 0;
		
		ifstream temp(a.c_str());
		while (getline (temp,line)) {
			cout << a << " " << line << " >> " << b << "\n";
			
			string cmd = "echo "+line+" >> "+b;
			system(cmd.c_str());
		}
		
	}
}

main(){
	while(true){
		feed();
		Sleep(1000);
	}
}