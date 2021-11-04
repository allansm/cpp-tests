#include <pugixml.hpp>

#include <cpp-lib/io.hpp>
#include <cpp-lib/util.hpp>
#include <cpp-lib/parser.hpp>

struct XmlNode{
	pugi::xml_document doc;
	pugi::xml_node data;
	std::string name;
	undefined value;
	
	XmlNode(pugi::xml_node data){
		this->data = data;
		this->value = unknown(data.child_value());
		this->name = data.name();
	}

	XmlNode(std::string fn){
		this->doc.load_file(fn.c_str());
		this->data = this->doc.root();
		this->value = unknown(data.child_value());	
		this->name = data.name();
	}
	
	XmlNode get(std::string name){
		return XmlNode(this->data.child(name.c_str()));
	}

	/*XmlNode get(std::string name,int index){
		int i = 0;
		for(auto n : this->data.child(name.c_str())){
			if(i++ == index){
				return XmlNode(n);
			}
		}

		return this->get(name);
	}*/

	XmlNode operator[](const int& i){
		int c = 0;
		for(auto n : this->data){
			if(c++ == i){
				//println(n.name());
				return XmlNode(n);
			}
		}

		return this->data;
	}
	
	//template <typename T>
	vector<XmlNode> nodes(){
		vector<XmlNode> tmp;
		
		for(auto n : this->data){
			tmp.push_back(XmlNode(n));
		}

		return tmp;
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

#define useNode

#ifdef useNode
using node = XmlNode;
#endif

main(){		
	node n = node("test.xml");

	int x = n.get("obj").get("x");
	int y = n.get("obj").get("y");
	
	std::string name = n.get("obj").var("name");
	int n1 = n.get("obj").var("n");
	println(x+y);

	println(name+" ");
	println(n1);
	
	
	//float fx = n[1].get("x");
	//auto test = n.get("obj").data;
	//println(test[1].child_value("x"));
	//float fx = node().get("x");
	//println(fx);
	/*for(auto nd : n[1].nodes()){
		//std::string value = x;
		//println(x.name+" "+value);
		std::string nm = nd.data.name();
		std::string vl = nd;
		println(nm+" "+vl);
	}*/	
}
