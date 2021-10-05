#include <cpp-lib/json.hpp>

main(){	
	Files files = Files();

	string json = files.readFile("../test.json");
	
	Json t = Json(json);
	Json values = Json(t.get<string>("values"));	
	println(t.data+"\n");

	println(values.get<int>("x")+values.get<float>("y"));	
	
	println("\n"+values.toString());
	
	println("");

	print_r(t.array<string>("letters"));
	
	println("");

	auto numbers = t.array<int>("numbers");

	string txt = t.get<string>("numbers",1)+"+"+t.get<string>("numbers",4);

	txt += "="+to<string>(numbers[1]+numbers[4]); 
	println(txt);	
}
