//
// Created by soufiane on 17/11/2020.
//

#ifndef DRIVEORDIE_MAIN_H
#define DRIVEORDIE_MAIN_H

// include libraries
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern SDL_Surface* car_img;
extern SDL_Texture* car_txt;
extern SDL_Surface* menu_img;
extern SDL_Texture* menu_txt;
extern SDL_Surface* play_button;
extern SDL_Texture* play_button_txt;
extern SDL_Surface* obstacle_img;
extern SDL_Texture* texture_obstacle;
extern SDL_Texture* texture_obstacle2;
extern SDL_Texture* texture_obstacle3;

// define constants
#define SCREEN_WIDTH 840
#define SCREEN_HEIGHT 680

#endif //DRIVEORDIE_MAIN_H
