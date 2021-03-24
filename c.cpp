#include "class/io.h"
#include <string.h>

string erase(string txt,string del){
	return txt.erase(txt.find(del),txt.find(del)+del.length());
}

string getArg(int argc,char** argv,string fnd){
	for(int i =0; i<argc;i++){
		string tmp = argv[i];
		if(tmp.find(fnd) != -1){
			tmp = erase(tmp,fnd);
			return tmp;
		}
	}
}

main(int argc,char** argv){
	string pname = getArg(argc,argv,".cpp");
	string cmd = "g++ -o "+pname+".exe "+pname+".cpp";
	system(cmd.c_str());
}