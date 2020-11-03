//
// Created by Alex on 03/11/2020.
//

#include "Road.h"

void road(SDL_Renderer* renderer, const int SCREEN_WIDTH,const int SCREEN_HEIGHT){
    SDL_Rect route = { SCREEN_WIDTH / 4, 0, SCREEN_WIDTH /2, SCREEN_HEIGHT };
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
    SDL_RenderFillRect( renderer, &route );

    SDL_Rect bandeslaterales[4]; // Création des bandes latérales
    bandeslaterales[0].x=bandeslaterales[1].x=(SCREEN_WIDTH/4)+5;
    bandeslaterales[2].x=bandeslaterales[3].x=SCREEN_WIDTH-((SCREEN_WIDTH/4)+20);
    bandeslaterales[0].y=bandeslaterales[2].y=5;
    bandeslaterales[1].y=bandeslaterales[3].y=(SCREEN_HEIGHT/2)+10;
    bandeslaterales[0].w=bandeslaterales[1].w=bandeslaterales[2].w=bandeslaterales[3].w=12;
    bandeslaterales[0].h=bandeslaterales[1].h=bandeslaterales[2].h=bandeslaterales[3].h=320;

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderFillRects(renderer, bandeslaterales, 4);

    SDL_Rect pointilles[15]; // Création des bandes du milieu de la route
    pointilles[0].x=pointilles[1].x=pointilles[2].x=pointilles[3].x=pointilles[4].x=(SCREEN_WIDTH/3)+30;
    pointilles[5].x=pointilles[6].x=pointilles[7].x=pointilles[8].x=pointilles[9].x=(SCREEN_WIDTH/2)-5;
    pointilles[10].x=pointilles[11].x=pointilles[12].x=pointilles[13].x=pointilles[14].x=SCREEN_WIDTH-((SCREEN_WIDTH/3)+30);
    pointilles[0].y=pointilles[5].y=pointilles[10].y=25;
    pointilles[1].y=pointilles[6].y=pointilles[11].y=159;
    pointilles[2].y=pointilles[7].y=pointilles[12].y=293;
    pointilles[3].y=pointilles[8].y=pointilles[13].y=427;
    pointilles[4].y=pointilles[9].y=pointilles[14].y=561;
    for(int i = 0; i!=15;i++)
    {
        pointilles[i].w = 5;
        pointilles[i].h = 60;
    }

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderFillRects(renderer, pointilles, 15);

    SDL_Delay(500);
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
}