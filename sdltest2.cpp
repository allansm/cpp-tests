#include <allansm/simple/sdl2/init.hpp>
#include <allansm/simple/sdl2/EventArea.hpp>
#include <allansm/simple/sdl2/util.hpp>
#include <allansm/simple/sdl2/mouse.hpp>
#include <allansm/io.hpp>

EventArea test = {150,100,100,100};
Mouse m;
int wx;
int wy;
bool can = false;
int main(int argc,char ** argv){
	test.onclick = [](){
		if(can){
			can = false;
		}else{
			can = true;
		}
	};

	sdl2 root;
		
	root.start(SDL_WINDOW_BORDERLESS);
	
	root.onUpdate = [](auto a){
		if(can){
	       		SDL_SetWindowPosition(a->window,m.x-200,m.y-150);
		}

		SDL_GetWindowPosition(a->window,&wx,&wy);

		print(wx);
		print(" ");
		print(wy);
		print(" ");

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
		m.pos(a->event);
	};

	root.loop();

	return 0;
}
