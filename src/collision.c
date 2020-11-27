//
// Created by Alex on 20/11/2020.
//

#include "modules/collision.h"

int collisiondetection(SDL_Rect* car, SDL_Rect* car_obstacle,SDL_Rect* car_obstacle2,SDL_Rect* car_obstacle3, int speed){

    int collision = 1;

    //Les cotes des rectangles
    int leftCar, leftOb1, leftOb2, leftOb3;
    int rightCar, rightOb1, rightOb2, rightOb3;
    int topCar, topOb1, topOb2, topOb3;
    int bottomCar, bottomOb1, bottomOb2, bottomOb3;

    //Calcul les cotes du rectangle car
    leftCar = car->x;
    rightCar = car->x + car->w;
    topCar = car->y;
    bottomCar = car->y + car->h;

    //Calcul les cotes du rectangle car_obstacle
    leftOb1 = car_obstacle->x;
    rightOb1 = car_obstacle->x + car_obstacle->w;
    topOb1 = car_obstacle->y;
    bottomOb1 = car_obstacle->y + car_obstacle->h;

    //Calcul les cotes du rectangle car_obstacle2
    leftOb2 = car_obstacle2->x;
    rightOb2 = car_obstacle2->x + car_obstacle2->w;
    topOb2 = car_obstacle2->y;
    bottomOb2 = car_obstacle2->y + car_obstacle2->h;

    //Calcul les cotes du rectangle car_obstacle3
    leftOb3 = car_obstacle3->x;
    rightOb3 = car_obstacle3->x + car_obstacle3->w;
    topOb3 = car_obstacle3->y;
    bottomOb3 = car_obstacle3->y + car_obstacle3->h;

    //Tests de collision
    if( topCar <= bottomOb1 && leftCar <= rightOb1 && rightCar >= leftOb1 )
    {
        collision = 0;
        return collision;
    }

    if( topCar <= bottomOb2 && leftCar <= rightOb2 && rightCar >= leftOb2 )
    {
        collision = 0;
        return collision;
    }

    if( topCar <= bottomOb3 && leftCar <= rightOb3 && rightCar >= leftOb3 )
    {
        collision = 0;
        return collision;
    }

    //Si conditions collision detectee
    return collision;
}

