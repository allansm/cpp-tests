#include <allansm/simple/sdl2/init.hpp>
#include <allansm/simple/sdl2/EventArea.hpp>
#include <allansm/simple/sdl2/util.hpp>
#include <allansm/io.hpp>

EventArea test = {0,0,100,100};

int main(int argc,char ** argv){
	test.onclick = [](){
		println("helloworld");
	};

	sdl2 root;
		
	root.start(SDL_WINDOW_BORDERLESS);
	
	root.onUpdate = [](auto a){ 
		auto win = a->window;	
		auto screenSurface = SDL_GetWindowSurface(win);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));	
		
		SDL_Rect rect = test;
		SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
		SDL_UpdateWindowSurface(win);
	};

	root.onEvent = [](auto a){
		test.init = a;
		test.click();
	};

	root.loop();

	return 0;
}
