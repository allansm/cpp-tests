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
std::string _ip = "";
int _port = 0;

const long _DAY = 1000*60*60*24;

std::vector<key_info> getKeys(std::string config){
	std::vector<key_info> tmp;
	
	for(auto n:File(config).lines()){
		if(n.length()) tmp.push_back({n.at(0), n.at(2)});
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
	std::string config = ".config";
	File cfg(".config");

	if(cfg.lines()[0].length() >= 8 && cfg.lines()[1].length() >= 4){
		_ip = cfg.lines()[0];
		_port = to<int>(cfg.lines()[1]);
	}

	if(argc >= 3){
		_ip = argv[1];
		_port = to<int>(argv[2]);
	}

	if(_ip == "" || _port == 0){
		println("please define ip and port");
		return 1;
	}

	if(argc == 4){
		config = argv[3];
	}
	
	std::thread connection_thread(getConnection);

	std::vector<std::thread> threads;

	for(auto n : getKeys(config)){
		threads.push_back(std::thread(keyAction, n));
	}

	while(true){
		Sleep(_DAY);
	}

	return 0;
}
