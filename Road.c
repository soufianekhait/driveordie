// Road.c
#include "Road.h"


int init_road(SDL_Renderer* renderer, SDL_Texture* texture){
    SDL_SetRenderTarget(renderer, texture);
    // define a rectangle
    SDL_Rect route = { SCREEN_WIDTH/4, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT * 2 };
    //SDL_Rect route = { 0, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT };
    // fill it with brown color
    SDL_SetRenderDrawColor(renderer, 201, 173, 167, 0);
    // draw rectangle
    SDL_RenderFillRect(renderer, &route);

    SDL_Rect solidLines[8];
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
    // draw rectangles
    if(SDL_RenderFillRects(renderer, solidLines, 8) < 0){
        printf("SDL_RenderFillRects for solid lines: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    // set dashed lines dimensions
    SDL_Rect dashedLines[32];
    for(int i=0; i<32; i++){
        dashedLines[i].w = 5;
        dashedLines[i].h = 60;
    }

    // set dashed lines positions
    int pos = 25;
    for (int j=0; j<32; j++){
        if (j<10)
            dashedLines[j].x = (SCREEN_WIDTH/3) + 30;
        else if (j<20){
            dashedLines[j].x = (SCREEN_WIDTH/2) - dashedLines[j].w;
            if (j==10) pos = 25;
        } else{
            dashedLines[j].x = SCREEN_WIDTH - ((SCREEN_WIDTH/3) + 30);
            if (j==20) pos = 25;
        }
        dashedLines[j].y = pos;
        pos += SCREEN_HEIGHT/5;
    }

    // set dashed lines color
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    // draw dashed lines
    if(SDL_RenderFillRects(renderer, dashedLines, 32) < 0){
        printf("SDL_RenderFillRects for dashed lines: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    /*SDL_Surface* image = IMG_Load("resources/img/car.png");
    if(!image){
        printf("Error while loading image: %s",SDL_GetError());
        return -1;
    }*/


    int running = 1;
    const int FPS = 60;
    const int speed = 5;
    Uint32 start;
    //SDL_Rect imgloc = { 350,170,100,100 };
    SDL_Rect camera = { SCREEN_WIDTH/4, SCREEN_HEIGHT, SCREEN_WIDTH/2, SCREEN_HEIGHT };

    while(running){
        SDL_Event e;
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT)
                running = 0;
        }
        start = SDL_GetTicks();
        camera.y -= speed;
        if (camera.y <= 0)
            camera.y = camera.h;

        SDL_Rect location = {SCREEN_WIDTH/4, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT };
        SDL_SetRenderTarget(renderer, NULL);
        SDL_RenderCopy(renderer, texture, &camera, &location);
        //if(collision(&location, &imgloc))
            //SDL_BlitSurface(image, NULL, screen, &relcoord);

        SDL_RenderPresent(renderer);
        if(1000/FPS > SDL_GetTicks()-start){
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }
    }

    // Show renderer's content
    //SDL_RenderPresent(renderer);


    // while the user doesn't close the window
    /*int quit = 0;
    SDL_Event e;
    while (!quit){
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = 1;
        }
    }*/

    // free surface memory space
    //SDL_FreeSurface(image);

    return 0;
}