#include <optimizedclass/basic.h>
#include <optimizedclass/util.h>
#include <filesystem>

//namespace fs = std::filesystem

main(){
	chdir("c:/");
	
	//string tmp = fs::current_path();

	//Util().print(tmp);
	
	system("echo %cd%");
}
