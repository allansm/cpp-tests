#include <allansm/socket.hpp>

#include "key.cpp"
#include "keyboard.cpp"

#include <allansm/io.hpp>
#include <allansm/file.hpp>

#include <thread>

SOCKET _sock;

struct key_info{
	int key;
	int target;
};

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

			print("holding ");
			println((char)self->key);
		}else{
			char c = self->target;
			std::string msg = "R"+std::string(1,c);
			
			Socket().send(_sock, msg);
			
			print("release ");
			println((char)self->key);
		}
	}, info.target);
}



void getConnection(){
	Socket().client("127.0.0.1", 54321, [](auto sock){
		_sock = sock;
		
		println("connected\n");

		while(true){}
	});
}

std::vector<key_info> keys;

main(){
	std::thread connection_thread(getConnection);

	keys = getKeys();

	std::vector<std::thread> threads;

	for(auto n : keys){
		threads.push_back(std::thread(keyAction, n));
	}

	while(true){}
}
