#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "CSprite.h"
#include <math.h>

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Player
{
private:
    double x,y;
    double vx, vy;
    CSprite *spr {nullptr};
    SDL_Renderer *renderer {nullptr};
    
    double ticker = 0.0f;
    double sx = 1.0f;
    double sy = 1.0f;
        
    
public:


    Player(SDL_Renderer *renderer, int x, int y, double ticker);
    ~Player();
    void Init();
    void Process();
    void Render(SDL_Renderer *renderer);
    void Input(const int dir);

};

#endif // PLAYER_H
