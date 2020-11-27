//
// Created by soufiane on 26/11/2020.
//

#ifndef DRIVEORDIE_SCORE_H
#define DRIVEORDIE_SCORE_H

// include modules
#include "main.h"

int displayScore(int score);
int destroyScore();
double computeScore(double score);

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *background;

#endif //DRIVEORDIE_SCORE_H
