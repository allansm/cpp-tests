#include <download.h>
#include <cpp-lib/parser.hpp>
#include <cpp-lib/io.hpp>
#include <cpp-lib/json.hpp>

using namespace std;
/*struct json_array{
	vector<json_obj> data;

	json_array(string json){	
		json = Util().replace(json,"\t","");
		json = Util().replace(json,"\r\n","");
		json = JsonHandle().removeSpaces(json);

		for(string tmp : JsonHandle().getArray(json)){
			tmp = JsonHandle().removeSpaces(tmp);
			this->data.push_back(json_obj(tmp));
		}
	}

	operator vector<json_obj>(){
		return this->data;
	}
};

using JsonArray = json_array;*/

string removeFormat(string json){
	json = Util().replace(json,"\t","");
	json = Util().replace(json,"\r\n","");
	json = JsonHandle().removeSpaces(json);
	
	return json;
}

vector<json_obj> getArray(string json){
	vector<json_obj> data;

	json = Util().replace(json,"\t","");
	json = Util().replace(json,"\r\n","");
	json = JsonHandle().removeSpaces(json);

	for(string tmp : JsonHandle().getArray(json)){
		tmp = JsonHandle().removeSpaces(tmp);
		data.push_back(json_obj(tmp));
	}

	return data;
}

void out(){
	string tmp = "http://mysafeinfo.com/api/data?list=englishmonarchs&format=json";
	//string tmp = "http://worldtimeapi.org/api/timezone/America/Sao_Paulo";
	string html = download(tmp);
	
	if(html == ""){
		println("D:");
	}else{	

		/*println("--------------------------------------");	
		for(auto json : getArray(html)){	
			println(json.get("ID"));
			println(json.get("Name"));
			println("--------------------------------------");
		}*/
		
		/*println(getArray(html)[0].get("Name"));
		println(getArray(html)[1].get("Name"));
		print(getArray(html)[2].get("Name"));*/

		string test = "{'array':"+removeFormat(html)+"}";

		Json json = Json(test);

		println(json.array("array",0).data);
	}
}

main(){	
	out();
}
