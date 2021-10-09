#include <cpp-lib/io.hpp>
#include <cpp-lib/util.hpp>

using namespace std;

main(){
	int val = input<int>("test:");	
	
	string str = input("test2:");

	println(val);
	println(str);

	if(Util().has(str,";")){
		print_r(Util().explode(str,";"));
	}
}
