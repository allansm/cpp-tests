#define useSDL2

#include <allansm/simple/sdl2/init.hpp>
#include <allansm/io.hpp>

int x,y;
int mx,my;

bool stop = true;

int main(int argc,char ** argv){
	sdl2 t;
	
	t.width = 1366;
	t.height = 768;

	t.event = [](event e){
		if(e.type == SDL_MOUSEMOTION){
			SDL_GetGlobalMouseState(&mx,&my);
			if(!stop){
				x = mx;
				y = my;
			}	
		}
    		if(e.type == SDL_MOUSEBUTTONDOWN){	
			if(stop){	
				if(mx >= x-50 && mx <= x+50 && my >= y-50 && my <= y+50){
					stop = false;		
				}	
			}else{
				stop = true;
			}
		}		
	};

	t.callback = [](auto a){
		auto win = a->window;	
		auto screenSurface = SDL_GetWindowSurface(win);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));	
		
		SDL_Rect rect = {x-50, y-50, 100, 100};
		SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
		SDL_UpdateWindowSurface(win);
	};
	
	t.start();	
	t.loop();
	return 0;
}
