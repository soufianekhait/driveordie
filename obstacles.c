//
// Created by Alex on 18/11/2020.
//

#include "obstacles.h"

//float bouge = 0;
int newx = ROAD_LEFT;
int newx2 = 0;
int newx3 = 0;

int random_obstacles(SDL_Renderer* renderer, SDL_Texture* texture_obstacle,SDL_Texture* texture_obstacle2,SDL_Texture* texture_obstacle3, int speed, SDL_Surface* obstacle){
    SDL_Rect src = {0,0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_Rect car_obstacle = { ROAD_LEFT,SCREEN_HEIGHT, WAY_WIDTH,obstacle->h/3 };
    SDL_Rect car_obstacle2 = { ROAD_LEFT,SCREEN_HEIGHT, WAY_WIDTH,obstacle->h/3 };
    SDL_Rect car_obstacle3 = { ROAD_LEFT,SCREEN_HEIGHT, WAY_WIDTH,obstacle->h/3 };
    car_obstacle.y -= speed;
    car_obstacle2.y -= speed;
    car_obstacle3.y -= speed;
    /*Entity *enemy;

    if (--enemySpawnTimer <= 0){
        enemy = malloc(sizeof(Entity));
        memset(enemy, 0, sizeof(Entity));

        enemy->x = rand() %SCREEN_WIDTH;
        enemy->y = -50;
        enemy->texture = enemyTexture;
        enemy->dy = 8;
        enemy->health = 1;

        enemySpawnTimer = 30 + (rand() % 5);*/
    //car.x = rand() % (SCREEN_WIDTH/4 + SCREEN_WIDTH/2);
    //printf("%d\n", car.y);
    if (car_obstacle.y  <= 0) {
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
                printf("10");
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
    car_obstacle.x = newx;
    car_obstacle2.x = newx2;
    car_obstacle3.x = newx3;
    SDL_RenderCopy(renderer, texture_obstacle, &src, &car_obstacle);

    if (newx2 != 0){
        SDL_RenderCopy(renderer, texture_obstacle2, &src, &car_obstacle2);
    }
    if (newx3 != 0){
        SDL_RenderCopy(renderer, texture_obstacle3, &src, &car_obstacle3);
    }

    return newx;
}
