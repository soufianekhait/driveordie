/*
 * This is the main function where the show begins.
 * Including main and road modules
 */
#include "src/modules/main.h"
#include "src/modules/road.h"
#include "src/modules/car.h"


void wait(float time)
{
    clock_t end = clock()+(time*CLOCKS_PER_SEC);
    // Clock() retourne le nombre de tick par seconde. On calcule le moment où le wait devra s'arrêter

    while(clock()<end);
}


int function_score(){
    int score = 0;
    do{
        printf("Score = %04d\n", score);
        wait(1); // score is incremented every sec
        score++;
    }while(score<=120); //While score is < 120, score++
    do{
        printf("Score = %04d\n", score);
        wait(1);
        score+=2;
    }while(score<=240);
    do{
        printf("Score = %04d\n", score);
        wait(1);
        score+=5;
    }while(score<=360);
    do{
        printf("Score = %04d\n", score);
        wait(1);
        score+=10;
    }while(score>=360);

    return score;
}


// define a color for renderer
const SDL_Color green = { 87, 167, 115, 255 };
SDL_Renderer *renderer = NULL;
SDL_Window *window = NULL;
SDL_Texture *background = NULL;


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


int create_texture(){
    background = SDL_CreateTexture(renderer,
                                   SDL_PIXELFORMAT_RGBA8888,
                                   SDL_TEXTUREACCESS_TARGET,
                                   SCREEN_WIDTH, SCREEN_HEIGHT*2);
    if(background == NULL) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
}


void draw(){
    // draw the road
    draw_road();
    // draw the player
    SDL_Surface *car_img = draw_car();

    SDL_Texture *carTxt = SDL_CreateTextureFromSurface(renderer, car_img);
    SDL_Rect car = { SCREEN_WIDTH/2 + 20, SCREEN_HEIGHT - car_img->h/3 - 10, car_img->w/3,car_img->h/3 };
    SDL_Rect src = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    move_road(carTxt, car, src);
    destroy_car(carTxt, car_img);
}


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

