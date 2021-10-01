#include <map>
#include <iostream>
#include <sstream>
using namespace std;

struct test{
	stringstream ss;

	template<typename T>
	test(T val){
		this->ss << val;
	}

	template<typename T>
	T val(){
		T x;

		this->ss >> x;

		//this->ss << x;
		this->ss.seekg(0);

		return x;
	}	
};

main(){
	test a = test("123");
	
	int val = a.val<int>();
	string txt = a.val<string>();
	float val2 = a.val<float>();
	cout << val+1;

	cout << endl << txt+"b";

	cout << endl << val2+2.5;
}
