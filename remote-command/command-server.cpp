#include <allansm/io.hpp>
#include <allansm/socket.hpp>
#include <allansm/path.hpp>
#include <allansm/string.hpp>
#include <allansm/util.hpp>
#include <allansm/file.hpp>
#include <allansm/parser.hpp>

main(){
	int port = unknown(File(".config").lines()[1]);

	while(true){
		println("waiting...");
		Socket().server(port, [](auto connection){
				String command = Socket().receive(connection, 1024);
				
				if(command.has("cd")){
					chdir(command.split(" ")[1]);
					Socket().send(connection, getcwd());
				}else{
					std::string out = Util().exec(((std::string)command).c_str());
					println(out);
					
					Socket().send(connection, out);
				}
		});
	}
}
