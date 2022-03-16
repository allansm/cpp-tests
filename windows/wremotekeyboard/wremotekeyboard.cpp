#include <allansm/socket.hpp>

#include "key.cpp"
#include "keyboard.cpp"

#include <allansm/io.hpp>
#include <allansm/file.hpp>
#include <allansm/parser.hpp>

#include <thread>

struct key_info{
	int key;
	int target;
};

SOCKET _sock;
std::string _ip;
int _port;

const long _DAY = 1000*60*60*24;

std::vector<key_info> getKeys(){
	std::vector<key_info> tmp;
	
	for(auto n:File(".config").lines()){
		tmp.push_back({n.at(0), n.at(2)});
	}

	return tmp;
}

void keyAction(key_info info){
	Key(info.key, [](auto self){
		if(self->holding){
			char c = self->target;
			std::string msg = "H"+std::string(1,c);
			
			Socket().send(_sock, msg);

			print("H");
			print((char)self->key);
			print(" ");
		}else{
			char c = self->target;
			std::string msg = "R"+std::string(1,c);
			
			Socket().send(_sock, msg);
			
			print("R");
			print((char)self->key);
			print(" ");
		}
	}, info.target);
}

void getConnection(){
	Socket().client(_ip.c_str(), _port, [](auto sock){
		_sock = sock;
		
		println("connected\n");

		while(true){
			Sleep(_DAY);
		}
	});
}

int main(int argc, char** argv){
	if(argc == 3){
		_ip = argv[1];
		_port = to<int>(argv[2]);
	}else{
		println("please define ip and port");
		return 1;
	}
	
	std::thread connection_thread(getConnection);

	std::vector<std::thread> threads;

	for(auto n : getKeys()){
		threads.push_back(std::thread(keyAction, n));
	}

	while(true){
		Sleep(_DAY);
	}

	return 0;
}
