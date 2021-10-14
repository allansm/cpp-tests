#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include <iostream>

void redsquare(SDL_Surface* screenSurface){
	SDL_Rect rect = {50, 50, 100, 100};
	SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
}

int main(int argc, char *argv[])
{
 
    // retutns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       400, 400, 0);
	

	SDL_Surface* screenSurface = SDL_GetWindowSurface(win);
  	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
  
	redsquare(screenSurface);
		
    while(true){
	SDL_UpdateWindowSurface(win);
	SDL_Delay(2000);
    }
 
    return 0;
}
