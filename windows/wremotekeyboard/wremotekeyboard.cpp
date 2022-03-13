#include <allansm/socket.hpp>

#include "key.cpp"
#include "keyboard.cpp"

#include <allansm/io.hpp>
#include <allansm/file.hpp>

#include <thread>

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
			down(self->target);
			print("holding ");
			println((char)self->key);
			
		}else{
			up(self->target);
			print("release ");
			println((char)self->key);
		}
	}, info.target);
}

std::vector<key_info> keys;

main(){
	keys = getKeys();

	std::vector<std::thread> threads;

	for(auto n : keys){
		threads.push_back(std::thread(keyAction, n));
	}

	while(true){}
}
