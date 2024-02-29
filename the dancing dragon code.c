#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include <SDL/SDL_mixer.h>

#define NB_IMAGES 40
#define SPRITE_WIDTH 666  // Width of each sprite frame
#define SPRITE_HEIGHT 375 // Height of each sprite frame
#define ANIMATION_DELAY 50

int main(int argc,char *argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        return 1;
    }
    image images[NB_IMAGES];
    // Chargement des images de animationnn ///
    char *image_paths[NB_IMAGES] = {

        "/home/khalil/Desktop/sdl/animation/a0.png",
        "/home/khalil/Desktop/sdl/animation/a1.png",
        "/home/khalil/Desktop/sdl/animation/a2.png",
        "/home/khalil/Desktop/sdl/animation/a3.png",
        "/home/khalil/Desktop/sdl/animation/a4.png",
        "/home/khalil/Desktop/sdl/animation/a5.png",
        "/home/khalil/Desktop/sdl/animation/a6.png",
        "/home/khalil/Desktop/sdl/animation/a7.png",
        "/home/khalil/Desktop/sdl/animation/a8.png",
        "/home/khalil/Desktop/sdl/animation/a9.png",
        "/home/khalil/Desktop/sdl/animation/a10.png",
        "/home/khalil/Desktop/sdl/animation/a11.png",
        "/home/khalil/Desktop/sdl/animation/a12.png",
        "/home/khalil/Desktop/sdl/animation/a13.png",
        "/home/khalil/Desktop/sdl/animation/a14.png",
        "/home/khalil/Desktop/sdl/animation/a15.png",
        "/home/khalil/Desktop/sdl/animation/a16.png",
        "/home/khalil/Desktop/sdl/animation/a17.png",
        "/home/khalil/Desktop/sdl/animation/a18.png",
        "/home/khalil/Desktop/sdl/animation/a19.png",
        "/home/khalil/Desktop/sdl/animation/a20.png",
        "/home/khalil/Desktop/sdl/animation/a21.png",
        "/home/khalil/Desktop/sdl/animation/a22.png",
        "/home/khalil/Desktop/sdl/animation/a23.png",
        "/home/khalil/Desktop/sdl/animation/a24.png",
        "/home/khalil/Desktop/sdl/animation/a25.png",
        "/home/khalil/Desktop/sdl/animation/a26.png",
        "/home/khalil/Desktop/sdl/animation/a27.png",
        "/home/khalil/Desktop/sdl/animation/a28.png",
        "/home/khalil/Desktop/sdl/animation/a29.png",
        "/home/khalil/Desktop/sdl/animation/a30.png",
        "/home/khalil/Desktop/sdl/animation/a31.png",
        "/home/khalil/Desktop/sdl/animation/a32.png",
        "/home/khalil/Desktop/sdl/animation/a33.png",
        "/home/khalil/Desktop/sdl/animation/a34.png",
        "/home/khalil/Desktop/sdl/animation/a35.png",
        "/home/khalil/Desktop/sdl/animation/a36.png",
        "/home/khalil/Desktop/sdl/animation/a37.png",
        "/home/khalil/Desktop/sdl/animation/a38.png",
        "/home/khalil/Desktop/sdl/animation/a39.png"

    };

    for (int i = 0; i < NB_IMAGES; i++)
    {
        initbouton(&images[i], image_paths[i], 250, 310);
    }

    // Set up the screen
    SDL_Surface *screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE);
    if (screen == NULL)
    {
        fprintf(stderr, "Impossible d'initialiser l'écran : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Surface *screen1 = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE);
    if (screen1 == NULL)
    {
        fprintf(stderr, "Impossible d'initialiser l'écran : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

        // Initialize SDL Mixer and load audio resources
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
        Mix_Music *music = Mix_LoadMUS("/home/khalil/Desktop/sdl/music.mp3");
        Mix_Chunk *son = Mix_LoadWAV("/home/khalil/Desktop/sdl/soundpass.wav");
        Mix_Chunk *son1 = Mix_LoadWAV("/home/khalil/Desktop/sdl/click.wav");
        if (!music || !son || !son1)
        {
            fprintf(stderr, "Erreur lors du chargement des ressources audio : %s\n", Mix_GetError());
            SDL_Quit();
            return 1;
        }

        // Load animationground image and button images

        /// animation//////

        image background, bg;
        initBackground(&background, "/home/khalil/Desktop/sdl/back/back.png");
        initBackground(&bg, "/home/khalil/Desktop/sdl/back/Background.png");
        ////
        image but1low, but1high, but2low, but2high, but3low, but3high;
        initbouton(&but1low, "/home/khalil/Desktop/sdl/buttons/play_sel.png", 100, 250);
        initbouton(&but1high, "/home/khalil/Desktop/sdl/buttons/play.png", 100, 250);
        initbouton(&but2low, "/home/khalil/Desktop/sdl/buttons/settings_sel.png", 130, 350);
        initbouton(&but2high, "/home/khalil/Desktop/sdl/buttons/settings.png", 130, 350);
        initbouton(&but3low, "/home/khalil/Desktop/sdl/buttons/quit_sel.png", 130, 450);
        initbouton(&but3high, "/home/khalil/Desktop/sdl/buttons/quit.png", 130, 450);

        // Play animationground music
        Mix_PlayMusic(music, -1);

        // Display initial screen with animationground and buttons
        //afficher(background, screen); // Pass screen directly without dereferencing it

       // SDL_Flip(screen);
        // Event loop
        SDL_Event event;
        int running = 1;
        int i = 0;
        int current_image = 0;
        Uint32 start_time = SDL_GetTicks();
        while (running)
        {
            Uint32 elapsed_time = SDL_GetTicks() - start_time;
            if (elapsed_time > ANIMATION_DELAY)
            {
                current_image = (current_image + 1) % NB_IMAGES;
                start_time = SDL_GetTicks();
            }
            // Draw the background
            afficher(background, screen);
                    afficher(but1low, screen);
        afficher(but2low, screen);
        afficher(but3low, screen);

            // Draw the current image
            afficher(images[current_image], screen);
            // Update the screen
            // SDL_Flip(screen);

            while (SDL_PollEvent(&event))
            {

                switch (event.type)
                {
                case SDL_MOUSEMOTION:
                    printf("position x = %d,\n posisition y = %d", event.motion.x, event.motion.y);
                    // Handle mouse motion events to change button appearance
                    if (event.motion.x > 110 && event.motion.x <= 239 && event.motion.y > 261 && event.motion.y <= 310)
                    {
                        afficher(but1high, screen);
                        Mix_PlayChannel(-1, son, 0);
                    }
                    else
                    {
                        afficher(but1low, screen);
                    }
                    if (event.motion.x > 136 && event.motion.x <= 195 && event.motion.y > 358 && event.motion.y <= 412)
                    {
                        afficher(but2high, screen);
                        Mix_PlayChannel(-1, son, 0);
                    }
                    else
                    {
                        afficher(but2low, screen);
                    }
                    if (event.motion.x > 135 && event.motion.x <= 193 && event.motion.y > 454 && event.motion.y <= 510)
                    {
                        afficher(but3high, screen);
                        Mix_PlayChannel(-1, son, 0);
                    }
                    else
                    {
                        afficher(but3low, screen);
                    }
                    SDL_Flip(screen);
                    break;
                case SDL_QUIT:
                    // Quit the program when the window is closed
                    running = 0;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    /////////////////////////////clickkkk butttttttttttttttooonnnnnnnnn/ yaaa ret3iiiiiiii/////////////////////
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        int mouseX = event.button.x;
                        int mouseY = event.button.y;

                        // Check if the left mouse button was clicked inside any of the buttons
                        if (mouseX > 110 && mouseX <= 239 && mouseY > 261 && mouseY <= 310)
                        {
                            // Play button clicked
                            printf("Play button clicked!\n");
                            Mix_PlayChannel(-1, son1, 0);
                            //setting();
                         //   if (event.button.button == SDL_BUTTON_LEFT)
                 //   {
                            //if(mouseX > 135 && mouseX <= 193 && mouseY > 454 && mouseY <= 510)   {
                               //printf("clickkkkkkkkkkkkkkkkkk");
                               
                              // running = 0;
                               //exit = 0;


                            
                    
                            
                            


                         // Change the screen state or perform any action for the play button
                        }
                        else if (mouseX > 136 && mouseX <= 195 && mouseY > 358 && mouseY <= 412)
                        {
                            // Settings button clicked
                            printf("Settings button clicked!\n");
                            Mix_PlayChannel(-1, son1, 0);
                            // Change the screen state or perform any action for the settings button
                        }
                        else if (mouseX > 135 && mouseX <= 193 && mouseY > 454 && mouseY <= 510)
                        {
                            // Quit button clicked
                            printf("Quit button clicked!\n");
                            Mix_PlayChannel(-1, son1, 0);
                            // Change the screen state or perform any action for the quit button
                            running = 0; // Quit the program
                        }
                    }
                    break;
                }
            }
        }

        // Free resources and quit SDL

        liberer(but1low);
        liberer(but1high);
        liberer(but2low);
        liberer(but2high);
        liberer(but3high);
        liberer(but3low);
        Mix_FreeMusic(music);
        Mix_FreeChunk(son);
        liberer(background);
        for (int i = 0; i < NB_IMAGES; i++)
        {
            liberer(images[i]);
        }
        SDL_Quit();

        return 0;
    }
