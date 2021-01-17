/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>
#include <memory>
#include <time.h>

#include "Player.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 1024;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

Player *player {nullptr};

void Process();
void Render();

typedef std::shared_ptr<Player> playerPtrType;
std::vector<playerPtrType> players;

void CreatePlayer();


bool init()
{
    // Set random seed to time stamp, so different rand each time
    srand(time(NULL));
    
    
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}
    
    
    // Init Player(s)
    CreatePlayer();
	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Nothing to load
	return success;
}

void close()
{
    if(player != nullptr) 
        delete player;
    
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

int main( int argc, char* args[] )
{
    
    
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT ) {
						quit = true;
					} else {
                        
                        switch(e.key.keysym.sym) {
                            
                            /*
                            case SDLK_UP:
                            if(player != nullptr) 
                                player->Input(UP);
                                break;
                            case SDLK_DOWN:
                            if(player != nullptr) 
                                player->Input(DOWN);
                                break;
                            case SDLK_LEFT:
                            if(player != nullptr) 
                                player->Input(LEFT);
                                break;
                            case SDLK_RIGHT:
                            if(player != nullptr) 
                                player->Input(RIGHT);
                                break;
                            */
                            case SDLK_SPACE:
                                CreatePlayer();
                                break;

                        }
                         
                    }
                    
                    
				}

                Process();
                Render();
                
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

void Process() 
{
    // 60 fps processing
    
    for(playerPtrType player:players) {
        player->Process();
    }
    
}

void Render() 
{
    //Clear screen (Teal)
    SDL_SetRenderDrawColor( gRenderer, 0x00F, 0x77, 0x99, 0xFF );
    SDL_RenderClear( gRenderer );


    for(playerPtrType player:players) {
        player->Render(gRenderer);
    }
 
    
    //Update screen
    SDL_RenderPresent( gRenderer );
}



void CreatePlayer()
{
    // Create a random player
    // typedef std::shared_ptr<Player> playerPtrType;
    playerPtrType player = std::make_shared<Player>(gRenderer, (rand()%SCREEN_WIDTH), (rand()%SCREEN_HEIGHT), (rand()%1000) * 0.001f);
    player->Init();
    players.push_back(player);
    
}