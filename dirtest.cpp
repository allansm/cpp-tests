//#include <iostream>
//#include <vector>
#include <allansm/path.hpp>
#include <allansm/io.hpp>

std::vector<std::string> test(std::string path){
	std::vector<std::string> tmp;
	std::vector<std::vector<std::string>> tmp2;
	//println(path);
	//auto current = getcwd();
	//chdir(path);
	//path = getcwd();
	//chdir(current);
	println(path);
	auto back = getcwd();
	chdir(path);
	auto root = ls(".");
	//chdir(current);
	//print_r(root);
	for(auto n : root){
		auto current = getcwd();
		if(isDir(n)){
			if(n != "." && n != ".."){
				//auto current = getcwd();
				chdir(n);
				auto p = getcwd();
				//chdir(current);
				tmp.push_back(p);

				for(auto x : test(p)){
					tmp.push_back(x);
				}
			}
		}else{
			//println(">>"+n);
		}
		chdir(current);
	}

	/*for(auto n : tmp2){
		for(auto x : n){
			tmp.push_back(x);
		}
	}*/
	chdir(back);
	return tmp;
}

main(int argc,char ** argv){
	print_r(test(argv[1]));
	println(getcwd());
}
