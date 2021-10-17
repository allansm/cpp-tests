#include <cpp-lib/parser.hpp>
#include <iostream>

using namespace std;
main(){	
	auto x = unknown(10);

	int n = x+2;

	x = unknown(n);
	
	string res = x;
	res = "res:"+res;
	cout << res;
}
