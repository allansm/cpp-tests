#include <allansm/socket.hpp>
#include <allansm/io.hpp>
#include <allansm/string.hpp>
#include <allansm/time.hpp>

bool ok = false;

main(int argc, char** argv){
	std::string start = Time().getCurrent();
	std::string ip = "142.250.79.36";
	
	if(argc > 1){
		ip = argv[1];
	}
	
	println("ip:"+ip);
	print("\n");

	while(true){	
		Socket().client(ip.c_str(), 80, [](auto connection){
			std::string h = "GET / HTTP/1.1\r\n";
			h+="Host: www.google.com\r\n";
			h+="Connection: Close\r\n\r\n";

			Socket().send(connection, h);
			String response = Socket().receive(connection);
			String status = response.split("\r\n\r\n")[0];
			
			if(status.has("200") && status.has("OK")){
				ok = true;
			}
		});

		if(ok){
			println("connection ok");
			break;
		}else{
			println("has no connection");
		}

		Time().sleep(100);
	}

	println(start+" >> "+Time().getCurrent());
}
