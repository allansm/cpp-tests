#include <cpp-lib/io.hpp>
#include <cpp-lib/path.hpp>
//#include <sys/stat.h>
//using namespace std;
/*void test(std::string path){
	struct stat s;
	if(stat(path.c_str(),&s) == 0){
		if(s.st_mode & S_IFDIR){
			print("isdir");
		}else if(s.st_mode & S_IFREG){
			print("isfile");

		}else{
			print("dunno");
		}
	}else{}
}*/

main(){
	std::string cwd = getcwd();

	auto arr = ls("..");
	
	chdir("../"+arr[8]);

	print_r(ls("."));

	chdir("c:/");

	print_r(ls("."));

	chdir(ls(".")[23]);

	print_r(ls("."));

	chdir("e:/");
	
	bool flag = true;
	while(flag){
		flag = false;
		println(getcwd());

		for(auto s : ls(".")){
			if(isDir(s) && s != "." && s != ".."){
				chdir(s);
				flag = true;
			}
		}
	}
}
