#include <cpp-lib/parser.hpp>
#include <cpp-lib/io.hpp>

using namespace std;

main(){	
	auto x = unknown(10);	

	x = x+2;
	x = x+1;			
	
	int n = x;

	x = "result:"+x.data;

	println(x.data);

	x = "allansm u.u";
	
	println((string)x);

	x = n;	
	
	println(x+2.5);	
}	
