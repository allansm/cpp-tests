#include <cpp-lib/io.hpp>
#include <cpp-lib/json.hpp>
#include <cpp-lib/files.hpp>

using namespace std;

main(){
	Json json = Json("test.json");

	println(json.get("msg"));
	print_r(json.array<string>("letters"));

	println(json.object("user").get("name")+" "+json.object("user").get("username"));
	
	println(json.array("values",0).get<int>("x")+json.array("values",1).get<float>("y"));
	println(json.array("values",0).get<float>("y")+json.array("values",1).get<int>("x"));

	println(json.object("values2").get<int>("x")+json.object("values2").get<float>("y"));

	println("");	
	println(json.get<int>("numbers",0)+json.get<int>("numbers",1));
	println(json.get<int>("numbers",2)+json.get<int>("numbers",3));
	println(json.get<int>("numbers",4)+json.get<int>("numbers",4));
	
	auto n = unknown(10.2);

	println("n:"+n.get());
	
	n = unknown(n.get<float>()+2);

	println("n+2:"+n.get());

	println(Json("{'test':'works :D'}").get("test"));
}
