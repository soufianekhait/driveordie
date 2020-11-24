

#include "src/modules/background.h"


int load_background() {
    SDL_Surface *grass_img = IMG_Load("resources/img/soil.png");
    if (!grass_img) {
        printf("Error while loading image: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    grass_txt = SDL_CreateTextureFromSurface(renderer, grass_img);
    if (grass_txt == NULL) {
        printf("Error while creating texture from surface: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
}


/*void move_background(SDL_Rect grass, SDL_Rect rcGrass){
    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderTarget(renderer, grass_txt);
    // map the grass texture on the whole background
    for (int x = 0; x < SCREEN_WIDTH*2 / 100; x++) {
        for (int y = 0; y < SCREEN_HEIGHT*2 / 100; y++) {
            rcGrass.x = x * 100;
            rcGrass.y = y * 100;
            SDL_RenderCopy(renderer, grass_txt, &grass, &rcGrass);
        }
    }
    SDL_SetRenderTarget(renderer, background);
}*/