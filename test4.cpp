#include <cpp-lib/parser.hpp>
#include <cpp-lib/io.hpp>

using namespace std;

main(){	
	auto x = unknown(10);	

	x = x+2;
	x = x+1;			
	
	x = (string) "result:"+x.data;

	println(x.data);

	x = (string) "allansm u.u";

	println(x.data);
}	
