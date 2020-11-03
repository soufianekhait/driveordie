////Using SDL and standard IO
//#include <SDL.h>
//#include <stdio.h>
//#include <stdlib.h>
//
////Screen dimension constants
//const int SCREEN_WIDTH = 840;
//const int SCREEN_HEIGHT = 680;
//
//
//int main( int argc, char* args[] )
//{
//    SDL_Window * ecran = NULL;
//    SDL_Renderer* rendu = NULL;
////    SDL_Surface* screensurface = NULL;
////    SDL_Surface *rectangle = NULL;
//    SDL_Rect position;
//    const char *title = "DOD";
//
//    SDL_Init(SDL_INIT_VIDEO);
//
//    ecran = SDL_CreateWindow(title, 440, 200, 800, 550, 0);
//    // Allocation de la surface
////    rectangle = SDL_CreateRGBSurface(SDL_SWSURFACE, 220, 180, 32, 0, 0, 0, 0);
//    SDL_SetWindowTitle(ecran, "DriveOrDie");
//
//    // Create Renderer
//    SDL_CreateRenderer(ecran, -1 , SDL_RENDERER_ACCELERATED);
//    //Render red filled quad
//    SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
//    SDL_SetRenderDrawColor( rendu, 0xFF, 0x00, 0x00, 0xFF );
//    SDL_RenderFillRect( rendu, &fillRect );
//
//    SDL_RenderPresent(rendu); // Mise à jour de l'écran
//
//    SDL_Delay(2000);
//
//    SDL_RenderClear(rendu); // Libération de la surface
//    SDL_Quit();
//
//    return EXIT_SUCCESS;
//}

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 680;

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    int statut = EXIT_FAILURE;
    SDL_Color orange = {255, 127, 40, 255};

    /* Initialisation, création de la fenêtre et du renderer. */
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_SetWindowTitle(window, "DriveOrDie");
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(NULL == renderer)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        goto Quit;
    }

//    if (SDL_SetWindowFullscreen(window , SDL_TRUE) < 0)
//    {
//        printf("Erreur lors du passage en mode plein ecran : %s", SDL_GetError());
//        return EXIT_FAILURE;
//    }

    /* C’est à partir de maintenant que ça se passe. */
    if(0 != SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        goto Quit;
    }

    if(0 != SDL_RenderClear(renderer))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        goto Quit;
    }

    SDL_Rect route = { SCREEN_WIDTH / 4, 0, SCREEN_WIDTH /2, SCREEN_HEIGHT };
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
    SDL_RenderFillRect( renderer, &route );
    SDL_Rect bandegauche = {(SCREEN_WIDTH/4)+5, 0, 15, SCREEN_HEIGHT};
    SDL_Rect bandedroite = {SCREEN_WIDTH-((SCREEN_WIDTH/4)+20), 0, 15, SCREEN_HEIGHT};
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderFillRect(renderer, &bandedroite);
    SDL_RenderFillRect(renderer, &bandegauche);
    SDL_Delay(500);
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);

    statut = EXIT_SUCCESS;

    Quit:
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;
}