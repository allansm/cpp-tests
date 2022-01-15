#include <fstream>
#include <allansm/io.hpp>
#include <files.cpp>

main(){
	std::vector<char> buffer;
	std::ifstream test("test3.cpp");
	
	test.seekg(0, test.end);
	size_t sz = test.tellg();
	test.seekg(0, test.beg);

	
	buffer.resize(sz);
	test.read(&buffer[0],sz);
	test.close();
	
	for(auto n : buffer){
		print(n);
		print(" ");
	}
}
