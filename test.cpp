#include <iostream>
#include <map>
#include <any>

using namespace std;

//template<typename T>
/*map<string,any> test(){
	map<string,any> tmp;

	tmp["val"] = 2;
	tmp["txt"] = "helloworld";

	return tmp;
}*/

/*T test(T x){
	return x+y;
}*/

struct aa{
	T val;	
};

main(){
	//any x = 2;
	//
	std::any test;
	test = "helloworld";

	cout << test;

	//cout << x.type().name();
	/*dat<string> tes;
	tes.test = "helloworld";
	*/
	/*aa<int> a;
	a.val = 2;

	map<string,aa<string>> ta;

	ta["val"] = a;*/
	
//	map<string,any> arr = test();

/*
	map<string,dat> test;
	test["val"] = t;

	cout << test["val"].test;*/
}

