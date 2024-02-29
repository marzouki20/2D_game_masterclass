#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include <SDL/SDL_mixer.h>
#include <pthread.h> // Include pthread header

#define NB_IMAGES 40
#define SCREEN_W 800 // Screen width
#define SCREEN_H 600 // Screen height

// Function prototype
void* displayImages(void* arg);

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        return 1;
    }

    // Declare and initialize the images array
    image images[NB_IMAGES];
    // Paths to image files
    char* image_paths[NB_IMAGES] = {
        "/home/khalil/Desktop/sdl/animation/a0.png",
        "/home/khalil/Desktop/sdl/animation/a1.png",
        // Add paths for other images here...
    };

    for (int i = 0; i < NB_IMAGES; i++) {
        initbouton(&images[i], image_paths[i], 500, 200);
    }

    // Set up the screen
    SDL_Surface* screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Impossible d'initialiser l'écran : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Initialize SDL Mixer and load audio resources
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Music* music = Mix_LoadMUS("/home/khalil/Desktop/sdl/music.mp3");
    Mix_Chunk* son = Mix_LoadWAV("/home/khalil/Desktop/sdl/soundpass.wav");
    Mix_Chunk* son1 = Mix_LoadWAV("/home/khalil/Desktop/sdl/click.wav");
    if (!music || !son || !son1) {
        fprintf(stderr, "Erreur lors du chargement des ressources audio : %s\n", Mix_GetError());
        SDL_Quit();
        return 1;
    }

    // Load background image and button images
    image background;
    initBackground(&background, "/home/khalil/Desktop/sdl/back/back.png");

    // Create a thread to display images
    pthread_t thread;
    if (pthread_create(&thread, NULL, displayImages, images) != 0) {
        fprintf(stderr, "Erreur lors de la création du thread\n");
        return 1;
    }

    // Play music
    Mix_PlayMusic(music, -1);

    // Display initial screen with background
    afficher(background, screen);
    SDL_Flip(screen);

    // Event loop
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_MOUSEMOTION:
                    // Handle mouse motion events
                    // Implement your logic here
                    break;
                case SDL_QUIT:
                    // Quit the program when the window is closed
                    running = 0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    // Handle mouse button down events
                    // Implement your logic here
                    break;
            }
        }
    }

    // Wait for the displayImages thread to finish
    pthread_join(thread, NULL);

    // Free resources and quit SDL
    liberer(background);
    for (int i = 0; i < NB_IMAGES; i++) {
        liberer(images[i]);
    }
    Mix_FreeMusic(music);
    Mix_FreeChunk(son);
    Mix_FreeChunk(son1);
    SDL_Quit();

    return 0;
}

// Thread function to display images
void* displayImages(void* arg) {
    image* images = (image*)arg;
    for (int i = 0; i < NB_IMAGES; i++) {
        afficher(images[i], screen);
        SDL_Flip(screen);
        SDL_Delay(100);
    }
    return NULL;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////
///////////////////////////
////////////////////
void setting() {
    // Create a new window
    SDL_Surface *newWindow = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
    if (newWindow == NULL) {
        fprintf(stderr, "Unable to create window: %s\n", SDL_GetError());
        return;
    }
//load backgrouun///////
image background,bg;
initBackground(&background,"/home/khalil/Desktop/sdl/volume/startingsoon.jpg");
initBackground(&bg,"/home/khalil/Desktop/sdl/volume/startingsoon.jpg");
    // Load button images
 image but1low, but1high, but2low, but2high, but3low, but3high;
    initbouton(&but1low, "/home/khalil/Desktop/sdl/buttons/play_sel.png", 100, 250);
    initbouton(&but1high, "/home/khalil/Desktop/sdl/buttons/play.png", 100, 250);
    initbouton(&but2low, "/home/khalil/Desktop/sdl/buttons/settings_sel.png", 130, 350);
    initbouton(&but2high, "/home/khalil/Desktop/sdl/buttons/settings.png", 130, 350);
    initbouton(&but3low, "/home/khalil/Desktop/sdl/buttons/quit_sel.png", 130, 450);
    initbouton(&but3high, "/home/khalil/Desktop/sdl/buttons/quit.png", 130, 450);
    afficher(background, newWindow); // Pass newWindow directly without dereferencing it
    afficher(but1low, newWindow);
    afficher(but2low, newWindow);
    afficher(but3low, newWindow);
        // Update the display
        SDL_Flip(newWindow);
 //afficher(playButton, newWindow);
 //SDL_Flip(newWindow);
    // Flag to control event loop
    int running = 1;

    // Event loop for the new window
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            while (SDL_PollEvent(&event)) {

            
            switch (event.type) {
                case SDL_MOUSEMOTION:
                printf("position x = %d,\n posisition y = %d",event.motion.x,event.motion.y);
                    // Handle mouse motion events to change button appearance
                    if (event.motion.x > 110 && event.motion.x <= 239 && event.motion.y > 261 && event.motion.y <= 310) {
                        afficher(but1high, newWindow);
                      //  Mix_PlayChannel(-1,son,0);
                    } else {
                        afficher(but1low, newWindow);
                    }
                    if (event.motion.x > 136 && event.motion.x <= 195 && event.motion.y > 358 && event.motion.y <= 412) {
                        afficher(but2high, newWindow);
                      //  Mix_PlayChannel(-1,son,0);
                    } else {
                        afficher(but2low, newWindow);
                    }
                    if (event.motion.x > 135 && event.motion.x <= 193 && event.motion.y > 454 && event.motion.y <= 510) {
                        afficher(but3high, newWindow);
                      //  Mix_PlayChannel(-1,son,0);
                    } else {
                        afficher(but3low, newWindow);
                    }
                    SDL_Flip(newWindow);
                    break;
                case SDL_QUIT:
                    // Quit the program when the window is closed
                    running = 0;
                    break;
                    
                case SDL_MOUSEBUTTONDOWN :
                /////////////////////////////clickkkk butttttttttttttttooonnnnnnnnn/ yaaa ret3iiiiiiii/////////////////////
                  if (event.button.button == SDL_BUTTON_LEFT) {
                   int mouseX = event.button.x;
                   int mouseY = event.button.y;

                   // Check if the left mouse button was clicked inside any of the buttons
                   if (mouseX > 110 && mouseX <= 239 && mouseY > 261 && mouseY <= 310) {
                  // Play button clicked
                       printf("Play button clicked!\n");
                       //Mix_PlayChannel(-1,son1,0);
                       afficher(bg)

                     // Change the newWindow state or perform any action for the play button
                    } 
                    else if (mouseX > 136 && mouseX <= 195 && mouseY > 358 && mouseY <= 412) {
                      // Settings button clicked
                        printf("Settings button clicked!\n");
                        //Mix_PlayChannel(-1,son1,0);
                      // Change the newWindow state or perform any action for the settings button
                    } 
                    else if (mouseX > 135 && mouseX <= 193 && mouseY > 454 && mouseY <= 510) {
                         // Quit button clicked
                               printf("Quit button clicked!\n");
                               //Mix_PlayChannel(-1,son1,0);
                               // Change the newWindow state or perform any action for the quit button
                        running = 0; // Quit the program
                   }
                  }
                  break;

            }
        }

        // Clear the newWindow
       // SDL_FillRect(newWindow, NULL, SDL_MapRGB(newWindow->format, 255, 255, 255));

        // Render buttons

    }

    // Free resources
    liberer(but1low);
    liberer(but1high);
    liberer(but2low);
    liberer(but2high);
    liberer(but3high);
    liberer(but3low);

    // Free the surface and close the window
    SDL_FreeSurface(newWindow);
}
}