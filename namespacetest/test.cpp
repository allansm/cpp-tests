#include <allansm/io.hpp>

namespace allansm{
	std::string message = "";

	void hello(){
		println(message);
	}
}

void test(){
	using namespace allansm;
	
	hello();
}

main(){
	allansm::message = "helloworld";
	test();	
}
