//

// Created by Alex on 18/11/2020.
//

#include "modules/obstacles.h"
#include "modules/collision.h"

//float bouge = 0;
int newx = ROAD_LEFT;
int newx2 = 0;
int newx3 = 0;
SDL_Surface* obstacle_img = NULL;

//SDL_Texture *obstacles_txt[3];

SDL_Texture *texture_obstacle = NULL;
SDL_Texture *texture_obstacle2 = NULL;
SDL_Texture *texture_obstacle3 = NULL;


int load_obstacle(){
    obstacle_img = IMG_Load("resources/img/wood.png");
    if (!obstacle_img) {
        printf("Error while loading image: %s", SDL_GetError());
        return EXIT_FAILURE;
    }



    texture_obstacle = SDL_CreateTextureFromSurface(renderer, obstacle_img);
    texture_obstacle2 = SDL_CreateTextureFromSurface(renderer, obstacle_img);
    texture_obstacle3 = SDL_CreateTextureFromSurface(renderer, obstacle_img);

    //obstacles_txt = { texture_obstacle, texture_obstacle2, texture_obstacle3 };
}


int randomize_obstacles(int speed, SDL_Rect* car_obstacle, SDL_Rect* car_obstacle2, SDL_Rect* car_obstacle3){
    SDL_Rect src = {0,0, SCREEN_WIDTH, SCREEN_HEIGHT};
//    SDL_Rect car_obstacle = { ROAD_LEFT,SCREEN_HEIGHT, WAY_WIDTH,obstacle_img->h/3 };
//    SDL_Rect car_obstacle2 = { ROAD_LEFT,SCREEN_HEIGHT, WAY_WIDTH,obstacle_img->h/3 };
//    SDL_Rect car_obstacle3 = { ROAD_LEFT,SCREEN_HEIGHT, WAY_WIDTH,obstacle_img->h/3 };
    car_obstacle->y += 5;
    car_obstacle2->y += 5;
    car_obstacle3->y += 5;

    if (car_obstacle->y  >= SCREEN_HEIGHT) {
        car_obstacle->y = 0;
        car_obstacle2->y = 0;
        car_obstacle3->y = 0;
        newx = rand() % 14;
        switch (newx){
            case 0 : //Voie de gauche
                newx=ROAD_LEFT;
                newx2 = 0;newx3=0; break;
            case 1 : //Seconde voie
                newx=ROAD_LEFT+WAY_WIDTH+DASHED_WIDTH;
                newx2=0 ;newx3=0;break;
            case 2 : //Troisième voie
                newx=ROAD_LEFT+WAY_WIDTH*2+DASHED_WIDTH*2;
                newx2 = 0 ;newx3=0; break;
            case 3 : // Quatrième Voie
                newx=ROAD_LEFT+WAY_WIDTH*3+DASHED_WIDTH*3;
                newx2 = 0;newx3=0;break;
            case 4 : // 1 + 2
                newx=ROAD_LEFT;
                newx2=ROAD_LEFT+WAY_WIDTH+DASHED_WIDTH;
                newx3=0;
                break;
            case 5 : // 1 + 3
                newx=ROAD_LEFT;
                newx2=ROAD_LEFT+WAY_WIDTH*2+DASHED_WIDTH*2;
                newx3=0;
                break;
            case 6 : // 1 + 4
                newx=ROAD_LEFT;
                newx2=ROAD_LEFT+WAY_WIDTH*3+DASHED_WIDTH*3;
                newx3=0;
                break;
            case 7 : // 2 + 3
                newx=ROAD_LEFT+WAY_WIDTH+DASHED_WIDTH;
                newx2=ROAD_LEFT+WAY_WIDTH*2+DASHED_WIDTH*2;
                newx3=0;
                break;
            case 8 : // 2 + 4
                newx=ROAD_LEFT+WAY_WIDTH+DASHED_WIDTH;
                newx2=ROAD_LEFT+WAY_WIDTH*3+DASHED_WIDTH*3;
                newx3=0;
                break;
            case 9 : // 3 + 4
                newx=ROAD_LEFT+WAY_WIDTH*2+DASHED_WIDTH*2;
                newx2=ROAD_LEFT+WAY_WIDTH*3+DASHED_WIDTH*3;
                newx3=0;
                break;
            case 10 : // 1+2+3
                newx=ROAD_LEFT;
                newx2=ROAD_LEFT+WAY_WIDTH+DASHED_WIDTH;
                newx3=ROAD_LEFT+WAY_WIDTH*2+DASHED_WIDTH*2;
                break;
            case 11 : // 2+3+4
                newx=ROAD_LEFT+WAY_WIDTH+DASHED_WIDTH;
                newx2=ROAD_LEFT+WAY_WIDTH*2+DASHED_WIDTH*2;
                newx3=ROAD_LEFT+WAY_WIDTH*3+DASHED_WIDTH*3;
                break;
            case 12 : // 1+3+4
                newx=ROAD_LEFT;
                newx2=ROAD_LEFT+WAY_WIDTH*2+DASHED_WIDTH*2;
                newx3=ROAD_LEFT+WAY_WIDTH*3+DASHED_WIDTH*3;
                break;
            case 13 : // 1+2+4
                newx=ROAD_LEFT;
                newx2=ROAD_LEFT+WAY_WIDTH+DASHED_WIDTH;
                newx3=ROAD_LEFT+WAY_WIDTH*3+DASHED_WIDTH*3;
                break;
        }
//        printf("%d\n", newx);

//        _sleep(500);
    }
    car_obstacle->x = newx;
    car_obstacle2->x = newx2;
    car_obstacle3->x = newx3;
    SDL_RenderCopy(renderer, texture_obstacle, &src, car_obstacle);

    if (newx2 != 0){
        SDL_RenderCopy(renderer, texture_obstacle2, &src, car_obstacle2);
    }
    if (newx3 != 0){
        SDL_RenderCopy(renderer, texture_obstacle3, &src, car_obstacle3);
    }

    return newx;
}


void destroy_obstacle(){
    // free surface memory space
    SDL_FreeSurface(obstacle_img);
}