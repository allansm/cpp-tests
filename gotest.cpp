#include <download.h>
#include <cpp-lib/parser.hpp>
#include <cpp-lib/io.hpp>
#include <cpp-lib/json.hpp>

using namespace std;
struct json_array{
	vector<json_obj> data;

	json_array(string json){
		//json = JsonHandle().removeSpaces(json);
		println(json);
		for(string tmp : JsonHandle().getArray(json)){
			tmp = JsonHandle().removeSpaces(tmp);
			this->data.push_back(json_obj(tmp));
		}
	}	
};

void out(){
	string tmp = "http://mysafeinfo.com/api/data?list=englishmonarchs&format=json";
	//string tmp = "http://worldtimeapi.org/api/timezone/America/Sao_Paulo";
	string html = download(tmp);
	
	if(html == ""){
		println("D:");
	}else{
		auto test = json_array(html);
		
		for(auto json : test.data){
			/*for(auto s:json.fields){
				println(s+":"+json.get(s));
			}*/
			println(json.data);	
		}

		/*Json json = Json(html);

		for(auto s:json.fields){
			println(s+":"+json.get(s));
		}*/
	}
}

main(){	
	out();
}
