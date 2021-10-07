#include <cpp-lib/output.hpp>
#include <cpp-lib/json.hpp>
#include <cpp-lib/files.hpp>

Util util = Util();

main(){
	string json = Files().readFile("../test.json");

	Json test = Json(json);
	
	Json values1 = test.array("values",0);
	Json values2 = test.array("values",1);
	
	println(test.toString());

	println(values1.get<int>("x")+test.get<float>("values2","y"));	
	
	print_r(test.fields);

	Json test2 = Json(test.toString());

	println(test2.object("user").get<string>("username"));

	print_r(test.array<string>("numbers"));
}
