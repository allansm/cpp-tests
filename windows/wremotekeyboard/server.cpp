#include <allansm/socket.hpp>

#include "keyboard.cpp"

#include <allansm/io.hpp>

main(){
	println("starting...");
	Socket().server(54321, [](auto sock){
		while(true){
			std::string recv = Socket().receive(sock, 9);
			
			print("receive:");
			println(recv);
		}
	});
}
