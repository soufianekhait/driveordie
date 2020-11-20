// Road.h
#ifndef DRIVEORDIE_ROAD_H
#define DRIVEORDIE_ROAD_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SCREEN_WIDTH 840
#define SCREEN_HEIGHT 680
#define ROAD_LEFT 230 //(SCREEN_WIDTH/4)+20
#define ROAD_RIGHT (SCREEN_WIDTH - ((SCREEN_WIDTH/4)-20)
#define DASHED_WIDTH 5
#define WAY_WIDTH 91.25

int init_road(SDL_Renderer*, SDL_Texture*);

#endif //DRIVEORDIE_ROAD_H
