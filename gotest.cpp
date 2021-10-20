#include <download.h>
#include <cpp-lib/parser.hpp>
#include <cpp-lib/io.hpp>
#include <cpp-lib/json.hpp>

using namespace std;

void out(){
	string tmp = "http://worldtimeapi.org/api/timezone/America/Sao_Paulo";
	auto html = download(to<char*>(tmp));
	print(html);
}

main(){	
	out();
}
