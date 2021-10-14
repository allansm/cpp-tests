#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include <iostream>

bool quit;
int x = 0;
int y = 0;
int red = 0xFF;

SDL_Surface* getCanvas(SDL_Window* win){
	return SDL_GetWindowSurface(win);
}

void clearCanvas(SDL_Window* win){
	auto screenSurface = getCanvas(win);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));	
}

void redsquare(SDL_Window* win){
	auto screenSurface = getCanvas(win);
	SDL_Rect rect = {x, y, 100, 100};
	SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, red, 0x00, 0x00));
}

void keydown(SDL_Event event){
	switch (event.key.keysym.scancode) {
		case SDL_SCANCODE_UP:
			y-=10;
			break;	
		case SDL_SCANCODE_DOWN:
			y+=10;
			break;
		case SDL_SCANCODE_LEFT:
			x-=10;
			break;
		case SDL_SCANCODE_RIGHT:
			x+=10;
	}
}

void eventloop(){
	SDL_Event event;
	
	while(SDL_PollEvent(&event)){  
		switch(event.type){	
			case SDL_KEYDOWN:
				keydown(event);				
				break;
			case SDL_KEYUP:
				break;

			case SDL_QUIT:
				quit = true;
				break; 
		}
	}
}

void draw(SDL_Window* win){
	redsquare(win);
}

void loop(SDL_Window* win){
	while(!quit){
		clearCanvas(win);
		draw(win);

		SDL_UpdateWindowSurface(win);

		eventloop();	 
	}
}

SDL_Window* createWindow(std::string title = "",int width = 400,int height = 300){
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
		printf("error initializing SDL: %s\n", SDL_GetError());
	}

	return SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width, height, 0);
}

int main(int argc, char *argv[]){ 
	loop(createWindow());

	return 0;
}
