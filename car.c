//
// Created by soufiane on 17/11/2020.
//

#include "src/modules/car.h"


SDL_Surface* draw_car(){
    SDL_Surface* car_img = IMG_Load("resources/img/car.png");
    /*if(!car_img){
        printf("Error while loading image: %s", SDL_GetError());
        return EXIT_FAILURE;
    }*/

    return car_img;

    //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
}


int move_car(SDL_Event e, float deltatime, SDL_Rect* location, SDL_Rect* car, float* move, int running, int solidLines){
    switch(e.key.keysym.sym){
        case SDLK_ESCAPE:
            running = 0;
            break;
        case SDLK_RIGHT:
            if(car->x + car->w < location->x + location->w - solidLines - 8){
                *move+= 2.0f * deltatime;
                car->x += *move;
            }
            break;
        case SDLK_LEFT:
            if(car->x > location->x + solidLines + 8){
                *move+= 2.0f * deltatime;
                car->x -= *move;
            }
            break;
    }
}


void destroy_car(SDL_Texture* carTxt, SDL_Surface* car_img){
    // free texture memory space
    SDL_DestroyTexture(carTxt);
    // free surface memory space
    SDL_FreeSurface(car_img);
}


//int computeSpeed(){}