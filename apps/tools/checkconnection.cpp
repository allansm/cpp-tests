#include <optimizedclass/util.h>

main(){
	while(true){
		string headers = Util().exec("curl -s -I www.google.com");
	
		if(Util().has(headers,"200") && Util().has(headers,"OK")){
			Util().println("connection ok");
			break;
		}else{
			Util().println("has no connection");
		}
	}
}
