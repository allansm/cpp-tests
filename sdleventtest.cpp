#define useSDL2

#include <allansm/simple/sdl2/init.hpp>
#include <allansm/io.hpp>

struct Mouse{
	int x;
	int y;

	void pos(SDL_Event e){
		if(e.type == SDL_MOUSEMOTION){
			SDL_GetGlobalMouseState(&this->x,&this->y);	
		}	
	}

	void relativePos(SDL_Window * win,SDL_Event e){
		if(e.type == SDL_MOUSEMOTION){
			int x,y;
			SDL_GetGlobalMouseState(&this->x,&this->y);	
			SDL_GetWindowPosition(win,&x,&y);
		
			this->x -= x;
			this->y -= y;
		}	
	}
};

struct test{
	SDL_Rect rect;
	
	test(SDL_Rect rect){
		this->rect = rect;
	}

	void click(Mouse m,SDL_Event e){
		if(e.type == SDL_MOUSEBUTTONDOWN){		
			int x = this->rect.x;
			int y = this->rect.y;
			int w = this->rect.w;
			int h = this->rect.h;
			println(x);
			println(y);
			println(w);
			println(h);
			println(m.x);
			println(m.y);
			if(m.x >= x && m.x <= x+w && m.y >= y && m.y <= y+h){
				println("inside");
			}else{
				println("outside");
			}
		}
	}
};

Mouse mouse;
test t2 = test({0,0,100,100});

int main(int argc,char ** argv){
	sdl2 t;
	//t.width = 1366;
	//t.height = 768;

	t.start();	
	
	t.event = [](auto a){
		mouse.relativePos(a->window,a->e);
		t2.click(mouse,a->e);
	};

	t.callback = [](auto a){
		auto win = a->window;	
		
		auto screenSurface = SDL_GetWindowSurface(win);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));	
		
		SDL_Rect rect = t2.rect;
		SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
		SDL_UpdateWindowSurface(win);

		SDL_Rect rect2 = {mouse.x,mouse.y,1,1};
		SDL_FillRect(screenSurface, &rect2, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
		SDL_UpdateWindowSurface(win);	
	};
	
	t.loop();	

	return 0;
}
