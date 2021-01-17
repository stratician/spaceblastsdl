#include "Player.h"


Player::Player(SDL_Renderer *renderer, int x, int y, double ticker = 0.0f)
{
    this->x = static_cast<double>(x);
    this->y = static_cast<double>(y);
    
    this->renderer = renderer;
    this->ticker = ticker;
    
}

Player::~Player()
{
    if(spr != nullptr) {
        delete spr;
    }
}

void Player::Init() {
    // Load Ship Sprite
    spr = new CSprite(this->renderer, "sakura.bmp");
}


void Player::Process()
{
    
    // physics
    this->x += this->vx;
    this->y += this->vy;
    
    this->ticker += 0.1f;
    this->sx = 0.7f + sin(ticker) * 0.3f;
    this->sy = 0.7f + cos(ticker + 0.5f) * 0.3f;
    
}

void Player::Render(SDL_Renderer *renderer)
{
    
    if(spr != nullptr)
        spr->Render(renderer, this->x, this->y, this->sx, this->sy);
}

void Player::Input(const int dir) 
{
    switch(dir) {
        case UP: // Up
                
                break;
        case DOWN: // Down
               
                break;
        case LEFT: // Left
                
                break;
        case RIGHT: // Right
                
                break;
    }
}

