#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include <iostream>
bool quit;
int x = 0;
int y = 0;
void redsquare(SDL_Surface* screenSurface){
	SDL_Rect rect = {x, y, 100, 100};
	SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
}

void test(SDL_Window* win,SDL_Surface* screenSurface){
	while( !quit ){
		//std::cout << y;
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

		redsquare(screenSurface);

		SDL_UpdateWindowSurface(win);
		// optionally your code comes here...

		// The following inner loop flushes the event queue.
		// (All events that have been queued up between two frames.)

		// declare an event struct somewhere
		SDL_Event event;

		/* Poll for events */
		while( SDL_PollEvent( &event ) ){   
			switch( event.type ){
		    	/* Keyboard event */
		    	/* Pass the event data onto PrintKeyInfo() */
				case SDL_KEYDOWN:
					switch (event.key.keysym.scancode) {
						case SDL_SCANCODE_UP:
							y-=10;
							break;	
						case SDL_SCANCODE_DOWN:
							y+=10;
							break;
					}
					//y-=10;
					break;
				case SDL_KEYUP:
					//y+=10;
					break;
			//PrintKeyInfo( &event.key );
		     //   break;

		    /* SDL_QUIT event (window close) */
		    		case SDL_QUIT:
					quit = 1;
					break;

		    //default:
		      //  break;
			}
		}

	    // optionally your code comes here...
	}
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
  	//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
  
	//redsquare(screenSurface);
		
    /*while(true){
	SDL_UpdateWindowSurface(win);
	SDL_Delay(2000);
    }*/
	test(win,screenSurface);
 
    return 0;
}
