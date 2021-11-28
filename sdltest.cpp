#include <allansm/simple/sdl2/init.hpp>

int main(int argc,char ** argv){
	sdl2 t;
	
	t.start(SDL_WINDOW_HIDDEN);
	
	t.onUpdate = [](auto a){
		auto win = a->window;
		
		auto screenSurface = SDL_GetWindowSurface(win);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));	
		
		SDL_Rect rect = {0,0,100,100};
		SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
			
		SDL_UpdateWindowSurface(win);
		IMG_SavePNG(screenSurface, "hello.png");
	       	//a->quit = true;	
	};

	t.onUpdate(&t);
	//t.loop();

	return 0;
}
