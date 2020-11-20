//
// Car module
//

#ifndef DRIVEORDIE_CAR_H
#define DRIVEORDIE_CAR_H

// include modules
#include "road.h"

// signatures
int load_car();
int move_car(SDL_Event e, float deltaTime, SDL_Rect* camera, SDL_Rect* dimensions, float* move, int running, int solidLines);
void destroy_car();

#endif //DRIVEORDIE_CAR_H
