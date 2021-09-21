#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;
using namespace std;


json getJson(const char* fn){
	ifstream i(fn);
	json j;	
	i >> j;

	return j;
}

main(){	
	//json j = getJson("person.json");

	//cout << j["Anna"]["profession"] << endl;
	
	auto j2 = json::parse(R"({"happy": true, "pi": 3.141})");
	
	cout << j2["pi"] << endl;

	//string test = j.dump();

	cout << test << endl;

	auto j3 = json::parse("{\"message\":\"helloworld\"}");

	cout << j3["message"] << endl;


	json person;
	
	person[0]["name"] = "allan";
	person[0]["lastname"] = "sm";
	
	person[1]["name"] = "unk";
	person[1]["lastname"] = "unk";
	
	cout << person.dump();
}	
