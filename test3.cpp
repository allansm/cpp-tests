#include <cpp-lib/io.hpp>

using namespace std;

struct integer{
	int x;		

	integer operator=(const int& a){
		this->x =a;
		return *this;
	}	

	operator int(){
		return (int)this->x;
	}
};

main(){
	integer t;
	t = 10;
	integer t2;
	t2 = t+5;
		
	print("t:");
	println(t);
	print("t2:");
	println(t2);
	int n = t+t2;
	print("n:");
	println(n);

	float test;
       	test = 2;
	println(test);
}
