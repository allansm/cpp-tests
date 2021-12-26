#include <iostream>
#include <allansm/io.hpp>

main(){
	std::string k = "0123456789ABCDEF";
	int n = 'h';

	std::string res;
	while(n > 0){
		print(n%16);
		print(" ");
		println(n/16);
		res = k[n % 16] + res;
		n = n/16;
	}

	std::cout << res;
}
