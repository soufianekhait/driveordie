//
// Created by soufiane on 17/11/2020.
//

#include "modules/car.h"

SDL_Surface* car_img = NULL;
SDL_Texture* car_txt = NULL;


int load_car(){
    car_img = IMG_Load("resources/img/car.png");
    if(!car_img){
        printf("Error while loading image: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    car_txt = SDL_CreateTextureFromSurface(renderer, car_img);
    if(car_txt == NULL){
        printf("Error while creating texture from surface: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
}


int move_car(SDL_Event e, float deltaTime, SDL_Rect* location, SDL_Rect* car, float* move, int running, int solidLines){
    switch(e.key.keysym.sym){
        case SDLK_ESCAPE:
            running = 0;
            break;
        case SDLK_RIGHT:
            if(car->x + car->w < location->x + location->w - solidLines - 8){
                //*move+= 25.0f * deltaTime;
                //car->x += *move;
                //On a essayé de rendre le déplacement "smooth" mais le deltaTime augmentant le jeu devient injouable
                car->x += 6;
            }
            break;
        case SDLK_LEFT:
            if(car->x > location->x + solidLines + 8){
                //*move+= 25.0f * deltaTime;
                //car->x -= *move;
                car->x -= 6;
            }
            break;
    }
}


void destroy_car(){
    // free texture memory space
    SDL_DestroyTexture(car_txt);
    // free surface memory space
    SDL_FreeSurface(car_img);
}