#define useSDL2

#include <allansm/simple/sdl2/init.hpp>
#include <allansm/simple/sdl2/EventArea.hpp>
#include <allansm/io.hpp>

EventArea t2 = {0,0,100,100};
EventArea t3 = {200,0,50,50};
EventArea t4 = {0,200,100,40};

int main(int argc,char ** argv){
	sdl2 t;
	
	t.width = 800;
	t.height = 600;
	
	t.start();

	t2.init = &t;
	t2.onclick = [](){
		system("dir");
	};
		
	t3.init = &t;
	t3.onclick = [](){
		system("cls");
	};
	
	t4.init = &t;
	t4.onclick = [](){
		println("helloworld");
	};
	
	t.onEvent = [](auto a){	
		t2.click();
		t3.click();
		t4.click();
	};

	t.onUpdate = [](auto a){
		auto win = a->window;
		
		auto screenSurface = SDL_GetWindowSurface(win);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));	
		
		SDL_Rect rect = t2;
		SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
		
		rect = t3;
		SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0xFF));
		
		rect = t4;
		SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
			
		SDL_UpdateWindowSurface(win);
	};
	
	t.loop();

	return 0;
}
