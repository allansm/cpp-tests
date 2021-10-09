#include <cpp-lib/io.hpp>
#include <cpp-lib/json.hpp>

using namespace std;

main(){
	auto test = Json("{ 'a' : 'b' , 'b' : 'hello world', 'c' : 2 }");
		
	println(test.get("b"));
	println(test.get<int>("c")+1);
	string tes = "hello world";	
	println(unknown(tes).get());

	int n = unknown(2).get<int>();
	println(unknown(2).get<int>()+unknown(2.25).get<float>());
}
