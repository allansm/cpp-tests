#include <allansm/io.hpp>

void test(int* x){
	*x+=10;
}

void test2(bool* x){
	*x=true;
}

void test3(std::string* x){
	*x="Hello";
}

struct test4{
	int* x;
	bool* y;
	std::string* z;
};

class test5{
	public:

	int* x;
	bool* y;
	std::string* z;
};

main(){
	int x = 0;
	bool y = false;
	std::string z = "a";

	test4 xyz = {&x, &y, &z};
	test5 zyx;
	
	zyx.x = &x;
	zyx.y = &y;
	zyx.z = &z;

	*zyx.z+="b";
	
	*xyz.x = 5;
	*xyz.y = false;
	*xyz.z += "c";
	
	*zyx.x+=12;

	test(&x);
	test2(&y);
	test3(&z);
	
	x-=20;

	std::string* a = &z;
	
	auto b = [a](){
		*a+="World";
	};
	
	b();

	z+="!!!";

	auto c = [x, y, z, xyz, zyx](){
		if(*zyx.y && *xyz.y && y){
			std::cout << x << " " << *xyz.x << " " << *zyx.x << "\n";
			std::cout << z << " " << *xyz.z << " " << *zyx.z;
		}
	};

	c();
}
