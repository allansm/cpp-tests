#include <iostream>
//#include <stdlib.h>
//#include <cpp-lib/util.hpp>
#include <cpp-lib/path.hpp>
/*std::string test(char **argv){
	#if defined _WIN32
		char buf[255] = "";
		_fullpath(buf,argv[0],255);

		return buf;
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		return realpath(argv[0],NULL);	
	#endif

	return "";
}*/

std::string test(char **argv){	
	std::string tmp = argv[0];
	
	int end = 0;
	for(int i = 0;i<tmp.length();i++){	
		if(tmp.at(i) == '\\' || tmp.at(i) == '/'){
			end = i;
		}
	}

	auto relative = tmp.substr(0,end);

	if(relative == ""){
		return ".";
	}else{
		return relative;
	}	
}

std::string test2(char **argv){
	auto current = getcwd();

	chdir(test(argv));

	auto tmp = getcwd();

	chdir(current);

	return tmp;
}

main(int argc,char **argv){	
	std::cout << test2(argv);
}
