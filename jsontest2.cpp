#include <cpp-lib/json.hpp>

main(){
	
	string json = files.readFile("../test.json");
	
	test t = test(json);
	test values = test(t.get<string>("values"));	
	println(t.data);

	println(values.get<int>("x")+values.get<float>("y"));	
	
	println(values.toString());

	println(t.get<string>("letters",0));
	println(t.get<string>("letters",1));
	println(t.get<string>("letters",2));
}
