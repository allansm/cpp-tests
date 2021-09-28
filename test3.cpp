#include <cpp-lib/util.hpp>
#include <cpp-lib/output.hpp>
//#include <vector>

using namespace std;

Util util = Util();

main(){
	string json = "{\"text\":\"helloworld\",\"n\":0}";
	
	for(string s : util.explode(json,",")){
		if(has(s,"{") && !has(s,"}")){
			s = util.replace(s,"{","");
		}else if(has(s,"}") && !has(s,"{")){
			s = util.replace(s,"}","");	
		}
		
		string field = util.replace(util.explode(s,":")[0],"\"","");
		string val = util.explode(s,":")[1];	

		println(field+":"+val);
	}
}
