#include <cpp-lib/util.hpp>
#include <cpp-lib/output.hpp>

#include <map>
#include <cstring>

using namespace std;

Util util = Util();

map<string,string> test(string json){
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
}

map<string,string> test2(string json){
	string field = "";
	char buff[255];
	int n = 0;
	for(int i = 0; i < json.length();i++){
		buff[n++] = json.at(i);
		string cha;
		if(json.at(i) == ':'){
			field = buff;
			println("field:"+field);	
			n = 0;
			memset(buff,'\0',255);
		}
	}

	map<string,string> tmp;
	
	return tmp;
}

main(){
	string json = "{'text':'helloworld',\"n\":0,\"son\":{\"a\":1},'arr':['a','b','c'],\"arr2\":['d','e']}";

	/*vector<string> arr;
	while(util.has(json,":[")){
		string temp = util.explode(json,":[")[1];
		temp = util.explode(temp,"]")[0];

		temp = ":["+temp+"]";
		string last = "";
		for(string n : util.explode(util.explode(json,temp)[0],",")){
			last = n;
		}

		arr.push_back(last+temp);

		json = util.replace(json,last+temp,"");
	}

	for(string n : arr){
		println(n);
	}*/

	//auto t = test(json);

	//println(t["text"]);
	//println(t["n"]);
	//
	test2(json);
}
