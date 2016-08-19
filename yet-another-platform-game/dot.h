#ifndef dot_hpp
#define dot_hpp

#include <iostream>

#include <SDL2/SDL.h>

class Dot {
public:
    Dot():
    mPosX(0), mPosY(0), mVelX(0), mVelY(0) { }
    
    
    void handleEvent(SDL_Event& event);     // Takes key input and adept the dot's velocity
    void move(int width, int height);       // Moves the dot
    void render(SDL_Renderer* renderer);    // Draw the dot on to the screen
    
    static const int DOT_WIDTH  = 20;       // Dot's width
    static const int DOT_HEIGHT = 20;       // Dot's height
    static const int DOT_VEL    = 10;       // Max velocity of the dot
    
private:
    int mPosX, mPosY;                       // The X and Y offsets of the dot
    int mVelX, mVelY;                       // The velocity of the dot
    
};

#endif
