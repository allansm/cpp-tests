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

struct Rect{
	int x;
	int y;
	int w;
	int h;
	
	Mouse * mouse;

	operator SDL_Rect(){
		SDL_Rect rect = {x,y,w,h};
		
		return rect;
	}

	SDL_Rect rect;
	void (*onclick)() = [](){};	

	void click(Mouse m,SDL_Event e){
		if(e.type == SDL_MOUSEBUTTONDOWN){		
			int x = this->x;
			int y = this->y;
			int w = this->w;
			int h = this->h;
			
			if(m.x >= x && m.x <= x+w && m.y >= y && m.y <= y+h){
				this->onclick();
			}
		}
	}

	void click(int mx,int my,SDL_Event e){
		if(e.type == SDL_MOUSEBUTTONDOWN){		
			int x = this->x;
			int y = this->y;
			int w = this->w;
			int h = this->h;
			
			if(mx >= x && mx <= x+w && my >= y && my <= y+h){
				this->onclick();
			}
		}
	}

	void click(SDL_Event e){
		if(e.type == SDL_MOUSEBUTTONDOWN){		
			int x = this->x;
			int y = this->y;
			int w = this->w;
			int h = this->h;
			Mouse * m = this->mouse;

			if(m->x >= x && m->x <= x+w && m->y >= y && m->y <= y+h){
				this->onclick();
			}
		}
	}
};

struct test{
	int x;
	int y;
	int w;
	int h;
	
	int mx;
	int my;

	SDL_Window * window;
	SDL_Event * event;
	
	void (*onclick)() = [](){};

	operator SDL_Rect(){
		SDL_Rect rect = {x,y,w,h};
		
		return rect;
	}

	void relativePos(SDL_Window * win,SDL_Event * e){
		if(e->type == SDL_MOUSEMOTION){
			int x,y;
			SDL_GetGlobalMouseState(&this->mx,&this->my);	
			SDL_GetWindowPosition(win,&x,&y);
		
			this->mx -= x;
			this->my -= y;	
		}
	}

	void click(){
		this->relativePos(this->window,this->event);

		if(this->event->type == SDL_MOUSEBUTTONDOWN){		
			int x = this->x;
			int y = this->y;
			int w = this->w;
			int h = this->h;
				
			if(this->mx >= x && this->mx <= x+w && this->my >= y && this->my <= y+h){
				this->onclick();
			}		
		}
	}
	
};

Mouse mouse;

Rect t2 = {0,0,100,100};
Rect t3 = {200,0,50,50};
test t4 = {0,200,100,40};

int main(int argc,char ** argv){
	sdl2 t;
	
	t.width = 800;
	t.height = 600;
	
	t.start();

	t2.mouse = &mouse;
	t2.onclick = [](){
		system("dir");
	};
	
	t3.mouse = &mouse;
	t3.onclick = [](){
		system("cls");
	};

	t4.window = t.window;
	t4.event = &t.event;
	t4.onclick = [](){
		println("helloworld");
	};
	
	t.onEvent = [](auto a){
		mouse.relativePos(a->window,a->event);
		t2.click(a->event);
		t3.click(mouse.x,mouse.y,a->event);
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
		
		rect = {mouse.x,mouse.y,5,5};
		SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
		SDL_UpdateWindowSurface(win);
	};
	
	t.loop();

	return 0;
}
