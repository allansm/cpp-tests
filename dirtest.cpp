#include <path.cpp>
#include <allansm/io.hpp>

std::vector<std::string> test(std::string path){
	std::vector<std::string> tmp;
	std::vector<std::vector<std::string>> tmp2;
	//println(path);
	auto root = ls(path);
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

	return tmp;
}

main(int argc,char ** argv){
	print_r(test(argv[1]));
}
