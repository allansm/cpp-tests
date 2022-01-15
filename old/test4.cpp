#include <fstream>
#include <iterator>
#include <vector>
#include <allansm/io.hpp>

main(){
	std::ifstream input("test4.cpp", std::ios::binary);
	std::vector<int> bytes((std::istreambuf_iterator<char>(input)),(std::istreambuf_iterator<char>()));
	input.close();

	print_r(bytes);
	print("\n");

	for(char n : bytes){
		print(n);
	}
}
