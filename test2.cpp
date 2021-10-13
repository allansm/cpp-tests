#include <cpp-lib/io.hpp>
#include <cpp-lib/path.hpp>

main(){
	std::string cwd = getcwd();

	auto arr = ls("..");
	
	chdir("../"+arr[8]);

	print_r(ls("."));

	chdir("c:/");

	print_r(ls("."));

	chdir(ls(".")[23]);

	print_r(ls("."));

	chdir(cwd);

	system("notepad test2.cpp");
}
