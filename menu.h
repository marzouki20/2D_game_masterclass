#ifndef MENU_H_
#define MENU_H_


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <time.h>
#include "image.h"





//void sounds(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i);
//void controls(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i);
//void resolution(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i);
//void sounds(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i);
//void menu(SDL_Surface *ecran,Mix_Music *musique,int *i);
void play(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique);
void menu();
void setting(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique);
int music_volume_up(int volume, SDL_Surface *ecran, image v1, image v2, image v3, image v4);
int music_volume_down(int volume, SDL_Surface *ecran, image v1, image v2, image v3, image v4);
int music_mute_unmute(int volume);
int full_screen_mode_on_off(SDL_Surface *ecran, int fullscreen);
//void choose(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i,int l);









#endif 
