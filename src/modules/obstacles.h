//
// Obstacle module
//

#ifndef DRIVEORDIE_OBSTACLES_H
#define DRIVEORDIE_OBSTACLES_H

// include modules
#include "road.h"

#define WAY_WIDTH 91.25

// signatures
int randomize_obstacles(int speed, SDL_Rect*, SDL_Rect*, SDL_Rect*);
int load_obstacle();
void destroy_obstacle();

#endif //DRIVEORDIE_OBSTACLES_H
