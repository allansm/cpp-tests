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

string toString(json jsn){
	return jsn.dump();
}

json toJson(string jsn){
	return json::parse(jsn);
}

main(){		
	json person = getJson("person.json");
	
	cout << person["user"] << endl;
	cout << toString(person);

}	
