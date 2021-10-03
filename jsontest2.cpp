#include <cpp-lib/util.hpp>
#include <cpp-lib/output.hpp>
#include <cpp-lib/files.hpp>
#include <cpp-lib/array.hpp>
#include <cpp-lib/parser.hpp>

#include <cstring>

using namespace std;

Util util = Util();
Files files = Files();

class JsonHandle{
	public:
	bool x(string txt,char cha){
		if(txt[0] == cha && txt[txt.size()-1] == cha){
			return true;
		}

		return false;
	}

	string unquote(string txt){
		if(x(txt,'"')){
			txt = txt.substr(0, txt.size()-1); 
			txt = txt.substr(1, txt.size());
		}

		return txt;
	}

	Array<undefined> getJson(string json){
		json = json.substr(0, json.size()-1); 
		json = json.substr(1, json.size());

		string val = "";
		char buff[255];
		int n = 0;
		char tok = ':';
		bool flag = false;
		
		string field = "";
		string value = "";

		Array<undefined> tmp;
		
		tmp["_"] = unknown("");

		for(int i = 0; i < json.length();i++){
			
			if(json.at(i) == '['){
				flag = true;
			}
			if(json.at(i) == ']'){
				flag = false;
			}

			if(json.at(i) == '{'){
				flag = true;
			}
			if(json.at(i) == '}'){
				flag = false;
			}

			if(json.at(i) == tok && !flag){
				val = buff;
				

				if(tok == ':'){
					val = util.replace(val,"\t","");
					val = util.replace(val,"\"","");
					val = util.replace(val,"'","");
					val = util.replace(val,"\n","");

					field = val;
				}

				if(tok == ','){
					if(has(val,"{") && has(val,"}") || has(val,"[") && has(val,"]")){
						val = util.replace(val,"\t","");
						val = util.replace(val,"\n","");
					}
					value = val;
				}
				
				if(field != "" && value != ""){
					tmp[field] = unknown(unquote(value));	

					if(tmp["_"].get<string>() != ""){
						tmp["_"] = unknown(tmp["_"].get<string>()+";");
					}

					tmp["_"] = unknown(tmp["_"].get<string>()+field);

					field = "";
					value = ""; 
				}

				n = 0;
				memset(buff,'\0',255);

				if(tok == ':'){
					tok = ',';
				}else if(tok == ','){
					tok = ':';
				}
			}else{
				buff[n++] = json.at(i);
			}
		}
		
		val = buff;
		memset(buff,'\0',255);

		if(tok == ':'){
			val = util.replace(val,"\t","");
			val = util.replace(val,"\"","");
			val = util.replace(val,"'","");
			val = util.replace(val,"\n","");

			field = val;

		}

		if(tok == ','){
			if(has(val,"{") && has(val,"}") || has(val,"[") && has(val,"]")){
				val = util.replace(val,"\t","");
				val = util.replace(val,"\n","");
			}
			value = val;
		}
		
		if(field != "" && value != ""){
			tmp[field] = unknown(unquote(value));
			
			if(tmp["_"].get<string>() != ""){
				tmp["_"] = unknown(tmp["_"].get<string>()+";");
			}

			tmp["_"] = unknown(tmp["_"].get<string>()+field);

			field = "";
			value = "";
		}
		
		return tmp;
	}

	vector<string> getArray(string jsonArray){
		jsonArray = jsonArray.substr(0, jsonArray.size()-1); 
		jsonArray = jsonArray.substr(1, jsonArray.size());
		
		return util.explode(jsonArray,",");
	}

	string toString(Array<undefined> json){
		bool flag = false;

		string tmp = "{";
		for(string n : util.explode(json["_"].get<string>(),";")){
			if(flag){
				tmp+=",";
			}

			tmp+= "\""+n+"\":\""+json[n].get<string>()+"\"";

			if(!flag){
				flag = true;
			}
		}

		tmp += "}";
		
		return tmp;
	}
};

struct json_field{
	string data;
	undefined unk;
	Array<undefined> obj;
		
	/*json_field(string x){
		this->data = x;
		this->unk = unknown(data);

		string txt = this->unk.data;
		if(txt[0] == '{' && txt[txt.size()-1] == '}'){	
			this->obj = JsonHandle().getJson(txt);	
		}
	}*/

	template<typename T>
	T get(){
		return this->unk.get<T>();
	}

	template<typename T>
	T get(string field){
		return this->obj[field].get<T>();
	}

	//template<typename T>
	//json_field create(string data){
	//	return {data};//to<std::string>(data)};
	//}
};

json_field jsf(string data){
	/*if(data[0] == '{' && data[data.size()-1] == '}'){
		auto tmp = JsonHandle().getJson(data);
		auto unk = unknown(data);
		return {data,unk,tmp};	
	}else{
		return {data};
	}*/
	return {data};
}

struct test{
	Array<json_field> obj;

	test(string x){
		json_field json = json_field(x);

		for(string s:util.explode(json.get<string>("_"),";")){
			//json_field tmp = json_field(json.obj[s].data);
			//json_field tmp2 = jsf(tmp.data);//{tmp.data};
			//tmp2.obj = tmp.obj;
			this->obj[s] = jsf("{}");//tmp2;
			//this->obj[s] = json_field("").create(json.get<string>(s));
			//}
		}
	}

	//template<typename T>
	//T get(string name){
	//	return this->obj[name].data;
	//}	
};

/*struct test{
	Array<json_field>	
};*/

using Json = Array<undefined>;

main(){
	/*
	string json = files.readFile("../test.json");
		
	Json tmp = getJson(json);
	
	auto fields = util.explode(tmp["_"].get<string>(),";");
	
	println("");

	for(string f:fields){
		println("json['"+f+"'] = "+tmp[f].get<string>());
	}

	println("\nletters(\n");
	print_r(getArray(tmp["letters"].get<string>()));
	println("\n)");
	
	Json user = getJson(tmp["user"].get<string>());

	println("\nparsed:"+toString(tmp));

	Json values = getJson(tmp["values"].get<string>());
				
	print("\nresult:");	
	println(values["x"].get<int>() + values["y"].get<float>());
	*/
	string json = files.readFile("../test.json");
	//println(json);
	json_field tst = json_field("{'msg':'helloworld','test':{'a':'b'}}");
	
	json_field js = json_field(json);//JsonHandle().getJson(files.readFile("../test.json"));
	//Array<undefined> js;
       	//js = JsonHandle().getJson(json);
	//print(js.get<string>("_"));//JsonHandle().toString(js));
	
	//println(tst.get<string>("test"));
	//
	test t = test(tst.data);
	//json_field tes = json_field("aaaa");
	//println(t.obj["test"].data);
}
