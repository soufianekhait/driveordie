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


void wait(float time){
    clock_t end = clock()+(time*CLOCKS_PER_SEC);
    // Clock() retourne le nombre de tick par seconde. On calcule le moment où le wait devra s'arrêter

    while(clock()<end);
}


int function_score(){
    int score = 0;
    do{
        printf("Score = %04d\n", score);
        wait(1); // score is incremented every sec
        score++;
    }while(score<=120); //While score is < 120, score++
    do{
        printf("Score = %04d\n", score);
        wait(1);
        score+=2;
    }while(score<=240);
    do{
        printf("Score = %04d\n", score);
        wait(1);
        score+=5;
    }while(score<=360);
    do{
        printf("Score = %04d\n", score);
        wait(1);
        score+=10;
    }while(score>=360);

    return score;
}