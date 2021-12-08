#include <iostream>
#include <allansm/io.hpp>

std::string rtrim(std::string txt){
	txt.erase(txt.find_last_not_of(' ')+1);
	txt.erase(txt.find_last_not_of('\t')+1);
	
	return txt;
}

std::string ltrim(std::string txt){
	txt.erase(0, txt.find_first_not_of(' '));
	txt.erase(0, txt.find_first_not_of('\t'));

	return txt;
}

std::string trim(std::string txt){
	return rtrim(ltrim(txt));
}

main(){
	std::string txt = "              hello world                   ";
	
	println(ltrim(txt)+"!!!");	
	println(rtrim(txt)+"!!!");

	txt = trim(txt);
	println(txt+"!!!");
}
