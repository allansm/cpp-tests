#include <allansm/win.hpp>
#include <allansm/io.hpp>
#include <allansm/parser.hpp>
#include <allansm/util.hpp>

main(int argc,char ** argv){

	for(auto n:Win().getAll()){

		if(Win().getAppname(n) == argv[1]){
			std::string a = argv[2];
			std::string b = argv[3];
			
			int x = unknown(a);
			int y = unknown(b);
			
			Win().resize(n, x, y);
			
			println("change");
		}
	}
}
