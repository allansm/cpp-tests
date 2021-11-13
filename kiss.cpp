#include <kiss_sdl.h>
#include <iostream>

using namespace std;

struct test{
	const char * title;
	int width = 400;
	int height = 300;

	bool quit = false;
	int draw = 1;

	void (*event)(SDL_Event) = [](SDL_Event event){};
	void (*callback)(SDL_Renderer*) = [](SDL_Renderer* renderer){};	

	void eventloop(){
		SDL_Event e;
		
		while(SDL_PollEvent(&e)){  
			event(e);
			
			if(e.type == SDL_QUIT){
				this->quit = true;
			}		
		}
	}

	void loop(SDL_Renderer* renderer){
		while(!this->quit){
			callback(renderer);
			eventloop();	 
		}
	}

	SDL_Renderer* (*createWindow)() = [](){
		SDL_Renderer *renderer;
		return renderer;
	};

	void start(){
		loop(createWindow());
	}
	
};

int main(int argc,char **argv){
	test t;
	t.createWindow = [](){
		kiss_window window;
		SDL_Renderer *renderer;
		kiss_array objects;
		kiss_window wi;
		kiss_window_new(&wi, NULL, 1, 0, 0, kiss_screen_width,kiss_screen_height);
		renderer = kiss_init("", &objects, 400, 300);
		wi.visible = 1;
		
		return renderer;
	};
	
	t.start();	
}
