#include <pugixml.hpp>

#include <cpp-lib/io.hpp>
#include <cpp-lib/util.hpp>
#include <cpp-lib/parser.hpp>

pugi::xml_document _x_m_l;
struct XmlNode{
	pugi::xml_node data;
	std::string name;
	undefined value;
	
	XmlNode(pugi::xml_node data){
		this->data = data;
		this->value = unknown(data.child_value());
		this->name = data.name();
	}

	XmlNode(std::string fn){	
		_x_m_l.load_file(fn.c_str());
		this->data = _x_m_l.root();
		this->value = unknown(data.child_value());	
		this->name = data.name();
	}
	
	XmlNode get(std::string name){
		return XmlNode(this->data.child(name.c_str()));
	}	

	
	
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
	
	XmlNode operator[](const int& i){
		int c = 0;
		for(auto n : this->data){
			if(c++ == i){
				return XmlNode(n);
			}
		}

		return this->data;
	}
	
	template <typename T>
	undefined operator+(const T&a){
		auto tmp = this->value;
		tmp = unknown(tmp.get<T>()+a);

		return tmp;
	}
	
	template <typename T>
	T operator+=(const T&a){
		auto tmp = this->value;
		tmp = unknown(tmp.get<T>()+a);

		return tmp;
	}
		

	/*template <typename T>
	T operator+=(const T& b,const XmlNode& a){
		auto tmp = this->value;
		tmp = unknown(b+a.value.get<T>());

		return tmp.get<T>();
	}*/

	template <typename T>
	operator T(){
		return this->value;
	}

	/*operator int(){
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
	}*/
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
	

	node n2 = node("test.xml");
	float res = n[0].get("x");
	res +=(float)n[1].get("x");
	println(res);	
}
