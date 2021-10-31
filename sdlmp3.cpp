#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <cpp-lib/io.hpp>
#include <cpp-lib/path.hpp>

void listen(const char* fn){
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	Mix_Music *music = Mix_LoadMUS(fn);
	Mix_PlayMusic(music, 1);

	while (Mix_PlayingMusic()) {
		SDL_Delay(250);
	}

	Mix_FreeMusic(music);
	Mix_CloseAudio();
}

int main(int argc,char** argv){
	chdir(argv[1]);

	for(auto n : ls(".")){
		if(n != "." && n != ".."){
			println(n);
			listen(n.c_str());
		}
	}
	
	return 0;    
}
