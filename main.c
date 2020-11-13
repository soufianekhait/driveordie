// main.c
#include "Road.h"
#include "Car.h"

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

// DOT Dimensions
const int DOT_WIDTH = 20;
const int DOT_HEIGHT = 20;
// DOT Velocity
const int DOT_VEL = 10;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int main(int argc, char *argv[]){
    SDL_DisplayMode dm;
    SDL_Color orange = {255, 127, 40, 255};
    SDL_Color green = { 87, 167, 115, 255 };

    // initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr, "SDL_Init Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // initialize SDL Image
    /*if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
        fprintf(stderr, "SDL_Init Error: %s", IMG_GetError());
        return EXIT_FAILURE;
    } else{
        printf("Hey");
    }*/
    // get actual desktop height
    if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
        SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
        return EXIT_FAILURE;
    } else{
        // create window
        window = SDL_CreateWindow("Drive or Die",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  SCREEN_WIDTH,
                                  //dm.h-80,
                                  SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        // check if window exists
        if(window == NULL){
            fprintf(stderr, "SDL_CreateWindow Error: %s", SDL_GetError());
            return EXIT_FAILURE;
        }
    }

    // create a render engine
    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
    // check if renderer exists
    if(renderer == NULL){
        fprintf(stderr, "SDL_CreateRenderer Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Texture *background = SDL_CreateTexture(renderer,
                                                SDL_PIXELFORMAT_RGBA8888,
                                                SDL_TEXTUREACCESS_TARGET,
                                                SCREEN_WIDTH, SCREEN_HEIGHT*2);

    if(background == NULL){
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    //
    // define a color for renderer
    if(SDL_SetRenderDrawColor(renderer, green.r, green.g, green.b, green.a) < 0){
        fprintf(stderr, "SDL_SetRenderDrawColor Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    // fill background with the defined color
    if(SDL_RenderClear(renderer) < 0){
        fprintf(stderr, "SDL_RenderClear Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    //printf("Your final score is : %03d\n",function_score());
    // draw a road
    init_road(renderer, background);
    addCar(renderer);
    // free texture memory space
    SDL_DestroyTexture(background);
    // free renderer memory space
    SDL_DestroyRenderer(renderer);
    // free window memory space
    SDL_DestroyWindow(window);
    // quit SDL Image
    //IMG_Quit();
    // quit SDL
    SDL_Quit();

    return 0;
}