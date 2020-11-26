/*
 *  Including Road module
 */

#include "modules/road.h"
#include "modules/car.h"
#include "modules/obstacles.h"
#include "modules/background.h"
#include "modules/collision.h"
#include "modules/game_over.h"
#include "modules/menu.h"


void draw_solidLines(SDL_Rect solidLines[]){
    // Assign dimensions to solid lines
    for(int i=0; i<8; i++){
        solidLines[i].w = 15;
        solidLines[i].h = 320;
    }

    // Set solid lines positions
    int cpt = 4;
    int y_pos = 5;
    for(int j=0; j<8; j++){
        if (j<4) {
            solidLines[j].x = solidLines[j+1].x = (SCREEN_WIDTH/4) + 5;
            solidLines[j].y = solidLines[cpt].y = y_pos;
            y_pos += SCREEN_HEIGHT/2;
            cpt ++;
        } else {
            solidLines[j].x = solidLines[j+1].x = SCREEN_WIDTH - ((SCREEN_WIDTH/4) + solidLines[j].w + 5);
        }
    }

    // fill solid lines with white color
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}


void draw_dashedLines(SDL_Rect dashedLines[]){
    // set dashed lines dimensions
    for(int i=0; i<32; i++){
        dashedLines[i].w = DASHED_WIDTH;
        dashedLines[i].h = 60;
    }

    // set dashed lines positions
    int pos = 25;
    for (int j=0; j<32; j++){
        if (j<10)
            dashedLines[j].x = ROAD_LEFT+ WAY_WIDTH;
        else if (j<20){
            dashedLines[j].x = ROAD_LEFT + DASHED_WIDTH + WAY_WIDTH*2;
            if (j==10) pos = 25;
        } else{
            dashedLines[j].x = ROAD_LEFT + DASHED_WIDTH*2 + WAY_WIDTH*3;
            if (j==20) pos = 25;
        }
        dashedLines[j].y = pos;
        pos += SCREEN_HEIGHT/5;
    }

    // set dashed lines color
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}


int draw_road() {
    // Set target
    SDL_SetRenderTarget(renderer, background);
    // define a rectangle
    SDL_Rect route = {SCREEN_WIDTH / 4, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT * 2};
    // fill it with brown color
    SDL_SetRenderDrawColor(renderer, 201, 173, 167, 0);
    // draw rectangle
    SDL_RenderFillRect(renderer, &route);

    // draw solid lines
    SDL_Rect solidLines[8];
    draw_solidLines(solidLines);

    if (SDL_RenderFillRects(renderer, solidLines, 8) < 0) {
        printf("SDL_RenderFillRects for solid lines: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // draw dashed lines
    SDL_Rect dashedLines[32];
    draw_dashedLines(dashedLines);

    if (SDL_RenderFillRects(renderer, dashedLines, 32) < 0) {
        printf("SDL_RenderFillRects for dashed lines: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    return 0;
}


int move_road() {
    int running = 1;
    float move = 0;
    int collision = 0;
    const int FPS = 60;
    const int speed = 5;
    Uint32 start;
    SDL_Rect location = { SCREEN_WIDTH/4, SCREEN_HEIGHT, SCREEN_WIDTH/2, SCREEN_HEIGHT };
    SDL_Rect camera = {SCREEN_WIDTH/4, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT };
    // car source on texture and car dest on render
    SDL_Rect carOnTxt = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    SDL_Rect carOnRnd = { SCREEN_WIDTH/2 - car_img->w/6 , SCREEN_HEIGHT - car_img->h/3 - 10, car_img->w/3,car_img->h/3 };

    //obstacles source
    int newHeight = obstacle_img->h/3;
    SDL_Rect car_obstacle = { ROAD_LEFT,0, WAY_WIDTH, newHeight };
    SDL_Rect car_obstacle2 = { ROAD_LEFT,0, WAY_WIDTH,newHeight };
    SDL_Rect car_obstacle3 = { ROAD_LEFT,0, WAY_WIDTH,newHeight };

    //background source
    SDL_Rect rcGrass = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    SDL_Rect grass = { 0, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT };

    while(running){
        SDL_Event e;
        float deltaTime = (SDL_GetTicks() - start) / 1000.0f;
        while (SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    move_car(e, deltaTime, &location, &carOnRnd, &move, running, 15);
                    break;
            }
        }
        //Road movement
        start = SDL_GetTicks();
        location.y -= speed;
        if (location.y <= 0) {
            location.y = location.h;
        }
        // Background movement
        grass.y -= 3;
        if (grass.y <= 0)
            grass.y = grass.h;

        //display road
        display(location, camera, carOnTxt, carOnRnd, grass, rcGrass, &car_obstacle, &car_obstacle2, &car_obstacle3);

        if(1000/FPS > SDL_GetTicks()-start){
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }
        //In case of detection
        if (collisiondetection(&carOnRnd, &car_obstacle, &car_obstacle2, &car_obstacle3, speed)==0){
            collision = 1;
            return collision;
        }
    }
    return running;
}


void display(SDL_Rect location, SDL_Rect camera, SDL_Rect src, SDL_Rect car, SDL_Rect grass, SDL_Rect rcGrass, SDL_Rect* car_obstacle, SDL_Rect* car_obstacle2, SDL_Rect* car_obstacle3){
    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopy(renderer, grass_txt, &grass, &rcGrass);
    SDL_RenderCopy(renderer, background, &location, &camera);
    SDL_RenderCopy(renderer, car_txt, &src, &car);
    randomize_obstacles(location.y, car_obstacle, car_obstacle2, car_obstacle3);
    // Show renderer's content
    SDL_RenderPresent(renderer);
}