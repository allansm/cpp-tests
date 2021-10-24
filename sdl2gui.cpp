#include <kiss_sdl.h>

struct aaa{
	SDL_Window *w;
	SDL_Renderer *r;
	int draw = 1;
};

kiss_window wi;
kiss_button button_ok1 = {0};

aaa damm;


int x = 0;
int y = 0;
int red = 0xFF;

static void buttonEvent(kiss_button *button, SDL_Event *e, int *draw){
	if(kiss_button_event(button, e, draw)){	
		/*cout << txt << endl;
		*draw = 1;*/
		x+=10;
	}
}

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

void draw(aaa damm){
	if(damm.draw){
		SDL_RenderClear(damm.r);
		kiss_window_draw(&wi,damm.r);
		kiss_button_draw(&button_ok1, damm.r);
		redsquare(damm.w);

		SDL_RenderPresent(damm.r);
		damm.draw = 0;

	}
}


aaa init(char* title, kiss_array *a, int w, int h){
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Rect srect;
	int r;

	r = 0;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GetDisplayBounds(0, &srect);
	if (!a || w > srect.w || h > srect.h) {
		SDL_Quit();
		aaa tmp;
		return tmp;
	}
	kiss_screen_width = w;
	kiss_screen_height = h;
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	kiss_array_new(a);
	window = SDL_CreateWindow(title, srect.w / 2 - w / 2,
		srect.h / 2 - h / 2, w, h, SDL_WINDOW_SHOWN);
	if (window) kiss_array_append(a, WINDOW_TYPE, window);
	renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer) kiss_array_append(a, RENDERER_TYPE, renderer);
	r += kiss_font_new(&kiss_textfont, "kiss_font.ttf", a,
		kiss_textfont_size);
	r += kiss_font_new(&kiss_buttonfont, "kiss_font.ttf", a,
		kiss_buttonfont_size);
	r += kiss_image_new(&kiss_normal, "kiss_normal.png", a, renderer);
	r += kiss_image_new(&kiss_prelight, "kiss_prelight.png", a, renderer);
	r += kiss_image_new(&kiss_active, "kiss_active.png", a, renderer);
	r += kiss_image_new(&kiss_bar, "kiss_bar.png", a, renderer);
	r += kiss_image_new(&kiss_vslider, "kiss_vslider.png", a, renderer);
	r += kiss_image_new(&kiss_hslider, "kiss_hslider.png", a, renderer);
	r += kiss_image_new(&kiss_up, "kiss_up.png", a, renderer);
	r += kiss_image_new(&kiss_down, "kiss_down.png", a, renderer);
	r += kiss_image_new(&kiss_left, "kiss_left.png", a, renderer);
	r += kiss_image_new(&kiss_right, "kiss_right.png", a, renderer);
	r += kiss_image_new(&kiss_combo, "kiss_combo.png", a, renderer);
	r += kiss_image_new(&kiss_selected, "kiss_selected.png", a, renderer);
	r += kiss_image_new(&kiss_unselected, "kiss_unselected.png", a,
		renderer);
	if (r) {
		kiss_clean(a);
		aaa tmp;
		return tmp;
	}

	aaa tmp;

	tmp.w = window;
	tmp.r = renderer;

	return tmp;	
}

aaa init(int w=400,int h=300){	
	kiss_array objects;
	//test tmp = init("",&objects,w,h);
	return init("",&objects,w,h);//tmp;	
}

void events(SDL_Event e){
	kiss_window_event(&wi, &e, &damm.draw);
	buttonEvent(&button_ok1,&e,&damm.draw);
	//kiss_entry_event(&entry, &e, &draw);
	
}

void loop(aaa damm){
	bool quit = false;
	while(!quit){
		//clearCanvas(damm.w);
		
		//SDL_UpdateWindowSurface(damm.w);

		SDL_Event e;
		while(SDL_PollEvent(&e)){
		      	if(e.type == SDL_QUIT){
				quit = true;
			}

			events(e);		
		}

		draw(damm);
	}	
}

int main(int argc,char **argv){
	damm = init(800,600);
	kiss_window_new(&wi, NULL, 1, 0, 0, kiss_screen_width,kiss_screen_height);
	kiss_button_new(&button_ok1, &wi, "test", 110,300);
	loop(damm);
}
