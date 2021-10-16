#include <kiss_sdl.h>
#include <iostream>

using namespace std;
string txt = "";

static void buttonEvent(kiss_button *button, SDL_Event *e, int *draw){
	if(kiss_button_event(button, e, draw)){	
		cout << txt << endl;
		*draw = 1;
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
	renderer = kiss_init("", &objects, 200, 40);
	kiss_button button_ok1 = {0};
	kiss_button_new(&button_ok1, &wi, "OK", 110,2);

	kiss_entry entry = {0};
	kiss_entry_new(&entry, &wi, 1, "allansm", 0,0,100);

	if (!renderer) return 1;
	kiss_array_new(&a1);
	kiss_array_append(&objects, ARRAY_TYPE, &a1);
	kiss_array_new(&a2);
	kiss_array_append(&objects, ARRAY_TYPE, &a2);
	
	wi.visible = 1;	
	
	while(!quit){
		SDL_Event e;
		SDL_Delay(10);
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
			kiss_window_event(&wi, &e, &draw);
			kiss_entry_event(&entry, &e, &draw);
			buttonEvent(&button_ok1,&e,&draw);
			
		}
		
		if(draw){
			SDL_RenderClear(renderer);
			kiss_window_draw(&wi, renderer);
			kiss_entry_draw(&entry, renderer);

			kiss_button_draw(&button_ok1, renderer);
			
			SDL_RenderPresent(renderer);
			draw = 0;
		}

		txt = entry.text;
	}
	kiss_clean(&objects);
	return 0;
}
