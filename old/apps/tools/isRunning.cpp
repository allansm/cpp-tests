#include "class/io.h"
#include "class/proc.h"

void run(string pname){
	if(Proc::isRunning(pname)){
		cout << "yes";
	}else{
		cout << "no";
	}
}

main(int argc,char *argv[]){
	run(argv[1]);
}
