//
// Created by Alex on 24/11/2020.
//

#include "modules/game_over.h"

SDL_Surface* GO_img = NULL;
SDL_Texture* GO_txt = NULL;
SDL_Surface* restart_button = NULL;
SDL_Texture* restart_button_txt = NULL;
SDL_Surface* quitGO_button = NULL;
SDL_Texture* quitGO_button_txt = NULL;


int load_GO() {
    GO_img = IMG_Load("resources/img/game_over.png");
    if (!menu_img) {
        printf("Error while loading image: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    GO_txt = SDL_CreateTextureFromSurface(renderer, GO_img);
    if (GO_txt == NULL) {
        printf("Error while creating texture from surface: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    restart_button = IMG_Load("resources/img/restart_button.png");
    if (!restart_button) {
        printf("Error while loading image: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    restart_button_txt = SDL_CreateTextureFromSurface(renderer, restart_button);
    if (restart_button_txt == NULL) {
        printf("Error while creating texture from surface: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    quitGO_button = IMG_Load("resources/img/quit_buttonGO.png");
    if (!quitGO_button) {
        printf("Error while loading image: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    quitGO_button_txt = SDL_CreateTextureFromSurface(renderer, quitGO_button);
    if (quitGO_button_txt == NULL) {
        printf("Error while creating texture from surface: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Rect srcGO = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_Rect destrestart = {765, 500, 75, 75};
    SDL_Rect destquitGO = {765, 605, 75, 75};
    SDL_SetRenderTarget(renderer, NULL);

    SDL_RenderCopy(renderer, GO_txt, &srcGO, NULL);
    SDL_RenderCopy(renderer, restart_button_txt, &srcGO, &destrestart);
    SDL_RenderCopy(renderer, quitGO_button_txt, &srcGO, &destquitGO);
    //SDL_RenderFillRect(renderer, &test);
    // Show renderer's content
    SDL_RenderPresent(renderer);

    SDL_Rect buttonRestart = {765, 500, 75, 75};
    SDL_Rect buttonQuit = {765, 605, 75, 75};
    SDL_Event eGO;
    int continuer = 1;
    while (continuer == 1) {
        SDL_WaitEvent(&eGO); /// attente d'un event
        switch (eGO.type) {
            case SDL_MOUSEBUTTONDOWN:
                switch(eGO.button.button) {
                    case SDL_BUTTON_LEFT:
                        if (eGO.motion.x >= buttonRestart.x
                            && eGO.motion.x < buttonRestart.x + buttonRestart.w
                            && eGO.motion.y >= buttonRestart.y
                            && eGO.motion.y < buttonRestart.y + buttonRestart.h) {
                            continuer = 2;
                        }
                        if (eGO.motion.x >= buttonQuit.x
                            && eGO.motion.x < buttonQuit.x + buttonQuit.w
                            && eGO.motion.y >= buttonQuit.y
                            && eGO.motion.y < buttonQuit.y + buttonQuit.h) {
                            continuer = 0;
                        }
                        break;
                }
                break;
            case SDL_QUIT: /// si type = SDL_QUIT
                continuer = 0;
                break;
            case SDL_KEYDOWN: /// si type = TOUCHE APPUYE
                switch (eGO.key.keysym.sym) {
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

void destroy_GO(){
    // free texture memory space
    SDL_DestroyTexture(GO_txt);
    SDL_DestroyTexture(restart_button_txt);
    SDL_DestroyTexture(quitGO_button_txt);
    // free surface memory space
    SDL_FreeSurface(GO_img);
    SDL_FreeSurface(restart_button);
    SDL_FreeSurface(quitGO_button);
}

