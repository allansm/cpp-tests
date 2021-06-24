#include "class/io.h"
#include "optimizedclass/util.h"
#include "optimizedclass/files.h"

main(){
	Util util;
	Files files;
	
	vector<string> lines = files.getLines("test.cpp");

	for(string line : lines){
		if(util.has(line,"util.has")){
			cout << line;
		}
	}
}
