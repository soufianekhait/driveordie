#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "Road.h"

const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 680;

int main(int argc, char *argv[]){
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    int statut = EXIT_FAILURE;
    SDL_Color orange = {255, 127, 40, 255};

    /* Initialisation, création de la fenêtre et du renderer. */
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr, "SDL_Init Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("Drive or Die",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    SDL_SetWindowTitle(window, "DriveOrDie");

    if(window == NULL){
        fprintf(stderr, "SDL_CreateWindow Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        fprintf(stderr, "SDL_CreateRenderer Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    /* C’est à partir de maintenant que ça se passe. */
    if(SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a) < 0){
        fprintf(stderr, "SDL_SetRenderDrawColor Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    if(SDL_RenderClear(renderer) != 0){
        fprintf(stderr, "SDL_RenderClear Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    road(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}