//
// Created by soufiane on 17/11/2020.
//

#ifndef DRIVEORDIE_CAR_H
#define DRIVEORDIE_CAR_H

#include "road.h"

SDL_Surface* draw_car();
int move_car(SDL_Event e, float deltatime, SDL_Rect* camera, SDL_Rect* dimensions, float* move, int running, int solidLines);
void destroy_car(SDL_Texture* carTxt, SDL_Surface* car_img);

#endif //DRIVEORDIE_CAR_H
