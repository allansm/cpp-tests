#include <cpp-lib/util.hpp>
#include <cpp-lib/output.hpp>
#include <cpp-lib/files.h>

#include <vector>
#include <map>
#include <cstring>

using namespace std;

Util util = Util();
Files files = Files();
/*map<string,string> test(string json){
	json = json.substr(0, json.size()-1); 
	json = json.substr(1, json.size());

	map<string,string> tmp;
	
	while(util.has(json,":[")){
		string temp = util.explode(json,":[")[1];
		temp = util.explode(temp,",")[0];

		temp = ":["+temp;
		
		temp = util.replace(temp,",","");

		string last = "";
		for(string n : util.explode(util.explode(json,temp)[0],",")){
			last = n;
		}

		//arr.push_back(last+temp);
		
		json = util.replace(json,last+temp,"");

		tmp[last] = util.replace(temp,":","");
	}
		
	for(string s : util.explode(json,",")){
		string ex = "";
		if(has(s,":{")){
			ex = "{"+util.explode(s,":{")[1];	
		}else{
			if(has(s,"{") && !has(s,"}")){
				s = util.replace(s,"{","");
			}else if(has(s,"}") && !has(s,"{")){
				s = util.replace(s,"}","");	
			}
		}

		string field = util.replace(util.explode(s,":")[0],"\"","");
		field = util.replace(field,"'","");

		string val;
		if(ex == ""){
			val = util.replace(util.explode(s,":")[1],"\"","");
			val = util.replace(val,"'","");
		}else{
			val = ex;
		}

		tmp[field] = val;
	}
	
	return tmp;	
}*/

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
				val = util.replace(val,"\"","");//val.substr(0, val.size()-1); 
				val = util.replace(val,"'","");//val.substr(1, val.size());
				val = util.replace(val,"\n","");

				field = val;

				//println(field);
			}
	
			/*if(tok == ':'){
				field = val;	
			}*/

			if(tok == ','){
				value = val;
			}
			
			if(field != "" && value != ""){
				tmp[field] = value;
				
				tmp["_"] += field+";";

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
//println(val);
		}else{
			buff[n++] = json.at(i);
		}
	}
	
	val = buff;
	//println(val);

	if(tok == ':'){
		field = val;	
	}

	if(tok == ','){
		value = val;
	}
	
	if(field != "" && value != ""){
		tmp[field] = value;
		
		tmp["_"] += field+";";

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

main(){
	//string json = "{'text':'helloworld',\"n\":0,\"son\":{\"a\":1,'message':'helloworld'},'arr':['a','b','c'],\"arr2\":['d','e']}";
	//string json = "{'test'}";
	/*auto tmp = test2(json);
	println(tmp["arr2"]);
	println(tmp["son"]);
	
	auto tmp2 = test2(tmp["son"]);

	println(tmp2["a"]);
	println(tmp2["message"]);

	print_r(test3(tmp["arr"]));
	println("");
	print_r(test3(tmp["arr2"]));*/

	/*string json = util.exec("curl -s http://worldtimeapi.org/api/timezone/America/Sao_Paulo");
	auto tmp = test2(json);
	
	println(tmp["datetime"]);
	println(tmp["unixtime"]);*/
	string json = "";
	bool flag = false;
	for(string n : files.getLines("../test.json")){
		if(flag){
			json+="\n";
		}else{
			flag = true;
		}
		json+=n;
	}

	auto tmp = test2(json);
	println(tmp["_"]);
	println(tmp["msg"]);
	println(tmp["letters"]);
	println(tmp["user"]);
	
	auto tmp2 = test2(tmp["user"]);
	print(tmp2["_"]);
}
