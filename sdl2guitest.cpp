#include <kiss_sdl.h>

static void buttonEvent(kiss_button *button, SDL_Event *e, int *draw){
	if (kiss_button_event(button, e, draw)) {
		*draw = 1;
		system("notepad");	
	}
}

int main(int argc,char **argv){
	bool quit;
	kiss_window window;
	int draw;
	draw = 1;
	SDL_Renderer *renderer;
	kiss_array objects, a1, a2;
	kiss_window wi;
	kiss_window_new(&wi, NULL, 1, 0, 0, kiss_screen_width,kiss_screen_height);
	renderer = kiss_init("", &objects, 640, 480);
	kiss_button button_ok1 = {0};
	kiss_button_new(&button_ok1, &wi, "OK", 0,0);

	if (!renderer) return 1;
	
	wi.visible = 1;	
	
	while(!quit){
		SDL_Event e;
		while(SDL_PollEvent(&e)){  
			switch(e.type){	
				case SDL_KEYDOWN:				
					break;
				case SDL_KEYUP:
					break;

				case SDL_QUIT:
					quit = true;
					break; 
			}
			buttonEvent(&button_ok1,&e,&draw);
		}

	if(!draw) continue;
	kiss_window_draw(&wi, renderer);
	kiss_button_draw(&button_ok1, renderer);
	
	SDL_RenderPresent(renderer);
	draw =0;

	}

	return 0;
}
