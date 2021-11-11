#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>

using eventcall = void(*)(SDL_Event);
using callback = void(*)();

struct test{
	bool quit = false;

	eventcall event = [](SDL_Event event){
		
	};

	callback loopCallback = [](){
	
	};

	void eventloop(){
		SDL_Event e;
		
		while(SDL_PollEvent(&e)){  
			event(e);
			
			if(e.type == SDL_QUIT){
				this->quit = true;
			}		
		}
	}

	void loop(SDL_Window* win){
		while(!this->quit){
			loopCallback();
			eventloop();	 
		}
	}

	SDL_Window* createWindow(std::string title = "",int width = 400,int height = 300){
		if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
			printf("error initializing SDL: %s\n", SDL_GetError());
		}

		return SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width, height, 0);
	}

	void start(std::string title = "",int width = 400,int height = 300){
		loop(createWindow(title,width,height));
	}
};

int main(int argc,char ** argv){
	test t;
	t.start();

	return 0;
}
