//
// Created by Alex on 23/11/2020.
//

#ifndef DRIVEORDIE_MENU_H
#define DRIVEORDIE_MENU_H
#include "main.h"

int menu_display(SDL_Event);
int load_menu();
void destroy_menu();
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *background;


#endif //DRIVEORDIE_MENU_H
