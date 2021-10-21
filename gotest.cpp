#include <download.h>
#include <cpp-lib/parser.hpp>
#include <cpp-lib/io.hpp>
#include <cpp-lib/json.hpp>

using namespace std;

void out(){
	string tmp = "http://worldtimeapi.org/api/timezone/America/Sao_Paulo";
	string html = download(tmp);
	Json json = Json(html);

	for(auto s:json.fields){
		println(s+":"+json.get(s));
	}
}

main(){	
	out();
}
