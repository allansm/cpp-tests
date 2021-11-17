#include <cctype>
#include <iostream>
#include <allansm/io.hpp>

std::string str(std::string t,int (*type)(int)){
	std::string tmp = "";
	
	for(int i=0;i<t.size();i++){
		tmp+=type(t[i]);
	}
	
	return tmp;	
}

main(){
	char a = 'A';
	a = tolower(a);
	println(a);
	a = toupper(a);
	println(a);

	println(str("AaAaAa",tolower));
	print(str("AaAaAa",toupper));
}
