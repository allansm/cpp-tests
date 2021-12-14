#include <fstream>
#include <allansm/io.hpp>

main(int argc,char ** argv){
	std::ifstream in(argv[1], std::ifstream::ate | std::ifstream::binary);
	print(in.tellg()/1024/1024);
}
