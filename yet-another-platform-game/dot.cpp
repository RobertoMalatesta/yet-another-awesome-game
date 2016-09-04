#include "dot.h"

void Dot::handleEvent(SDL_Event& event) {
    // Key pressed down
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        switch(event.key.keysym.sym) {
            case SDLK_UP:
                mVelY -= DOT_VEL;
                jump = true;
            break;
            //case SDLK_DOWN:  mVelY += DOT_VEL; break;
            case SDLK_LEFT:  mVelX -= DOT_VEL; break;
            case SDLK_RIGHT: mVelX += DOT_VEL; break;
        }
    }
    // Key is released
    else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                mVelY += DOT_VEL;
                jump = false;
            break;
            //case SDLK_DOWN:  mVelY -= DOT_VEL; break;
            case SDLK_LEFT:  mVelX += DOT_VEL; break;
            case SDLK_RIGHT: mVelX -= DOT_VEL; break;
        }
    }
}

void Dot::move(int width, int height) {
    hit = false;
    // Left or right
    mPosX += mVelX;
    
    // Check if the dot moved to far left or right
    if ((mPosX < 0) || (mPosX + DOT_WIDTH > width)) {
        mPosX -= mVelX; // Move back
    }
    
    if (jump == false) {
        // Up or down
        //mPosY += mVelY;
        if (hit == false) {
            mPosY += DOT_VEL;
        } else {
            //mPosY -= DOT_VEL;
        }
    } else {
        // Up or down
        //mPosY += mVelY;
        if (hit == false) {
            mPosY -= DOT_VEL;
        } else {
            mPosY -= DOT_VEL;
        }
    }
    
    // Check if the dot moved to far up or down
    if ((mPosY < 0) || (mPosY + DOT_HEIGHT > height)) {
        //mPosY -= mVelY; // Move back
        
        if (jump == false) {
            //Move back
            if (hit == false) {
                mPosY -= DOT_VEL;
                hit = true;
            } else {
                //mPosY += DOT_VEL;
                hit = false;
            }
        }
    }
}

void Dot::render(SDL_Renderer* renderer) {
    // Draw the dot
    SDL_Rect bottomLine = {mPosX, mPosY, DOT_WIDTH, DOT_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &bottomLine);
}