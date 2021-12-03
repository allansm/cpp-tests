#include <iostream>
#include <allansm/io.hpp>

int ord(char c){
	return (int)c;
}

char chr(int n){
	return (char)n;
}

std::vector<int> getBytes(std::string txt){
	std::vector<int> tmp;

	for(int i=0;i<txt.length();i++){
		tmp.push_back(txt.at(i));	
	}

	return tmp;
}

std::string toString(std::vector<int> bytes){
	std::string tmp = "";

	for(auto n : bytes){
		tmp+= chr(n);
	}

	return tmp;
}

main(){
	std::string txt = "helloworld";
	
	for(int i=0;i<txt.length();i++){
		int tmp = ord(txt.at(i));
		char tmp2 = chr(tmp);
		print(tmp);
		print(" ");
		println(tmp2);
	}

	auto bytes = getBytes(txt);
	
	print_r(bytes);

	println(toString(bytes));
}
