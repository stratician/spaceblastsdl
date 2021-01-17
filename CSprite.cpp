#include "CSprite.h"

CSprite::CSprite(SDL_Renderer *renderer, const std::string fname)
{
    texture = LoadTexture(renderer, fname);
}

CSprite::~CSprite()
{
    if(texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

SDL_Texture* CSprite::LoadTexture(SDL_Renderer* renderer, const std::string fname)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( fname.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", fname.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", fname.c_str(), SDL_GetError() );
		}
        
        // Update our Sprites Width and Height
        this->width = loadedSurface->w;
        this->height = loadedSurface->h;

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;

}

void CSprite::Render(SDL_Renderer *renderer, double x, double y, double sx, double sy) {
    SDL_Rect srcRect { 0, 0, this->width, this->height };
    SDL_Rect destRect {static_cast<int>(x), static_cast<int>(y), this->width * sx, this->height * sy};
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
    
}
