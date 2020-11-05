//
// Created by Alex on 04/11/2020.
//

#include "BackMove.h"
#include "Road.h"

void backMove(SDL_Renderer* renderer){
//The X and Y offsets of the dot
    int mPosX, mPosY;

//The velocity of the dot
    int mVelX, mVelY;

//The background scrolling offset
    int scrollingOffset = 0;

    //Clear screen
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );

    //Render background
    gBGTexture.render( scrollingOffset, 0 );
    gBGTexture.render( scrollingOffset + gBGTexture.getWidth(), 0 );

    //Render objects
    dot.render();

    //Update screen
    SDL_RenderPresent( renderer );
}