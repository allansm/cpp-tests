#define useNode

#include <cpp-lib/dependent/pugi.hpp>
#include <cpp-lib/io.hpp>

void old(){
	auto d = XmlDoc("test.xml");
	node n = d;

	int x = n.get("obj").get("x");
	int y = n.get("obj").get("y");
	
	std::string name = n.get("obj").var("name");
	int n1 = n.get("obj").var("n");
	println(x+y);

	println(name+" ");
	println(n1);		
	
	float x1 = n[0].get("x");
	float x2 = n[1].get("x");

	float y1 = n[0].get("y");
	float y2 = n[1].get("y");

	println(x1+x2);
	println(y1+y2);
	
	for(auto nd : n.nodes("thing")){
		println(nd.name);
	}
	
	for(auto att : n[0].attributes()){
		std::cout << att.name() << ":" << att.value() << std::endl;
	}

	println<std::string>(n.get("obj")[0]);

			
	std::string a = n.nodes("thing")[0].get("otherthing");
	std::string b = n.nodes("thing")[1].get("otherthing");

	println(a);
	println(b);
}

undefined test(std::string name,int i){
	auto doc = XmlDoc("test.xml");
	node root = doc;
	return root.nodes("obj")[i].get(name); 	
}

vector<node> iterate(std::string name,vector<node> nodes){
	vector<node> pass;
	vector<node> ret;
	vector<node> allret;
	vector<node> all;
	
	for(node n : nodes){
		if(n.name == name){
			pass.push_back(n);
		}

		ret = iterate(name,n.nodes());
		
		for(auto n : ret){
			allret.push_back(n);
		}
	}
	
	for(auto n : pass){
		all.push_back(n);
	}

	for(auto n : allret){
		all.push_back(n);
	}

	return all;
}

void test(std::string name){
	auto doc = XmlDoc("test.xml");
	node root = doc;
	
	for(node n : root.nodes()){
		for(node x : n.nodes()){
			if(x.name == name){
				std::string val = x;
				println(x.name+" "+val);
			}
		}	
	}
}

main(){	
	//float x = test("x",1);
	//int y = test("y",0);	
	//println(x+y);
	//test("x");
	
	auto doc = XmlDoc("test.xml");
	//node no = doc;
	node a = doc["obj"][(std::string)"x"];
	println<std::string>(a);

	auto x = doc.root.find("x");//iterate("msg",no.nodes());
	for(node n : x){
		std::string value = (std::string)n.value;
		println(n.name+" "+value);		
	}
}
