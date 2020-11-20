// Road.c
#include "Road.h"
#include "obstacles.h"


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
    // draw dashed lines
    if(SDL_RenderFillRects(renderer, dashedLines, 32) < 0){
        printf("SDL_RenderFillRects for dashed lines: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Surface* car = IMG_Load("resources/img/car.png");
    if(!car){
        printf("Error while loading image: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Surface* obstacle = IMG_Load("resources/img/car_3.png");
    if(!obstacle){
        printf("Error while loading image: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
    //SDL_Texture *txt = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 201/3, 506/3);

    //SDL_SetRenderTarget(renderer, txt);
    SDL_Texture *texture_car = SDL_CreateTextureFromSurface(renderer, car);
    SDL_Texture *texture_obstacle = SDL_CreateTextureFromSurface(renderer, obstacle);
    SDL_Texture *texture_obstacle2 = SDL_CreateTextureFromSurface(renderer, obstacle);
    SDL_Texture *texture_obstacle3 = SDL_CreateTextureFromSurface(renderer, obstacle);
    SDL_Rect dimensions = { SCREEN_WIDTH/2 + 20,SCREEN_HEIGHT - car->h/3 - 10, car->w/3,car->h/3 };
    SDL_Rect src = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
//    SDL_Rect car_obstacle = { ROAD_LEFT,SCREEN_HEIGHT, WAY_WIDTH,obstacle->h/3 };
    //SDL_SetRenderTarget(renderer, NULL);


    int running = 1;
    const int FPS = 60;
    const int speed = 5;
    Uint32 start;
    //int deltatime = 0;
    int FPSCounter = 0;
    int FPS2 = 0;
    //SDL_Rect imgloc = { 350,170,100,100 };
    SDL_Rect camera = { SCREEN_WIDTH/4, SCREEN_HEIGHT, SCREEN_WIDTH/2, SCREEN_HEIGHT };
    float move = 0;
    while(running){
        SDL_Event e;
        float deltatime = ((SDL_GetTicks() - start) / 1000.0f);
        while (SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym){

                        case SDLK_ESCAPE:
                            running = 0;
                            break;
                        case SDLK_RIGHT:
                            if(dimensions.x + dimensions.w < camera.x + camera.w - solidLines->w - 8){
                                move+= 2.0f * deltatime;
                                dimensions.x += move;
                            }
                            break;
                        case SDLK_LEFT:
                            if(dimensions.x > camera.x + solidLines->w + 8){
                                move+= 2.0f * deltatime;
                                dimensions.x -= move;
                            }
                            break;
                    }
                    break;
            }
        }

        start = SDL_GetTicks();
        camera.y -= speed;
        if (camera.y <= 0){
            camera.y = camera.h;
//            car_obstacle.x = x;
            //printf("%d\n", car_obstacle.x);
        }


        SDL_Rect location = {SCREEN_WIDTH/4, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT };
        SDL_SetRenderTarget(renderer, NULL);
        //printf("%.2f\n", deltatime);
        SDL_RenderCopy(renderer, texture, &camera, &location);
        SDL_RenderCopy(renderer, texture_car, &src, &dimensions);
        random_obstacles(renderer, texture_obstacle, texture_obstacle2, texture_obstacle3, camera.y, obstacle);
//        printf("%d\n", x);

        //SDL_RenderCopy(renderer, texture_obstacle, &src, &car_obstacle);
        //if(collision(&location, &imgloc))
            //SDL_BlitSurface(image, NULL, screen, &relcoord);
        //printf("%d\n", car_obstacle.x);
        SDL_RenderPresent(renderer);
        if(1000/FPS > SDL_GetTicks()-start){
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }
    }
    //SDL_DestroyTexture(texture_car);  // on n'aura plus besoin de la texture tampon*/
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
    SDL_FreeSurface(obstacle);
    SDL_FreeSurface(car);

    return 0;
}