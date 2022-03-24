#include <allansm/socket.hpp>

#include "keyboard.cpp"

#include <allansm/io.hpp>
#include <allansm/parser.hpp>
#include <allansm/file.hpp>

main(int argc, char** argv){
	int port = 54321;
	
	File config(".config");

	if(config.lines()[1].length() >=4) port = to<int>(config.lines()[1]);
	
	if(argc == 2){
		port = to<int>(argv[1]);
	}

	print("starting on port:");
	println(port);
	Socket().server(port, [](auto sock){
		while(true){
			std::string recv = Socket().receive(sock, 2);
			
			if(recv.at(0) == 'H'){
				down(recv.at(1));
			}else{
				up(recv.at(1));
			}

			print(recv);
			print(" ");

			Sleep(1);
		}
	});
}
