/* Connor Brant
CSE20212
Final Project
initialTest.cpp

This is an initial test of the SDL graphics being used in our project. The program will
use the images that will be used in the project and will allow the user to move the 
frisbee around the screen using the arrow keys. Used lazyfoo.net SDL lesson10 as 
a guide.

*/


//Libraries to be included
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;


//Surfaces
SDL_Surface *background = NULL;
SDL_Surface *frisbee = NULL;
SDL_Surface *screen = NULL;

//Event structure
SDL_Event event;

SDL_Surface *load_image ( std::string filename )
{
    //Image to load
    SDL_Surface *loadedImage = NULL;
    
    //Optimized image
    SDL_Surface *optimizedImage = NULL;
    
    //Load image
    loadedImage = IMG_Load( filename.c_str() );
    
    if(loadedImage != NULL)
    {
        //create optimized
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //free the unoptimized image
        SDL_FreeSurface( loadedImage );
        
        if( optimizedImage != NULL );
        {
            //Get the color key of the image
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0xFF, 0xFF, 0xFF) );
        }
    }
    
    return optimizedImage;
}
            
            
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Rectangle to hold offsets
    SDL_Rect offset;
    
    offset.x = x;
    offset.y = y;
    
    //Blit surface
    SDL_BlitSurface( source, clip , destination, &offset );
}

           
           
bool init()
{
    std::cout<<"Initilizing..."<<std::endl;
    //Initilize SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1)
    {
      std::cout<<"Initilization Error"<<std::endl;
      return false;
    }
    
    //set up screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    
    //check for the screen setup
    if( screen == NULL)
    {
      std::cout<<"Screen didn't set correctly"<<std::endl;
      return false;
    }
    
    //set a window caption
    SDL_WM_SetCaption( "Initial Test of Project", NULL );
    
    std::cout<<"Initilization successful"<<std::endl;
    return true;
}

bool load_files()
{
    std::cout<<"Loading files..."<<std::endl;
    
    //Background
    background = load_image( "Start.png" );
    
    //Frisbee
    frisbee = load_image("ultimate_disc_white.png" );
    
    if( background ==NULL || frisbee == NULL )
    {
      std::cout<<"Files did not load correctly"<<std::endl;
      return false;
    }
    
    std::cout<<"Files loaded correctly"<<std::endl;
    return true;
}

void clean_up()
{
    SDL_FreeSurface( background );
    SDL_FreeSurface( frisbee );
    
    std::cout<<"Quitting SDL..."<<std::endl;
    
    SDL_Quit();
    
}


int main( int argc, char* args[] )
{
    //quit flag
    bool quit = false;
    
    //std::cout<<"Bug"<<std::endl;
    //initilize everything
    if( init() == false )
      return 1;
        
    //load in our files
    if( load_files() == false )
      return 1;
      
    //center the frisbee on the screen  
    int xpos= ( SCREEN_WIDTH - frisbee->w ) / 2;
    int ypos= ( SCREEN_HEIGHT - frisbee->h ) / 2;
            
    //loop until the user quits       
    while( quit == false )
    {
         //while there are events happening
         while( SDL_PollEvent( &event ) )
         {
             if( event.type == SDL_QUIT )
             {
                 quit = true;
             }
         }
            
         //apply the background
         apply_surface( 0, 0, background, screen);
         apply_surface( xpos, ypos, frisbee, screen);
         
         //get the state of all of the keys
         Uint8 *keystates = SDL_GetKeyState( NULL );
         
        //If up is pressed
        if( keystates[ SDLK_UP ] )
        {
            if( ypos > 0 )
              ypos-=10;
        }

        //If down is pressed
        if( keystates[SDLK_DOWN] )
        {
            if( ( ypos + frisbee->h ) < (SCREEN_HEIGHT - 10) )
              ypos+=10;
        }

        //If left is pressed
        if( keystates[ SDLK_LEFT ] )
        {
            if( xpos > 10 )
              xpos-=10;
        }

        //If right is pressed
        if( keystates[SDLK_RIGHT] )
        {
            if( ( xpos + frisbee->w ) < (SCREEN_WIDTH - 10 ) )
              xpos+=10;
        }

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            std::cout<<"Error in updating sceen"<<std::endl;
            return 1;
        }
         
     }
     
     clean_up();
     
     return 0;
}
             
