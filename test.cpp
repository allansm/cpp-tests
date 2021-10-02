//#include <cpp-lib/parser.hpp>
//#include <cpp-lib/output.hpp>
//#include <cpp-lib/array.hpp>

using namespace std;

struct undefined{
	string val;

	template<typename T>
	T get(){
		return to<T>(this->val);
	}

	template<typename T>
	undefined get(T val){
		return {to<string>(val)};
	}
};

main(){
	Array<undefined> arr;
	
	arr["x"] = undefined().get(2);
	arr["y"] = undefined().get("2.25");
	
	print(arr["x"].get<int>()+arr["y"].get<float>());
}
