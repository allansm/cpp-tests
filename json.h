#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;
using namespace std;

class Json{
	public:
		Json();

		json getJson(const char* fn);
		string toString(json jsn);
		json toJson(string jsn);
};

Json::Json(){}

json Json::getJson(const char* fn){
	ifstream i(fn);
	json j;	
	i >> j;

	return j;
}

string Json::toString(json jsn){
	return jsn.dump();
}

json Json::toJson(string jsn){
	return json::parse(jsn);
}	
