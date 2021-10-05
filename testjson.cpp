//#include <cpp-lib/parser.hpp>
//#include <cpp-lib/util.hpp>
#include <cpp-lib/output.hpp>
#include <cpp-lib/json.hpp>

Util util = Util();

main(){
	string tmp = util.exec("curl -s https://api.mangadex.org/manga?title="+util.input("title:"));

	//Json json = Json("{'a':[{'a':'b'},{'b':'c'}]}");

	//auto tmp2 = JsonHandle().getJson("{'a':[{'a':'b'}]}");
	//
	print_r(util.explode(tmp,","));
	Json json = Json(tmp);
	//print_r(json.array<string>("a"));
	//
	print(json.data);
}
