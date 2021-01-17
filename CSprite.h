#ifndef CSPRITE_H
#define CSPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>

class CSprite
{
private:
    SDL_Texture* texture{nullptr};
    int width{0};
    int height{0};
public:
    CSprite(SDL_Renderer *renderer, const std::string fname);
    ~CSprite();
    
    SDL_Texture* LoadTexture(SDL_Renderer *renderer, const std::string fname);
    void Render(SDL_Renderer *renderer, double x, double y, double sx = 1.0, double sy = 1.0);

};

#endif // CSPRITE_H
