#define useNode

#include <cpp-lib/dependent/pugi.hpp>
#include <cpp-lib/io.hpp>

main(){	
	auto doc = XmlDoc("test.xml");
	
	int x = doc["obj"][0]["x"];
	int y = doc["obj"][0]["y"];
	
	float x2 = doc["obj"][1]["x"];
	float y2 = doc["obj"][1]["y"];
	
	std::string msg = doc["obj"][1]["msg"];
	std::string msg2 = doc["thing"][0]["msg"];

	println(x+y);
	println(x2+y2);
	println(msg+msg2);
	

	auto X = doc.find("x");
	for(node n : X){
		std::string value = n;
		println(n.name+" "+value);		
	}

	auto Y = doc.find("y");
	for(node n : Y){
		std::string value = n;
		println(n.name+" "+value);		
	}

	auto MSG = doc.find("msg");
	for(node n : MSG){
		std::string value = n;
		println(n.name+" "+value);		
	}	
}
