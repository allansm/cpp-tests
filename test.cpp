#include <cpp-lib/io.hpp>
#include <cpp-lib/win.hpp>

using namespace std;

main(){
	auto all = Win().getAll();

	print_r(Win().getNames(all));

	for(string s : Win().getNames(all)){
		if(Win().isFocused(s)){
			println("focused:"+s);
		}
	}
}
