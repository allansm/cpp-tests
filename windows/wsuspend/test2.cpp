#include <allansm/mswindow.hpp>
#include <allansm/io.hpp>

main(int argc,char ** argv){
	std::string action = argv[1];
	std::string program = argv[2];

	if(action == "suspend"){
		print("suspending:");
		println(program);
		auto proc = MsWindow(program);

		proc.suspend();	
	}else if(action == "resume"){
		print("resuming:");
		println(program);
		
		auto proc = MsWindow(program);

		proc.resume();		
	}
}
