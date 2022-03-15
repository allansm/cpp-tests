#include <allansm/socket.hpp>

#include "keyboard.cpp"

#include <allansm/io.hpp>

main(){
	println("starting...");
	Socket().server(54321, [](auto sock){
		while(true){
			std::string recv = Socket().receive(sock, 2);
			
			if(recv.at(0) == 'H'){
				down(recv.at(1));
			}else{
				up(recv.at(1));
			}

			print("receive:");
			println(recv);
		}
	});
}
