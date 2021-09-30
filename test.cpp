#include <iostream>
#include <map>

using namespace std;

template<typename T>
struct dat{
	T test;
};

main(){
	dat<string> tes;
	tes.test = "helloworld";

	cout << tes.test;
/*
	map<string,dat> test;
	test["val"] = t;

	cout << test["val"].test;*/
}

