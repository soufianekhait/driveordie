// Road.c
#include "Road.h"


int init_road(SDL_Renderer* renderer){
    // define a rectangle
    SDL_Rect route = { SCREEN_WIDTH/4, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT*2 };
    // fill it with brown color
    SDL_SetRenderDrawColor(renderer, 201, 173, 167, 0);
    // draw rectangle
    SDL_RenderFillRect(renderer, &route);

    SDL_Rect solidLines[7];
    // Assign dimensions to solid lines
    for(int i=0; i<7; i++){
        solidLines[i].w = 15;
        solidLines[i].h = 320;
    }

    // Set solid lines positions
    int cpt = 4;
    int y = 5;
    for(int j=0; j<7; j++){
        if (j<4) {
            solidLines[j].x = solidLines[j+1].x = (SCREEN_WIDTH/4) + 5;
            solidLines[j].y = solidLines[cpt].y = y;
            y += SCREEN_HEIGHT/2;
            cpt ++;
        } else {
            solidLines[j].x = solidLines[j+1].x = SCREEN_WIDTH - ((SCREEN_WIDTH/4) + solidLines[j].w + 5);
        }
    }

    // fill solid lines with white color
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    // draw rectangles
    if(SDL_RenderFillRects(renderer, solidLines, 7) < 0){
        printf("SDL_RenderFillRects for solid lines: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // set dashed lines dimensions
    SDL_Rect dashedLines[18];
    for(int i=0; i<18; i++){
        dashedLines[i].w = 5;
        dashedLines[i].h = 60;
    }

    // set dashed lines positions
    int pos = 25;
    for (int j=0; j<18; j++){
        if (j<6)
            dashedLines[j].x = (SCREEN_WIDTH/3) + 30;
        else if (j<12){
            dashedLines[j].x = (SCREEN_WIDTH/2) - dashedLines[j].w;
            if (j==6) pos = 25;
        } else{
            dashedLines[j].x = SCREEN_WIDTH - ((SCREEN_WIDTH/3) + 30);
            if (j==12) pos = 25;
        }
        dashedLines[j].y = pos;
        pos += SCREEN_HEIGHT/5;
    }

    // set dashed lines color
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    // draw dashed lines
    if(SDL_RenderFillRects(renderer, dashedLines, 18) < 0){
        printf("SDL_RenderFillRects for dashed lines: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    /*SDL_Surface* image = IMG_Load("resources/img/car.png");
    if(!image){
        printf("Error while loading image: %s",SDL_GetError());
        return -1;
    }
    // free surface memory space
    SDL_FreeSurface(image);*/

    //SDL_RenderSetViewport(renderer, &route);
    // Show renderer's content
    SDL_RenderPresent(renderer);

    // while the user doesn't close the window
    int quit = 0;
    SDL_Event e;
    while (!quit){
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = 1;
        }
    }

    return 0;
}