#include <fstream>
#include <allansm/io.hpp>
#include <limits>

void old(char ** argv){
	std::ifstream in(argv[1], std::ifstream::ate | std::ifstream::binary);
	print(in.tellg()/1024/1024);
}

long test(char ** argv){
	std::ifstream file(argv[1],std::ios::in|std::ios::binary);
	file.ignore(std::numeric_limits<std::streamsize>::max());
	long length = file.gcount();
	file.clear();
	file.seekg(0, std::ios_base::beg);
	file.close();
	
	return length;
}

main(int argc,char ** argv){
	print(test(argv)/1024);
}
