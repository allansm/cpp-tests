#include <iostream>

#include <utility>
#include <test4.cpp>
using namespace std;

struct arr{
	Array<string> _string;
	Array<int> _int;
	Array<float> _float;

	template<typename T> 
	T get(Array<T> x,string n){
		return x[n];
	}
};

//typedef map<string,string> arr;

main(){	
	//Array<string> test;

	//test["name"] = "allansm";
	
	arr test;
	
	test._string["name"] = "allan";

	cout << test.get(test._string,"name");
}
