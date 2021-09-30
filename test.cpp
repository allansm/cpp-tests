#include <iostream>
#include <map>
#include <utility>

using namespace std;

template<typename T>
using Array = map<string,T>;
/*struct Array{
	typedef map<string,T> test;		
};*/

struct arr{
	map<string,string> _string;
	map<string,int> _int;
	map<string,float> _float;
};

//typedef map<string,string> arr;

main(){
	//typedef Array::test test2;
	
	Array<string> test;

	test["name"] = "allansm";

	cout << test["name"];
}
