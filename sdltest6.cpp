#define useSDL2

#include <allansm/simple/sdl2/init.hpp>
#include <allansm/io.hpp>


SDL_Texture * loadTexture(const char * fn,SDL_Renderer * renderer){	
	SDL_Surface * image = IMG_Load(fn);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
	
	SDL_FreeSurface(image);		
	
	return texture;
}


SDL_Texture * texture;
int x = 0;
int y = 0;
int width = 100;
int height = 100;
int main(int argc,char ** argv){
	sdl2 t;
	
	t.start();
	
	texture = loadTexture(argv[1],t.render);
	
	t.event = [](auto e){
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
		if(e.type == SDL_MOUSEWHEEL){
			if(e.wheel.y > 0){
				width+=10;
				height+=10;	
			}
			if(e.wheel.y < 0){
				width-=10;
				height-=10;
			}
		}	
	
	};

	t.callback = [](auto win){
		SDL_RenderClear(win->render);
		SDL_Rect sz = {x,y,width,height};
		SDL_RenderCopy(win->render, texture, NULL, &sz);
		SDL_RenderPresent(win->render);	
	};
	
	t.loop();	

	return 0;
}
