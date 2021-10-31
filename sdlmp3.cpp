#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include <iostream>

int main(int argc,char** argv){
    std::string fn = argv[1];

    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    Mix_Music *music = Mix_LoadMUS(fn.c_str());
    Mix_PlayMusic(music, 1);

    while (Mix_PlayingMusic()) {
        SDL_Delay(250);
    }

    Mix_FreeMusic(music);
    Mix_CloseAudio();
    //SDL_Quit();

    return 0;    
}
