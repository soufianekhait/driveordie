//
// Created by soufiane on 24/11/2020.
//

#ifndef DRIVEORDIE_BACKGROUND_H
#define DRIVEORDIE_BACKGROUND_H

#include "main.h"

int load_background();
void move_background(SDL_Rect grass, SDL_Rect rcGrass);

extern SDL_Renderer *renderer;
extern SDL_Texture *grass_txt;
extern SDL_Texture *background;

#endif //DRIVEORDIE_BACKGROUND_H
