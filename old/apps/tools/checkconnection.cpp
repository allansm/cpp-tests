#include <cpp-lib/util.hpp>
#include <cpp-lib/io.hpp>
#include <cpp-lib/time.hpp>

main(int argc,char *argv[]){
	string tmp = Time().getCurrent();

	while(true){
		string headers = Util().exec("curl -s -I www.google.com");
	
		if(Util().has(headers,"200") && Util().has(headers,"OK")){
			println("connection ok");
			break;
		}else{
			Util().clear();
			println("has no connection");
		}

		Time().sleep(100);
	}
	
	println(tmp+" >> "+Time().getCurrent());

	system(argv[1]);
}
