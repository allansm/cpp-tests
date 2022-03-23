#include <allansm/socket.hpp>
#include <allansm/io.hpp>

main(){
	Socket().client("127.0.0.1",54321,[](auto connection){
		Socket().send(connection, input("command:"));
		
		println(Socket().receive(connection,1024));
	});
}
