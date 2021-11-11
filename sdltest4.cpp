#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

struct test{
	const char * title;
	int width = 400;
	int height = 300;

	bool quit = false;

	void (*event)(SDL_Event) = [](SDL_Event event){};
	void (*callback)(SDL_Window*) = [](SDL_Window* win){};	

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
			callback(win);
			eventloop();	 
		}
	}

	SDL_Window* createWindow(const char * title = "",int width = 400,int height = 300){
		if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
			printf("error initializing SDL: %s\n", SDL_GetError());
		}

		return SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width, height, 0);
	}

	void start(){
		loop(createWindow(this->title,this->width,this->height));
	}
};

using window = SDL_Window*;

int x = 0;
int y = 0;

main(int argc,char ** argv){
	test t;
	
	t.title = "helloworld";
	t.width = 640;
	t.height = 480;
		
	t.callback = [](window win){	
		auto screenSurface = SDL_GetWindowSurface(win);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));	
		SDL_Rect rect = {x, y, 100, 100};
		SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
		SDL_UpdateWindowSurface(win);
	};

	t.event = [](SDL_Event e){
		if(e.type == SDL_KEYDOWN){
			switch(e.key.keysym.scancode){
				case SDL_SCANCODE_LEFT:
					x-=10;
					break;
				case SDL_SCANCODE_RIGHT:
					x+=10;
					break;
				case SDL_SCANCODE_UP:
					y-=10;
					break;	
				case SDL_SCANCODE_DOWN:
					y+=10;
					break;
			}
		}
	};

	t.start();

	return 0;
}
