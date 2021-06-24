#include "class/io.h"
#include "class/files2.h"

main(){
	Files2 f2;
	
	vector<string> lines = f2.getLines("test.cpp");

	for(string line:lines){
		cout << line << endl;
	}
}
