#include <cpp-lib/parser.hpp>
#include <cpp-lib/output.hpp>
#include <cpp-lib/array.hpp>

using namespace std;

main(){
	Array<undefined> arr;
	
	arr["a"] = unknown(255);
	arr["b"] = unknown(2.5);
	
	arr["val"] = unknown(arr["a"].get<int>()+arr["b"].get<float>());

	println("val:"+arr["val"].get<string>());
}
