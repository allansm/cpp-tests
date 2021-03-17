#include "class/io.h"
#include <string.h>

int main(int argc, char* argv[]){
    string app = argv[0];
	string cmd = "start "+app+".lnk";
	system(cmd.c_str());
}