/*
 * This is the main function where the show begins.
 * Including main and road modules
 */
#include "src/modules/main.h"
#include "src/modules/road.h"
#include "src/modules/car.h"
#include "src/modules/obstacles.h"
#include "src/modules/collision.h"
#include "src/modules/menu.h"
#include "src/modules/game_over.h"


// define a color for renderer
const SDL_Color green = { 87, 167, 115, 255 };
SDL_Renderer *renderer = NULL;
SDL_Window *window = NULL;
SDL_Texture *background = NULL;

// signatures
int init();
int create_renderer();
int create_texture();
void draw();
void destroy();


int main(int argc, char *argv[]){
    // initialize SDL
    init();
    // create features
    create_renderer();
    // create texture
    create_texture();
    // draw on screen
    draw();
    // free memory space
    destroy();

    return 0;
}


int init(){
    // initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr, "SDL_Init Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // initialize SDL Image
    if((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
        fprintf(stderr, "IMG_Init Error: %s", IMG_GetError());
        return EXIT_FAILURE;
    }
}


int create_renderer(){
    // create window
    window = SDL_CreateWindow("Drive or Die",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    // check if window exists
    if(window == NULL){
        fprintf(stderr, "SDL_CreateWindow Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // create a render engine
    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
    // check if renderer exists
    if(renderer == NULL){
        fprintf(stderr, "SDL_CreateRenderer Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    if(SDL_SetRenderDrawColor(renderer, green.r, green.g, green.b, green.a) < 0){
        fprintf(stderr, "SDL_SetRenderDrawColor Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // fill background with the defined color
    if(SDL_RenderClear(renderer) < 0){
        fprintf(stderr, "SDL_RenderClear Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
}


int create_texture(){
    background = SDL_CreateTexture(renderer,
                                   SDL_PIXELFORMAT_RGBA8888,
                                   SDL_TEXTUREACCESS_TARGET,
                                   SCREEN_WIDTH, SCREEN_HEIGHT*2);
    if(background == NULL) {
        fprintf(stderr, "SDL_CreateTexture Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
}


void draw(){
    int restart = 1;

        //display the menu
        if (load_menu() == 2) {
            while (restart == 1) {
                // draw the road
                draw_road();
                // draw the player
                load_car();
                // draw the obstacle
                load_obstacle();
                // move road

                if (move_road() == 1) {
                    if (load_GO() == 2) {
                        restart = 1;
                    } else {
                        restart = 0;
                    }
                }
            }
        }
            destroy_menu();
            destroy_GO();
            destroy_car(car_txt, car_img);
            destroy_obstacle(obstacle_img);


    }


void destroy(){
    // free texture memory space
    SDL_DestroyTexture(background);
    // free renderer memory space
    SDL_DestroyRenderer(renderer);
    // free window memory space
    SDL_DestroyWindow(window);
    // quit SDL Image
    IMG_Quit();
    // quit SDL
    SDL_Quit();
}