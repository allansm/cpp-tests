#include <cpp-lib/parser.hpp>
#include <cpp-lib/output.hpp>
#include <cpp-lib/array.hpp>

using namespace std;

template<typename T>
undefined unk(T x){
	return undefined().get(x);
}

Array<undefined> test(){
	Array<undefined> arr;
	
	arr["x"] = unk(2);
	arr["y"] = unk("2.25");
	
	return arr;
}

template<typename T>
T test2(string name){
	auto arr = test();
	
	return arr[name].get<T>();
}


struct test{
	test(){}

	int operator()() const{
		return 2;
	}
};

main(){	
	println(test2<int>("x")+test2<float>("y"));
	
	test t;

	int val = t();

	print(val);
}
