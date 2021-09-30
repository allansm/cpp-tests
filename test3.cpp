#include <cpp-lib/util.hpp>
#include <cpp-lib/output.hpp>
#include <cpp-lib/files.h>

#include <vector>
#include <map>
#include <cstring>

using namespace std;

Util util = Util();
Files files = Files();

map<string,string> test2(string json){
	json = json.substr(0, json.size()-1); 
	json = json.substr(1, json.size());

	string val = "";
	char buff[255];
	int n = 0;
	char tok = ':';
	bool flag = false;
	
	string field = "";
	string value = "";

	map<string,string> tmp;
	
	tmp["_"] = "";

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
				tmp[field] = value;
				
				if(tmp["_"] != ""){
					tmp["_"] += ";";
				}

				tmp["_"] +=field;

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
		tmp[field] = value;
		
		if(tmp["_"] != ""){
			tmp["_"] += ";";
		}

		tmp["_"] +=field;

		field = "";
		value = "";
	}
	
	return tmp;
}

vector<string> test3(string jsonArray){
	jsonArray = jsonArray.substr(0, jsonArray.size()-1); 
	jsonArray = jsonArray.substr(1, jsonArray.size());
	
	return util.explode(jsonArray,",");
}

string test4(map<string,string> json){
	bool flag = false;

	string tmp = "{";
	for(string n : util.explode(json["_"],";")){
		if(flag){
			tmp+=",";
		}

		tmp+= "\""+n+"\":"+json[n];

		if(!flag){
			flag = true;
		}
	}

	tmp += "}";
	
	return tmp;
}

main(){
	//string json = "{'text':'helloworld',\"n\":0,\"son\":{\"a\":1,'message':'helloworld'},'arr':['a','b','c'],\"arr2\":['d','e']}";	
		
	string json = files.readFile("../test.json");
	
	//println(json+"\n");

	auto tmp = test2(json);
	
	auto fields = util.explode(tmp["_"],";");

	/*println(fields[0]+":"+tmp["msg"]);
	println(fields[1]+":"+tmp["letters"]);
	println(fields[2]+":"+tmp["user"]);
	
	println("");	
	
	print_r(test3(tmp["letters"]));

	println("");*/

	auto user = test2(tmp["user"]);
	
	println(test4(tmp));

	//auto fd = util.explode(user["_"],";");

	/*println(fd[0]+":"+user["name"]);
	println(fd[1]+":"+user["username"]);	*/
}
