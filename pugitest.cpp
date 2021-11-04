#define useNode

#include <cpp-lib/dependent/pugi.hpp>

class XmlDoc{
	public:
		pugi::xml_document data;

		XmlDoc(std::string fn){
			this->data.load_file(fn.c_str());
		}

		XmlNode root(){
			return XmlNode(this->data.root());
		}
	
		operator XmlNode(){
			return this->root();
		}
};

/*pugi::xml_node XmlDoc(std::string fn){
	pugi::xml_document doc;
	doc.load_file(fn.c_str());

	return doc;
}*/

/*XmlNode test(std::string fn){
	return rootNode(fn);
}*/


main(){	
	//auto doc = XmlDoc("test.xml");
	//pugi::xml_node tmp = doc.root();	
	auto d = XmlDoc("test.xml");
	node n = d;//d.root();//node(d.data.root());

	int x = n.get("obj").get("x");
	int y = n.get("obj").get("y");
	
	std::string name = n.get("obj").var("name");
	int n1 = n.get("obj").var("n");
	println(x+y);

	println(name+" ");
	println(n1);		
	

	//node n2 = node("test.xml");
	float x1 = n[0].get("x");
	float x2 = n[1].get("x");

	float y1 = n[0].get("y");
	float y2 = n[1].get("y");

	println(x1+x2);
	println(y1+y2);
	
	for(auto nd : n.nodes()){
		println(nd.name);
	}
	
	for(auto att : n[0].attributes()){
		std::cout << att.name() << ":" << att.value() << std::endl;
	}

	print<std::string>(n.get("obj")[0]);	

	/*auto test1 = rootNode("test.xml");
	std::cout << test1.child("obj").name();*/
	//auto test1 = test("test.xml");

	//println(test1.name);
}
