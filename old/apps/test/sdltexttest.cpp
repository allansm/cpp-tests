#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include <iostream>

bool quit;

std::string txt = "";

SDL_Surface* getCanvas(SDL_Window* win){
	return SDL_GetWindowSurface(win);
}

void clearCanvas(SDL_Window* win){
	auto screenSurface = getCanvas(win);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));	
}



void keydown(SDL_Event event){
	switch (event.key.keysym.scancode) {
		case SDL_SCANCODE_RETURN:
			std::cout << txt;
			txt = "";
			break;
	}
}

void eventloop(){
	SDL_Event event;
	
	while(SDL_PollEvent(&event)){  
		switch(event.type){
			case SDL_KEYDOWN:
				keydown(event);				
				break;	
			case SDL_TEXTINPUT:
				txt+=event.text.text;
				break;	
			case SDL_QUIT:
				quit = true;
				break; 
		}
	}
}

void loop(SDL_Window* win){
	while(!quit){
		clearCanvas(win);

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
