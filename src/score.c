//
// Created by soufiane on 26/11/2020.
//

#include "modules/score.h"

TTF_Font* font = NULL;


int destroyScore(){
    TTF_CloseFont(font);
}


int displayScore(int score){
    font = TTF_OpenFont("./resources/font/VIDEOPHREAK.ttf", 100);
    SDL_Rect aire = { SCREEN_WIDTH/2 - 70, 50,100, 100};
    char buffer[20];

    if(font){
        SDL_Color color = { 255, 255, 255 };
        SDL_Surface *surface = TTF_RenderText_Solid(font, itoa(score, buffer, 10), color);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        //SDL_SetRenderTarget(renderer, texture);
        SDL_QueryTexture(texture, NULL, NULL, &aire.w, &aire.h);
        SDL_RenderCopy(renderer, texture, NULL, &aire);
    } else{
        printf("TTF_OpenFont Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    return 1;
}


double computeScore(double score){
    // score is incremented every sec
    score += 0.01;
    return score;
}