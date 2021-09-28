#include <cpp-lib/util.hpp>
#include <cpp-lib/output.hpp>

#include <map>

using namespace std;

Util util = Util();

map<string,string> test(string json){
	json = json.substr(0, json.size()-1); 
	json = json.substr(1, json.size());

	map<string,string> tmp;

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

main(){
	string json = "{'text':'helloworld',\"n\":0,\"son\":{\"a\":1},'arr':['a','b','c']}";
	
	/*json = json.substr(0, json.size()-1); 
	json = json.substr(1, json.size());

	map<string,string> tmp;

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
	}*/
	
	auto tmp = test(json);

	println(tmp["text"]);
	println(tmp["n"]);
	println(tmp["son"]);
	
	println("");

	auto tmp2 = test(tmp["son"]);

	println("a:"+tmp2["a"]);
}
