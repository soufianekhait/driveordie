//
// Created by Alex on 18/11/2020.
//

#ifndef DRIVEORDIE_OBSTACLES_H
#define DRIVEORDIE_OBSTACLES_H
#include "road.h"

int random_obstacles(SDL_Renderer*, SDL_Texture*,SDL_Texture*,SDL_Texture*, int, SDL_Surface*);
SDL_Surface* draw_obstacles();
void destroy_obstacles(SDL_Surface* obstacle);

#endif //DRIVEORDIE_OBSTACLES_H
