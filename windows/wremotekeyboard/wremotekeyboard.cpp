#include "key.cpp"
#include "keyboard.cpp"

#include <allansm/io.hpp>
#include <allansm/file.hpp>
#include <thread>

main(){
	std::thread a([](){
		Key(88,[](auto self){
			if(self->holding){
				down(self->target);
				print("holding ");
				println(self->key);
				
			}else{
				up(self->target);
				print("release ");
				println(self->key);
			}
		},65);
	});

	while(true){}
}
