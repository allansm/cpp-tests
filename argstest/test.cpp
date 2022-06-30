#include <allansm/string.hpp>
#include <allansm/io.hpp>
#include <map>

std::map<std::string,std::string> test(int argc, char** argv){
	String argname("");
	String argval("");
	
	std::map<std::string,std::string> arr;
	arr["args"] = "";
	
	for(int i=1;i<argc;i++){
		String arg = (std::string)argv[i];
		
		if(arg.has("--")){
			argname = arg.replace("--","");	
		}else{
			argval = arg;
		}

		if(argname.text != "" && argval.text != ""){
			arr[argname.text] = argval.text;
			arr["args"] += argname.text+";";

			argname = "";
			argval = "";
		}
	}

	return arr;
}

main(int argc, char ** argv){
	auto args = test(argc,argv);
	
	for(auto n : String(args["args"]).split(";")){
		println(n+" "+args[n]);
	}
}
