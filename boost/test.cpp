#include <iostream>

#include <boost/filesystem.hpp>

using namespace boost::filesystem;

void mkdir(std::string p){
	if(!exists(p)) create_directory(p);
}

void rmdir(std::string p){
	if(exists(p)) remove_all(p);
}

std::string getcwd(){
	return current_path().string();
}

std::string realpath(std::string p){
	return absolute(p).string();
}

std::string basename(std::string p){
	return path(p).filename().string();
}

std::string getTemp(){
	return temp_directory_path().string();
}

bool isdir(std::string p){
	return is_directory(p);
}

void list_files(std::string p){
	for(auto n : directory_iterator(p)){ 	
		if(isdir(n.path().string())){
			list_files(n.path().string());
		}else{
			std::cout << n.path().string() << "\n";
		}
	}
}

void chdir(std::string p){
	current_path(p);
}

int main(){
	chdir("..");

	std::cout << realpath("test.cpp") << "\n";
	std::cout << getcwd() << "\n";
	std::cout << basename(getcwd()) << "\n";
	std::cout << getTemp() << "\n\n";
	
	mkdir("somedir");
	
	list_files(".");
	
	rmdir("somedir");
}
