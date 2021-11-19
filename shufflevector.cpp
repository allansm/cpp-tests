#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <allansm/io.hpp>
#include <util.cpp>
#include <time.cpp>

template <typename T>
T test(T arr){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine e(seed);
	std::shuffle(arr.begin(), arr.end(), e);

	return arr;
}

main(){
	std::vector<int> foo{1,2,3,4,5};
	std::vector<std::string> foo2{"a","b","c","d"};
	
	while(true){
		Time().sleep(200);
		Util().clear();

		foo = test(foo);
		print_r(foo);
		
		println("");

		foo2 = test(foo2);
		print_r(foo2);	
	}
}
