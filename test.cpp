#include <cpp-lib/io.hpp>
#include <cpp-lib/util.hpp>
#include <cpp-lib/files.hpp>
#include <cpp-lib/parser.hpp>

using namespace std;

main(){
	int val = input<int>("n:");	
	
	string str = input("file or array:");
	
	println(to<string>(val)+"+2 = "+to<string>(val+2));
	println(str);

	if(Util().has(str,";")){
		print_r(Util().explode(str,";"));
	}

	if(Util().has(str,".")){
		println(Files().readFile(str));
	}
}
