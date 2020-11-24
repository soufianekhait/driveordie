// Road.h
#ifndef DRIVEORDIE_ROAD_H
#define DRIVEORDIE_ROAD_H

// include modules
#include "main.h"

// define constants
#define ROAD_LEFT (SCREEN_WIDTH/4)+20
#define ROAD_RIGHT (SCREEN_WIDTH - ((SCREEN_WIDTH/4)-20)
#define DASHED_WIDTH 5

// define signatures
int draw_road();
int move_road();
void draw_dashedLines(SDL_Rect tab[]);
void draw_solidLines(SDL_Rect tab[]);
void display(SDL_Rect location, SDL_Rect camera, SDL_Rect src, SDL_Rect car, SDL_Rect*, SDL_Rect*, SDL_Rect*);


extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *background;

#endif //DRIVEORDIE_ROAD_H