#define useSDL2

#include <allansm/simple/sdl2/init.hpp>
#include <allansm/io.hpp>


SDL_Texture * loadImage(const char * fn,SDL_Renderer * renderer){	
	SDL_Surface * image = IMG_Load(fn);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
	
	return texture;
}


SDL_Texture * texture;
const char* fn;
int main(int argc,char ** argv){
	sdl2 t;
	fn = argv[1];

	t.callback = [](window win){
		SDL_Renderer * renderer = SDL_CreateRenderer(win, -1, 0);
		SDL_RenderCopy(renderer, loadImage(fn,renderer), NULL, NULL);
		SDL_RenderPresent(renderer);
	};
	
	t.start();	

	return 0;
}
