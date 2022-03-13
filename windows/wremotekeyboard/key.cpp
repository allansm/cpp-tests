#include <windows.h>
#include <allansm/elapse.hpp>

struct Key{
	int key;
	int target;
	bool holding = false;
	
	Elapse elapse = Elapse();
	
	bool pressing(int n){
		return GetAsyncKeyState(n) == -32768;
	}

	Key(int key, void(*action)(Key* self), int target=-1){
		this->key = key;
		this->target = (target==-1)?this->key:target;

		while(true){
			if(pressing(this->key) && !holding){
				holding = true;
				
				action(this);
			
			}else if(pressing(this->key) && holding){
				elapse = Elapse();
			
			}else if(elapse.elapsed() > 30 && holding){
				holding = false;
				
				action(this);
			}

			Sleep(1);
		}
	}
};
