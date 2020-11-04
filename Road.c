//
// Created by Alex on 03/11/2020.
//

#include "Road.h"

void road(SDL_Renderer* renderer, const int SCREEN_WIDTH,const int SCREEN_HEIGHT){
    SDL_Rect route = { SCREEN_WIDTH / 4, 0, SCREEN_WIDTH /2, SCREEN_HEIGHT*2 };
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
    SDL_RenderFillRect( renderer, &route );

    SDL_Rect bandeslaterales[8]; // Création des bandes latérales colonne par colonne
    bandeslaterales[0].x=bandeslaterales[1].x=bandeslaterales[2].x=bandeslaterales[3].x=(SCREEN_WIDTH/4)+5;
    bandeslaterales[4].x=bandeslaterales[5].x=bandeslaterales[6].x=bandeslaterales[7].x=SCREEN_WIDTH-((SCREEN_WIDTH/4)+20);
    bandeslaterales[0].y=bandeslaterales[4].y=5;
    bandeslaterales[1].y=bandeslaterales[5].y=(SCREEN_HEIGHT/2)+5;
    bandeslaterales[2].y=bandeslaterales[6].y=SCREEN_HEIGHT+5;
    bandeslaterales[3].y=bandeslaterales[7].y=SCREEN_HEIGHT+(SCREEN_HEIGHT/2)+5;
    for(int i = 0; i!=8;i++)
    {
        bandeslaterales[i].w = 12;
        bandeslaterales[i].h = 320;
    }

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderFillRects(renderer, bandeslaterales, 8);

    SDL_Rect pointilles[30]; // Création des bandes du milieu de la route colonne par colonne
    for (int j=0; j!=30;j++){
        if (j<20){
            if (j<10)
                pointilles[j].x= (SCREEN_WIDTH/3)+30;
            else
                pointilles[j].x= (SCREEN_WIDTH/2)-5;
        }
        else pointilles[j].x= SCREEN_WIDTH-((SCREEN_WIDTH/3)+30);
    }

    for (int k=0;k<30;k++){
        if (k%10==0)pointilles[k].y= 25;
        if (k%10==1)pointilles[k].y= 159;
        if (k%10==2)pointilles[k].y= 293;
        if (k%10==3)pointilles[k].y= 427;
        if (k%10==4)pointilles[k].y= 561;
        if (k%10==5)pointilles[k].y= 696;
        if (k%10==6)pointilles[k].y= 831;
        if (k%10==7)pointilles[k].y= 966;
        if (k%10==8)pointilles[k].y= 1101;
        if (k%10==9)pointilles[k].y= 1236;

    }

    for(int i = 0; i!=30;i++)
    {
        pointilles[i].w = 5;
        pointilles[i].h = 60;
    }

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderFillRects(renderer, pointilles, 30);

    SDL_Delay(500);
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
}