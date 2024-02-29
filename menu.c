#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "menu.h"
#include <SDL/SDL_mixer.h>

#define NB_IMAGES 78
#define SPRITE_WIDTH 666  // Width of each sprite frame
#define SPRITE_HEIGHT 375 // Height of each sprite frame
#define ANIMATION_DELAY 50

void menu()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        //return 1;
    }
    image images[NB_IMAGES];
    image images1[78];
    // Chargement des images de animationnn ///
        char *image_paths1[78] = {

"/home/khalil/Desktop/sdl/back/a0.png",
"/home/khalil/Desktop/sdl/back/a1.png",
"/home/khalil/Desktop/sdl/back/a2.png",
"/home/khalil/Desktop/sdl/back/a3.png",
"/home/khalil/Desktop/sdl/back/a4.png",
"/home/khalil/Desktop/sdl/back/a5.png",
"/home/khalil/Desktop/sdl/back/a6.png",
"/home/khalil/Desktop/sdl/back/a7.png",
"/home/khalil/Desktop/sdl/back/a8.png",
"/home/khalil/Desktop/sdl/back/a9.png",
"/home/khalil/Desktop/sdl/back/a10.png",
"/home/khalil/Desktop/sdl/back/a11.png",
"/home/khalil/Desktop/sdl/back/a12.png",
"/home/khalil/Desktop/sdl/back/a13.png",
"/home/khalil/Desktop/sdl/back/a14.png",
"/home/khalil/Desktop/sdl/back/a15.png",
"/home/khalil/Desktop/sdl/back/a16.png",
"/home/khalil/Desktop/sdl/back/a17.png",
"/home/khalil/Desktop/sdl/back/a18.png",
"/home/khalil/Desktop/sdl/back/a19.png",
"/home/khalil/Desktop/sdl/back/a20.png",
"/home/khalil/Desktop/sdl/back/a21.png",
"/home/khalil/Desktop/sdl/back/a22.png",
"/home/khalil/Desktop/sdl/back/a23.png",
"/home/khalil/Desktop/sdl/back/a24.png",
"/home/khalil/Desktop/sdl/back/a25.png",
"/home/khalil/Desktop/sdl/back/a26.png",
"/home/khalil/Desktop/sdl/back/a27.png",
"/home/khalil/Desktop/sdl/back/a28.png",
"/home/khalil/Desktop/sdl/back/a29.png",
"/home/khalil/Desktop/sdl/back/a30.png",
"/home/khalil/Desktop/sdl/back/a31.png",
"/home/khalil/Desktop/sdl/back/a32.png",
"/home/khalil/Desktop/sdl/back/a33.png",
"/home/khalil/Desktop/sdl/back/a34.png",
"/home/khalil/Desktop/sdl/back/a35.png",
"/home/khalil/Desktop/sdl/back/a36.png",
"/home/khalil/Desktop/sdl/back/a37.png",
"/home/khalil/Desktop/sdl/back/a38.png",
"/home/khalil/Desktop/sdl/back/a39.png",
"/home/khalil/Desktop/sdl/back/a40.png",
"/home/khalil/Desktop/sdl/back/a41.png",
"/home/khalil/Desktop/sdl/back/a42.png",
"/home/khalil/Desktop/sdl/back/a43.png",
"/home/khalil/Desktop/sdl/back/a44.png",
"/home/khalil/Desktop/sdl/back/a45.png",
"/home/khalil/Desktop/sdl/back/a46.png",
"/home/khalil/Desktop/sdl/back/a47.png",
"/home/khalil/Desktop/sdl/back/a48.png",
"/home/khalil/Desktop/sdl/back/a49.png",
"/home/khalil/Desktop/sdl/back/a50.png",
"/home/khalil/Desktop/sdl/back/a51.png",
"/home/khalil/Desktop/sdl/back/a52.png",
"/home/khalil/Desktop/sdl/back/a53.png",
"/home/khalil/Desktop/sdl/back/a54.png",
"/home/khalil/Desktop/sdl/back/a55.png",
"/home/khalil/Desktop/sdl/back/a56.png",
"/home/khalil/Desktop/sdl/back/a57.png",
"/home/khalil/Desktop/sdl/back/a58.png",
"/home/khalil/Desktop/sdl/back/a59.png",
"/home/khalil/Desktop/sdl/back/a60.png",
"/home/khalil/Desktop/sdl/back/a61.png",
"/home/khalil/Desktop/sdl/back/a62.png",
"/home/khalil/Desktop/sdl/back/a63.png",
"/home/khalil/Desktop/sdl/back/a64.png",
"/home/khalil/Desktop/sdl/back/a65.png",
"/home/khalil/Desktop/sdl/back/a66.png",
"/home/khalil/Desktop/sdl/back/a67.png",
"/home/khalil/Desktop/sdl/back/a68.png",
"/home/khalil/Desktop/sdl/back/a69.png",
"/home/khalil/Desktop/sdl/back/a70.png",
"/home/khalil/Desktop/sdl/back/a71.png",
"/home/khalil/Desktop/sdl/back/a72.png",
"/home/khalil/Desktop/sdl/back/a73.png",
"/home/khalil/Desktop/sdl/back/a74.png",
"/home/khalil/Desktop/sdl/back/a75.png",
"/home/khalil/Desktop/sdl/back/a76.png",
"/home/khalil/Desktop/sdl/back/a77.png"

    };
        for (int i = 0; i < 78; i++)
    {
        initbouton(&images1[i], image_paths1[i], 750, 290);
    }
    char *image_paths[NB_IMAGES] = {

        "/home/khalil/Desktop/sdl/animation/background/Frame 1.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 2.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 3.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 4.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 5.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 6.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 7.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 8.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 9.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 10.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 11.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 12.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 13.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 14.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 15.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 16.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 17.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 18.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 19.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 20.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 21.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 22.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 23.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 24.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 25.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 26.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 27.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 28.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 29.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 30.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 31.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 32.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 33.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 34.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 35.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 36.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 37.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 38.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 39.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 40.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 41.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 42.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 43.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 44.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 45.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 46.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 47.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 48.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 49.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 50.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 51.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 52.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 53.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 54.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 55.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 56.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 57.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 58.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 59.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 60.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 61.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 62.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 63.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 64.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 65.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 66.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 67.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 68.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 69.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 70.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 71.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 72.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 73.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 74.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 75.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 76.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 77.png",
        "/home/khalil/Desktop/sdl/animation/background/Frame 78.png"
    };

    for (int i = 0; i < NB_IMAGES; i++)
    {
        initBackground(&images[i], image_paths[i]);
    }

    // Set up the screen//////////////////////////////////////////////////////////////////////////////////
    SDL_Surface *screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE);
    if (screen == NULL)
    {
        fprintf(stderr, "Impossible d'initialiser l'écran : %s\n", SDL_GetError());
        SDL_Quit();
       // return 1;
    }
    SDL_Surface *screen1 = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE);
    if (screen1 == NULL)
    {
        fprintf(stderr, "Impossible d'initialiser l'écran : %s\n", SDL_GetError());
        SDL_Quit();
        //return 1;
    }

        // Initialize SDL Mixer and load audio resources//////////////////////////////////////////////////////////////////
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
        Mix_Music *music = Mix_LoadMUS("/home/khalil/Desktop/sdl/music.mp3");
        Mix_Chunk *son = Mix_LoadWAV("/home/khalil/Desktop/sdl/soundpass.wav");
        Mix_Chunk *son1 = Mix_LoadWAV("/home/khalil/Desktop/sdl/click.wav");
        if (!music || !son || !son1)
        {
            fprintf(stderr, "Erreur lors du chargement des ressources audio : %s\n", Mix_GetError());
            SDL_Quit();
           // return 1;
        }

        // Load animationground image and button images

        /// animation////////////////////////////////////////////////////////////////////////////////////////////////////

        image background, bg;
        initBackground(&background, "/home/khalil/Desktop/sdl/back/back.png");
        
        ////
        image but1low, but1high, but2low, but2high, but3low, but3high,logo, bg1;
        initbouton(&but1low, "/home/khalil/Desktop/sdl/buttons/BUTTONS/Vector Smart Object-5.png", 220, 250);
        initbouton(&but1high, "//home/khalil/Desktop/sdl/buttons/BUTTONS/play.png", 220, 250);
        initbouton(&but2low, "/home/khalil/Desktop/sdl/buttons/BUTTONS/Layer 8.png", 220, 350);
        initbouton(&but2high, "/home/khalil/Desktop/sdl/buttons/BUTTONS/settings.png", 220, 350);
        initbouton(&but3low, "/home/khalil/Desktop/sdl/buttons/BUTTONS/Layer 10.png", 220, 450);
        initbouton(&but3high, "/home/khalil/Desktop/sdl/buttons/BUTTONS/exit.png", 220, 450);
        //initbouton(&logo, "/home/khalil/Desktop/sdl/logo.png", 800, 20);
        initbouton(&bg1, "/home/khalil/Desktop/sdl/buttons/MENU.png", 20, 20);


        // Play animationground music
        Mix_PlayMusic(music, -1);

        // Display initial screen with animationground and buttons
        // Pass screen directly without dereferencing it
          
       // SDL_Flip(screen);
        // Event loop//////////////////////////////////////////////////////////////////////////////////////////////
        SDL_Event event;
        int running = 1;
        int i = 0;
        int current_image = 0;
        Uint32 start_time = SDL_GetTicks();
        while (running)
        {
            Uint32 elapsed_time = SDL_GetTicks() - start_time;
// Draw the background
            afficher(background, screen);
            
            afficher(but1low, screen);
        afficher(but2low, screen);
        afficher(but3low, screen);
      //  afficher(logo, screen);            // Draw the current image
            afficher(images[current_image], screen);
            afficher(images1[current_image], screen);
            afficher(bg1, screen);
            // Update the screen
            // SDL_Flip(screen);

            while (SDL_PollEvent(&event))
            {
               afficher(logo, screen);
                switch (event.type)
                {
                     
                case SDL_MOUSEMOTION:
                    printf("position x = %d,\n posisition y = %d", event.motion.x, event.motion.y);
                        int mouseX = event.button.x;
                        int mouseY = event.button.y;
                    // Handle mouse motion events to change button appearance
                    if (mouseX > 220 && mouseX <= 383 && mouseY > 250 && mouseY <= 308)
                    {
                        afficher(but1high, screen);
                        Mix_PlayChannel(-1, son, 0);
                    }
                    else
                    {
                        afficher(but1low, screen);
                    }
                    if (mouseX > 220 && mouseX <= 387&& mouseY > 350 && mouseY <= 413)
                    {
                        afficher(but2high, screen);
                        Mix_PlayChannel(-1, son, 0);
                    }
                    else
                    {
                        afficher(but2low, screen);
                    }
                    if (mouseX > 220 && mouseX <= 388 && mouseY > 450 && mouseY <= 504)
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
                        if (mouseX > 220 && mouseX <= 383 && mouseY > 250 && mouseY <= 308)
                        {
                            // Play button clicked
                            printf("Play button clicked!\n");
                            Mix_PlayChannel(-1, son1, 0);
                            play(screen1,son,music);

                            
                            }
                         // Change the screen state or perform any action for the play 
                        else if (mouseX > 220 && mouseX <= 387&& mouseY > 350 && mouseY <= 413)
                        {
                            // Settings button clicked
                            printf("Settings button clicked!\n");
                            Mix_PlayChannel(-1, son1, 0);
                            setting(screen1,son,music);
                            // Change the screen state or perform any action for the settings button
                        }
                        else if (mouseX > 220 && mouseX <= 388 && mouseY > 450 && mouseY <= 504)
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
                        if (elapsed_time > ANIMATION_DELAY)
            {
                current_image = (current_image + 1) % NB_IMAGES;
                start_time = SDL_GetTicks();
            }
            //
        }

        // Free resources and quit SDL

        liberer(but1low);
        liberer(but1high);
        liberer(but2low);
        liberer(but2high);
        liberer(but3high);
        liberer(but3low);
        liberer(bg1);
        Mix_FreeMusic(music);
        Mix_FreeChunk(son);
        liberer(logo);
        liberer(background);
        for (int i = 0; i < NB_IMAGES; i++)
        {
            liberer(images[i]);
        }
        SDL_Quit();

        //return 0;
    }

/////////////////////////////////////palyyyy/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void play(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{
    SDL_Surface *background=NULL,*newgame = NULL, *continuer = NULL,*back=NULL;
    SDL_Rect positionbackground,positionback,positioncontinuer,positionnewgame;
    SDL_Event event;
    int continuee = 1,x=1,y=1,l,j;

background=IMG_Load("/home/khalil/Desktop/sdl/animation/background/Frame 90.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    newgame=IMG_Load("/home/khalil/Desktop/sdl/buttons/new1.png");
    positionnewgame.x = 340;
    positionnewgame.y = 310;

    continuer=IMG_Load("/home/khalil/Desktop/sdl/buttons/resume1.png");
    positioncontinuer.x = 340;
    positioncontinuer.y = 400;

    back=IMG_Load("/home/khalil/Desktop/sdl/buttons/home1.png");
    positionback.x = 20;
    positionback.y = 25;

while(continuee)
{
SDL_WaitEvent(&event);
        switch(event.type)
        {
case SDL_QUIT:
continuee = 0;
break;
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
                {
case SDLK_ESCAPE:
continuee = 0;
                break;
case SDLK_DOWN :
if(x==1)
{
back=IMG_Load("/home/khalil/Desktop/sdl/buttons/home1.png");
continuer=IMG_Load("/home/khalil/Desktop/sdl/buttons/resume2.png");
SDL_BlitSurface(continuer, NULL, ecran, &positioncontinuer);
Mix_PlayChannel(1, son, 0);
x=2;y=1;
}

else if(x==2)
{
continuer=IMG_Load("/home/khalil/Desktop/sdl/buttons/resume1.png");
newgame=IMG_Load("/home/khalil/Desktop/sdl/buttons/new2.png");
SDL_BlitSurface(newgame, NULL, ecran, &positionnewgame);
Mix_PlayChannel(1, son, 0);
x=3;y=3;
}

else if(x==3)
{
newgame=IMG_Load("/home/khalil/Desktop/sdl/buttons/new1.png");
back=IMG_Load("/home/khalil/Desktop/sdl/buttons/home2.png");
SDL_BlitSurface(back, NULL, ecran, &positionback);
Mix_PlayChannel(1, son, 0);
x=1;y=2;
}

break;
case SDLK_UP:
if(y==1)
{
continuer=IMG_Load("/home/khalil/Desktop/sdl/buttons/resume1.png");
back=IMG_Load("/home/khalil/Desktop/sdl/buttons/home2.png");
SDL_BlitSurface(back, NULL, ecran, &positionback);
Mix_PlayChannel(1, son, 0);
y=2;x=1;
}

else  if(y==2)
{
back=IMG_Load("/home/khalil/Desktop/sdl/buttons/home1.png");
newgame=IMG_Load("/home/khalil/Desktop/sdl/buttons/new2.png");
SDL_BlitSurface(newgame, NULL, ecran, &positionnewgame);
Mix_PlayChannel(1, son, 0);
y=3;x=3;
}

else if(y==3)
{
newgame=IMG_Load("/home/khalil/Desktop/sdl/buttons/new1.png");
continuer=IMG_Load("/home/khalil/Desktop/sdl/buttons/resume2.png");
SDL_BlitSurface(continuer, NULL, ecran, &positioncontinuer);
Mix_PlayChannel(1, son, 0);
y=1;x=2;
}
break;
case SDLK_RETURN :
if(y==1)
{continuee = 0;}
else if(y==2)
{l=0;}


break;


}
break;
                case SDL_MOUSEBUTTONDOWN:
if (event.button.button == SDL_BUTTON_LEFT)
        {
if ((event.button.x >positionnewgame.x) && (event.button.x < positionnewgame.x +positionnewgame.w) && (event.button.y >positionnewgame.y) && (event.button.y <positionnewgame.x+positionnewgame.h))
                     { }

else if ((event.button.x >positionback.x) && (event.button.x < positionback.x +positionback.w) && (event.button.y >positionback.y) && (event.button.y <positionback.x+positionback.h))
                                {menu();}

}
break;

        }

SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(newgame, NULL, ecran, &positionnewgame);
        SDL_BlitSurface(continuer, NULL, ecran, &positioncontinuer);
        SDL_BlitSurface(back, NULL, ecran, &positionback);
SDL_Flip(ecran);
    }
SDL_FreeSurface(background);
    SDL_FreeSurface(newgame);
    SDL_FreeSurface(continuer);
    SDL_FreeSurface(back);
SDL_Quit();
}
/////////////////////////////////////setting///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setting(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{
   SDL_Event event;
    int continuer = 1,x=1,y=1,musicVolume=0;

 image background, bg;
        initBackground(&background, "/home/khalil/Desktop/sdl/animation/background/Frame 90.png");
        
        ////
        image back0,back1,fullscreen0,fullscreen1,plus,moin,moin1,v1,v2,v3,v4,barr,bg1,plus1;
        

// Initialisez ces variables quelque part avant d'appeler les fonctions music_volume_up() et music_volume_down().
initbouton(&bg1 ,"/home/khalil/Desktop/sdl/buttons/MENU.png",320,20);
initbouton(&v1, "/home/khalil/Desktop/sdl/volume/v1.png", 520, 370);
initbouton(&v2, "/home/khalil/Desktop/sdl/volume/v2.png", 570, 370);
initbouton(&v3, "/home/khalil/Desktop/sdl/volume/v3.png", 620, 370);
initbouton(&v4, "/home/khalil/Desktop/sdl/volume/v4.png", 670, 370);
        initbouton(&back1,"/home/khalil/Desktop/sdl/buttons/BUTTONS/exit.png", 20, 25);
        initbouton(&back0, "/home/khalil/Desktop/sdl/buttons/BUTTONS/Layer 10.png", 20, 25);
        initbouton(&fullscreen0, "/home/khalil/Desktop/sdl/volume/Layer 13 copy 3.png", 1000, 20);
        initbouton(&fullscreen1, "/home/khalil/Desktop/sdl/volume/SeekPng.com_size-icon-png_3598049.png", 1000, 20);
        initbouton(&plus, "/home/khalil/Desktop/sdl/buttons/BUTTONS/speaker-plus-sign.png", 830, 370);
        initbouton(&plus1, "/home/khalil/Desktop/sdl/buttons/BUTTONS/speaker-plus-sign-3.png",830,370);
        initbouton(&moin, "/home/khalil/Desktop/sdl/buttons/BUTTONS/speaker-plus-sign-1.png", 380, 370);
        initbouton(&moin1, "/home/khalil/Desktop/sdl/buttons/BUTTONS/speaker-plus-sign-2.png", 380, 370);
         initbouton(&barr, "/home/khalil/Desktop/sdl/volume/barr.png", 400, 370);

afficher(background, ecran);
afficher(bg1, ecran);
afficher(back0,ecran);
afficher(fullscreen0,ecran);
afficher(plus,ecran);   
afficher(moin,ecran);
afficher(barr,ecran);
afficher(v1,ecran);
afficher(v2,ecran);


while (continuer)
{
SDL_WaitEvent(&event);
        switch(event.type)
        {
case SDL_QUIT:
                menu();
                continuer = 0;
                
break;
case SDL_MOUSEMOTION:
                    printf("position x = %d,\n posisition y = %d", event.motion.x, event.motion.y);
                    
                    if (event.motion.x > 25 && event.motion.x <= 150 && event.motion.y > 20 && event.motion.y <= 100)
                    {
                        afficher(back1, ecran);
                        Mix_PlayChannel(-1, son, 0);
                    }
                    else
                    {
                        afficher(back0,ecran);
                    }
                     if (event.motion.x > 830 && event.motion.x <= 900 && event.motion.y > 370 && event.motion.y <= 450)
                    {
                        afficher(plus1, ecran);
                        Mix_PlayChannel(-1, son, 0);
                    }
                    else
                    {
                        afficher(plus,ecran);
                    }
                    if (event.motion.x > 380 && event.motion.x <= 450 && event.motion.y > 370 && event.motion.y <= 450)
                    {
                       afficher(moin1,ecran);
                        Mix_PlayChannel(-1, son, 0);
                    }
                    else
                    {
                        afficher(moin,ecran);
                    }
                    if(event.motion.x > 1000 && event.motion.x <= 1100 && event.motion.y > 20 && event.motion.y <= 100){
                       afficher(fullscreen1,ecran);
                        Mix_PlayChannel(-1, son, 0);
                    }
                    else {
                        afficher(fullscreen0,ecran);
                    }
                    SDL_Flip(ecran);
                    break;
//////////////////////////////////////////////////////////////////////////////////////////////////////



case SDLK_ESCAPE:
menu();
        break;

case SDL_MOUSEBUTTONDOWN:
    if (event.button.button == SDL_BUTTON_LEFT) {
                        printf("position x = %d,\n posisition y = %d", event.motion.x, event.motion.y);
                    
                    if (event.motion.x > 25 && event.motion.x <= 150 && event.motion.y > 20 && event.motion.y <= 120)
                    {
                       continuer = 0;
                       menu();

                    }

                     if (event.motion.x > 830 && event.motion.x <= 900 && event.motion.y > 370 && event.motion.y <= 450)
                    {
                        
                        
                         musicVolume = music_volume_up(musicVolume, ecran, v1, v2, v3, v4);

                         SDL_Flip(ecran);
                    }

                    if (event.motion.x > 380 && event.motion.x <= 450 && event.motion.y > 370 && event.motion.y <= 450)
                    {
                       
                        
                         musicVolume = music_volume_down(musicVolume, ecran, v1, v2, v3, v4);
                         SDL_Flip(ecran);
                    }
                     if (event.motion.x > 380 && event.motion.x <= 450 && event.motion.y > 370 && event.motion.y <= 450)
                    {
                      
                    }

                    
                    break;

          

    
    }

    // Assuming this is the button for mute/unmute
    if (event.button.button == SDL_BUTTON_X1) {
        if (event.motion.x > 25 && event.motion.x <= 60 && event.motion.y > 20 && event.motion.y <= 60) {
            Mix_PlayChannel(1, son, 0);
            musicVolume = music_mute_unmute(musicVolume);
        }
    }
break;
case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_o) {
                    musicVolume = music_volume_up(musicVolume, ecran, v1, v2, v3, v4);
                } else if (event.key.keysym.sym == SDLK_p) {
                    musicVolume = music_volume_down(musicVolume, ecran, v1, v2, v3, v4);
                } else if (event.key.keysym.sym == SDLK_m) {
                    musicVolume = music_mute_unmute(musicVolume);
                }
                break;
 

        SDL_Flip(ecran);
    }
}

    // Free memory and quit SDL
    liberer(background);
    liberer(v1);
    liberer(v2);
    liberer(v3);
    liberer(v4);
    liberer(back0);
    liberer(back1);
    liberer(fullscreen0);
    liberer(fullscreen1);
    liberer(plus);
    liberer(moin);
    liberer(moin1);
    liberer(plus1);
    liberer(barr);
    SDL_Quit();
}
/////////////////////////////////////////////////////resolutionnnn////////////////////////////////////////////////
int full_screen_mode_on_off(SDL_Surface *ecran,int fullscreen)
{SDL_Surface* make_window() {
    // Create a window surface with the desired dimensions
    SDL_Surface* windowSurface = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (!windowSurface) {
        fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
        return NULL;
    }
    return windowSurface;
}
    if (fullscreen == 0) 
    {
        ecran = SDL_SetVideoMode(800 ,600, 32, SDL_FULLSCREEN|SDL_HWSURFACE );
        fullscreen = 1;
    }
    else 
    {
        ecran = make_window(); // 0 means windowed mode
        fullscreen = 0;
    }
    return fullscreen;
}

////////////////////////////////////////////////////////music/////////////////////////////////////////////////////////////////

int music_volume_up(int volume, SDL_Surface* ecran, image v1, image v2, image v3, image v4) {
    if (volume < 100) {
        if (volume < 25) {
            volume += 5;
            afficher(v1, ecran);
            SDL_Flip(ecran);
        } else if (volume < 50) {
            volume += 10;
            afficher(v2, ecran);
            SDL_Flip(ecran);
        } else if (volume < 75) {
            volume += 15;
            afficher(v3, ecran);
            SDL_Flip(ecran);
        } else {
            volume += 20;
            afficher(v4, ecran);    
            SDL_Flip(ecran);
        }
    }
    Mix_VolumeMusic(volume);
    return volume;
}

int music_volume_down(int volume, SDL_Surface* ecran, image v1, image v2, image v3, image v4) {
    if (volume > 0) {
        if (volume <= 25) {
            volume -= 5;
            liberer(v4);
            //SDL_Flip(ecran);
        } else if (volume <= 50) {
            volume -= 10;
            liberer(v3);
           // SDL_Flip(ecran);
        } else if (volume <= 75) {
            volume -= 15;
            liberer(v2);
           // SDL_Flip(ecran);
        } else {
            volume -= 20;
            liberer(v1);
           // SDL_Flip(ecran);
        }
    }
    Mix_VolumeMusic(volume);
    return volume;
}

int music_mute_unmute(int volume) {
    if (volume) {
        volume = 0;
    } else {
        volume = 100;
    }
    Mix_VolumeMusic(volume);
    return volume;
}   