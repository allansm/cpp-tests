#include <allansm/path.hpp>
#include <allansm/io.hpp>

std::vector<std::string> test(std::string path){
	std::vector<std::string> tmp;
	std::vector<std::vector<std::string>> tmp2;
	
	//println(path);
	auto back = getcwd();
	chdir(path);
	auto root = ls(".");
	
	for(auto n : root){
		auto current = getcwd();
		if(isDir(n)){
			if(n != "." && n != ".."){
				chdir(n);
				auto p = getcwd();
				
				tmp.push_back(p);

				for(auto x : test(p)){
					tmp.push_back(x);
				}
			}
		}

		chdir(current);
	}

	chdir(back);
	
	return tmp;
}

std::vector<std::string> test2(std::string path){
	std::vector<std::string> arr;
	auto current = getcwd();
	
	chdir(path);
	
	for(auto n : ls(".")){
		if(isFile(n)){
			auto tmp = getcwd()+"/";
			arr.push_back(tmp+n);
		}
	}

	for(auto n : test(path)){
		chdir(n);
		for(auto x : ls(".")){
			if(isFile(x)){
				auto tmp = getcwd()+"/";
				arr.push_back(tmp+x);
			}
		}
	}

	chdir(current);

	return arr;
}

main(int argc,char ** argv){
	print_r(test2(argv[1]));
}
