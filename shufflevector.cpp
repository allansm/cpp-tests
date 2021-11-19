#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <allansm/io.hpp>
#include <util.cpp>
#include <time.cpp>

main(){
	while(true){
		Time().sleep(200);
		Util().clear();

		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine e(seed);

		std::vector<int> foo{1,2,3,4,5};
		std::shuffle(foo.begin(), foo.end(), e);

		print_r(foo);	
	}
}
