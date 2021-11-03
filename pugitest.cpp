#include <pugixml.hpp>
#include <cpp-lib/io.hpp>
#include <cpp-lib/util.hpp>
#include <cpp-lib/parser.hpp>

using Xml = pugi::xml_document;
using XmlNode = pugi::xml_node;

/*std::string iXml(std::string pattern,Xml doc){
	
}*/
struct node{
	pugi::xml_document doc;
	pugi::xml_node data;
	undefined value;
	
	node(pugi::xml_node data){
		this->data = data;
		this->value = unknown(data.child_value());
	}

	node(std::string fn){
		this->doc.load_file(fn.c_str());
		this->data = this->doc.root();
		this->value = unknown(data.child_value());	
	}
	
	node get(std::string name){
		return node(this->data.child(name.c_str()));
	}

	undefined var(std::string name){
		return unknown(this->data.attribute(name.c_str()).value());
	}

	operator int(){
		return this->value;
	}

	operator std::string(){
		return this->value;
	}

	operator float(){
		return this->value;
	}

	operator bool(){
		return this->value;
	}		

};
/*struct test{
	pugi::xml_document doc;

	test(std::string fn){
		this->doc.load_file(fn.c_str());	
	}

	node get(std::string n){
		return node
	}
};*/

main(){
	Xml doc;
	doc.load_file("test.xml");
	
	/*auto obj = doc.child("obj");
	
	int x = unknown(obj.child_value("x"));	
	int y = unknown(obj.child_value("y"));
	
	println(x+y);
	println(obj.child_value("msg"));*/
	node n = node("test.xml");

	int x = n.get("obj").get("x");
	int y = n.get("obj").get("y");
	
	std::string name = n.get("obj").var("name");
	int n1 = n.get("obj").var("n");
	println(x+y);

	println(name+" ");
	print(n1);
}
