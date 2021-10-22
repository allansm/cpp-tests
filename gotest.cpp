#include <download.h>
#include <cpp-lib/parser.hpp>
#include <cpp-lib/io.hpp>
#include <cpp-lib/json.hpp>

using namespace std;

void out(){
	string tmp = "http://mysafeinfo.com/api/data?list=englishmonarchs&format=json";
	//string tmp = "http://worldtimeapi.org/api/timezone/America/Sao_Paulo";
	string html = download(tmp);
	
	if(html == ""){
		println("D:");
	}else{	
		for(auto json : JsonArray(html)){	
			println("--------------------------------------");
			for(auto f:json.fields){
				println(f+":"+json.get(f));
			}
		}
		print("--------------------------------------");	
	}
}

main(){	
	out();
}
