//
// Created by Alex on 18/11/2020.
//

#ifndef DRIVEORDIE_OBSTACLES_H
#define DRIVEORDIE_OBSTACLES_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Road.h"
#define SCREEN_WIDTH 840
#define SCREEN_HEIGHT 680
#define WAY_WIDTH 91.25
#define DASHED_WIDTH 5
#define ROAD_LEFT 230 //(SCREEN_WIDTH/4)+20
#define ROAD_SIZE 380


int random_obstacles(SDL_Renderer*, SDL_Texture*,SDL_Texture*,SDL_Texture*, int, SDL_Surface*);

#endif //DRIVEORDIE_OBSTACLES_H
