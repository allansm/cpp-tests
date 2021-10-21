#include <iostream>
//#include <limits.h>
#include <stdlib.h>

main(int argc,char **argv){
	char buf[255] = "";
	_fullpath(buf,argv[0],255);
	std::cout << buf;//realpath(argv[0],NULL);
}
