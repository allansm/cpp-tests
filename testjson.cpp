#include <cpp-lib/output.hpp>
#include <cpp-lib/json.hpp>
#include <cpp-lib/files.hpp>

Util util = Util();

main(){
	string tmp = util.exec("curl -s https://api.mangadex.org/manga?title="+util.input("title:"));
	
	//tmp = Util().replace(tmp,"\\u","");	
	string son = "{'a':'b','c':'d','e':[{'msg':'hello',['1','2']},{'a':['3','4']}],'f':[1,2],'g':{'h':'i'}}";
	
	Json t = Json(tmp);
	println(t.get<string>("data",0));
	
	//Json t2 = Json(son);

	//println(t2.get<int>("f",0)+t2.get<int>("f",1));
}
