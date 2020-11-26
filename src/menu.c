//
// Created by Alex on 23/11/2020.
//

#include "modules/menu.h"

SDL_Surface* menu_img = NULL;
SDL_Texture* menu_txt = NULL;
SDL_Surface* play_button = NULL;
SDL_Texture* play_button_txt = NULL;
SDL_Surface* quit_button = NULL;
SDL_Texture* quit_button_txt = NULL;


int load_menu() {
    menu_img = IMG_Load("resources/img/Menu.png");
    if (!menu_img) {
        printf("Error while loading image: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    menu_txt = SDL_CreateTextureFromSurface(renderer, menu_img);
    if (menu_txt == NULL) {
        printf("Error while creating texture from surface: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    play_button = IMG_Load("resources/img/play_button.png");
    if (!play_button) {
        printf("Error while loading image: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    play_button_txt = SDL_CreateTextureFromSurface(renderer, play_button);
    if (play_button_txt == NULL) {
        printf("Error while creating texture from surface: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    quit_button = IMG_Load("resources/img/quit_button.png");
    if (!quit_button) {
        printf("Error while loading image: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    quit_button_txt = SDL_CreateTextureFromSurface(renderer, quit_button);
    if (quit_button_txt == NULL) {
        printf("Error while creating texture from surface: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Rect srcmenu = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_Rect destplay = {300, 190, 240, 235};
    SDL_Rect destquit = {310, 450, 200, 200};
    SDL_SetRenderTarget(renderer, NULL);

    SDL_RenderCopy(renderer, menu_txt, &srcmenu, NULL);
    SDL_RenderCopy(renderer, play_button_txt, &srcmenu, &destplay);
    SDL_RenderCopy(renderer, quit_button_txt, &srcmenu, &destquit);
    // Show renderer's content
    SDL_RenderPresent(renderer);

    SDL_Rect buttonPlay = {300, 190, 240, 235};
    SDL_Rect buttonQuit = {310, 450, 200, 200};
    SDL_Event emenu;
    int continuer = 1;
    while (continuer == 1) {
        SDL_WaitEvent(&emenu); /// attente d'un event
        switch (emenu.type) {
            case SDL_MOUSEBUTTONDOWN:
                switch(emenu.button.button) {
                    case SDL_BUTTON_LEFT:
                        if (emenu.motion.x >= buttonPlay.x
                            && emenu.motion.x < buttonPlay.x + buttonPlay.w
                            && emenu.motion.y >= buttonPlay.y
                            && emenu.motion.y < buttonPlay.y + buttonPlay.h) {
                            continuer = 2;
                        }
                        if (emenu.motion.x >= buttonQuit.x
                            && emenu.motion.x < buttonQuit.x + buttonQuit.w
                            && emenu.motion.y >= buttonQuit.y
                            && emenu.motion.y < buttonQuit.y + buttonQuit.h) {
                            continuer = 0;
                        }
                        break;
                }
                break;
            case SDL_QUIT: /// si type = SDL_QUIT
                continuer = 0;
                break;
            case SDL_KEYDOWN: /// si type = TOUCHE APPUYE
                switch (emenu.key.keysym.sym) {
                    case SDLK_ESCAPE: /// si touche = ECHAP
                        continuer = 0;
                        break;
                }
            break;
        }
    }
    SDL_RenderClear(renderer);

    return continuer;
}

void destroy_menu(){
    // free texture memory space
    SDL_DestroyTexture(menu_txt);
    SDL_DestroyTexture(play_button_txt);
    // free surface memory space
    SDL_FreeSurface(menu_img);
    SDL_FreeSurface(play_button);
}
