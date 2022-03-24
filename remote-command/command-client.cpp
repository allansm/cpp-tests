#include <allansm/socket.hpp>
#include <allansm/io.hpp>
#include <allansm/file.hpp>
#include <allansm/parser.hpp>

main(){
	File config(".config");
	
	std::string ip = config.lines()[0];
	int port = unknown(config.lines()[1]);

	Socket().client(ip, port, [](auto connection){
		Socket().send(connection, input("command:"));
		
		println(Socket().receive(connection,1024));
	});
}
