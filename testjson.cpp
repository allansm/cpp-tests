#include <cpp-lib/output.hpp>
#include <cpp-lib/json.hpp>
#include <cpp-lib/files.hpp>

Util util = Util();

main(){
	//string tmp = util.exec("curl -s https://api.mangadex.org/manga?title="+util.input("title:"));
	
	//tmp = Util().replace(tmp,"\\u","");	
	string son = "{'a':'b','c':'d','e':[{'msg':'hello',numbers:['1','2']},{'a':['3','4']}],'f':[1,2],'g':{'h':'i'}}";
	
	/*Json t = Json(tmp);
	Json t2 = Json(t.get<string>("data",0));
	
	println(t2.get<string>("id"));

	println(t2.get<string>("type"));

	println(t2.object("attributes").array("tags",0).object("attributes").get<string>("name"));
	*/

	Json j  = Json(son);
	
	string n1 = j.array("e",0).get<string>("numbers",0);
	string n2 = j.array("e",0).get<string>("numbers",1); 
	println(to<int>(n1)+to<int>(n2));
}
