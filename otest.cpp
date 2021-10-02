#include <cpp-lib/output.hpp>
#include <cpp-lib/parser.hpp>
#include <cpp-lib/array.hpp>

using namespace std;

main(){
	Array<string> test;

	test["x"] = "10";
	test["y"] = "2.5";

	println(to<int>(test["x"])+to<float>(test["y"]));

	vector<string> vec{"a","b","c"};

	print_r(vec);
}
