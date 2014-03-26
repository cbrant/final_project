/* Connor Brant
CSE20212
Final Project
hole1.cpp

Main program used to create hole1 of the course. Functionality is
hardcoded now but will draw from object classes as development 
continues. Currently user should be able to aim disc and start/stop
power bar. Used lazyfoo.net tutorials as a guide.

*/


//Libraries to be included
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

const int SCREEN_WIDTH = 771;
const int SCREEN_HEIGHT = 593;
const int SCREEN_BPP = 32;


//Surfaces
SDL_Surface *background = NULL;
SDL_Surface *frisbee = NULL;
SDL_Surface *arrow0 = NULL;
SDL_Surface *left45 = NULL;
SDL_Surface *left30 = NULL;
SDL_Surface *left15 = NULL;
SDL_Surface *right45 = NULL;
SDL_Surface *right30 = NULL;
SDL_Surface *right15 = NULL;
SDL_Surface *message = NULL;
SDL_Surface *p0 = NULL;
SDL_Surface *p1 = NULL;
SDL_Surface *p2 = NULL;
SDL_Surface *p3 = NULL;
SDL_Surface *p4 = NULL;
SDL_Surface *p5 = NULL;
SDL_Surface *p6 = NULL;
SDL_Surface *p7 = NULL;
SDL_Surface *p8 = NULL;
SDL_Surface *p9 = NULL;
SDL_Surface *p10 = NULL;
SDL_Surface *p11 = NULL;
SDL_Surface *p12 = NULL;
SDL_Surface *p13 = NULL;
SDL_Surface *p14 = NULL;
SDL_Surface *p15 = NULL;
SDL_Surface *screen = NULL;

//Initialize font
TTF_Font *font = NULL;
SDL_Color textColor = { 255, 255, 255 };

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
    
    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        std::cout<<"TTF didn't initialize correctly"<<std::endl;
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
    SDL_WM_SetCaption( "Hole 1", NULL );
    
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
    
    //Powerbar images
    p0 = load_image("0.bmp");
    p1 = load_image("1.bmp");
    p2 = load_image("2.bmp");
    p3 = load_image("3.bmp");
    p4 = load_image("4.bmp");
    p5 = load_image("5.bmp");
    p6 = load_image("6.bmp");
    p7 = load_image("7.bmp");
    p8 = load_image("8.bmp");
    p9 = load_image("9.bmp");
    p10 = load_image("10.bmp");
    p11 = load_image("11.bmp");
    p12 = load_image("12.bmp");
    p13 = load_image("13.bmp");
    p14 = load_image("14.bmp");
    p15 = load_image("15.bmp");
    
    //arrow images
    arrow0 = load_image("0.png");
    left15 = load_image("15_left.png");
    left30 = load_image("30_left.png");
    left45 = load_image("45_left.png");
    right15 = load_image("15_right.png");
    right30 = load_image("30_right.png");
    right45 = load_image("45_right.png");
    
    //Open the font
    font = TTF_OpenFont( "lazy.ttf", 42 );
    
    if( background ==NULL || frisbee == NULL || font==NULL  )
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
    SDL_FreeSurface( p0 );
    
    TTF_CloseFont(font);
    
    TTF_Quit();
    
    std::cout<<"Quitting SDL..."<<std::endl;
    
    SDL_Quit();
    
}


int main( int argc, char* args[] )
{
    //quit program flag
    bool quit = false;
   
    //initilize everything
    if( init() == false )
      return 1;
        
    //load in our files
    if( load_files() == false )
      return 1;
      
     //current powerbar image
    SDL_Surface* currentPowerbar = p0;
    
    //current arrow image
    SDL_Surface* currentArrow = arrow0;
    int arrowCount = 0;
      
    //center the frisbee on the screen  
    int xposFris= ( SCREEN_WIDTH - frisbee->w ) / 2 ;
    int yposFris= ( SCREEN_HEIGHT - frisbee->h  / 2 ) ; 
    
    //center powerbar on top of screen
    int xposPowerbar = (SCREEN_WIDTH - currentPowerbar->w) / 2;
    int yposPowerbar = 10;
    
    //center arrow to start 
    int xposArrow= ( SCREEN_WIDTH - arrow0->w ) / 2 ;
    int yposArrow= ( SCREEN_HEIGHT - frisbee->h  / 2 ) - ( 3 * arrow0->h / 4) ; 
    
    //power variable
    int power = 0;
    
    //max and min for power 
    int maxPower = 15;
    int minPower =0;
     
     //set up the keystates        
     Uint8* keystates = SDL_GetKeyState( NULL );
            
    //loop until the user quits       
    while( quit == false )
    {
         //ensures that the program closes when the user exits
         while( SDL_PollEvent( &event ) )
         {
             if( event.type == SDL_QUIT )
             {
                 quit = true;
             }
         }
            
         //apply the background and frisbee and current powerbar
         apply_surface( 0, 0, background, screen);
         apply_surface( xposFris, yposFris, frisbee, screen);
         apply_surface( xposPowerbar, yposPowerbar, currentPowerbar, screen);
         apply_surface( xposArrow, yposArrow, currentArrow, screen);
         
         //get the state of all of the keys
         SDL_PumpEvents();
         
         if( keystates[SDLK_LEFT])
         {
             if(arrowCount>-3)
               arrowCount--;
         }
         
         if ( keystates[SDLK_RIGHT])
         {
             if(arrowCount<3)
               arrowCount++;
         }
         
         switch( arrowCount )
         {
             case -3:
                 currentArrow = left45;
             break;
             case -2:
                 currentArrow = left30;
             break;
             case -1:
                 currentArrow = left15;
             break;
             case 0:
                 currentArrow = arrow0;
             break;
             case 1:
                 currentArrow = right15;
             break;
             case 2:
                 currentArrow = right30;
             break;
             case 3:
                 currentArrow = right45;
             break;
             default:
                 currentArrow = arrow0;
             break;
         }       
                 
         if( keystates[SDLK_SPACE] )
         {
             //std::cout<<"Space"<<std::endl;
             int i = 0;
             bool inc = true;
             //boolean for power loop quit
    	     bool PowerbarGoing = true;
             
             while( PowerbarGoing )
             {
                //update keystates
                SDL_PumpEvents();
                //SDL_PollEvent( &event );
                 
                 if( keystates[SDLK_RETURN] )
                   PowerbarGoing = false;
                 
                 //bounce power between max and min power 
                 if( i<maxPower && inc)
                   i++;
                 else
		{
                     inc =false;
                 }
                 
                 if( i>minPower && !inc)
                   i--;
                 else
                 {
                     inc = true;
                 }
                 
                  //Code for the numerical display of power
                 /*std::cout<<i<<std::endl;
                 
                 std::stringstream ss;
                 ss.str(""); // empty the stringstream
                 ss.clear();
                 ss << i;
                 std::string s= ss.str();
                               
                message = TTF_RenderText_Solid( font, s.c_str(), textColor );*/
                                                
                //apply the background and frisbee
               apply_surface( 0, 0, background, screen);
               apply_surface( xposFris, yposFris, frisbee, screen);
               //determine current power
               switch(i)
               {
                   case 0:
                   	power = 0;
                   	currentPowerbar = p0;
                   break;
                   
                   case 1:
                   	power = 1;
                   	currentPowerbar = p1;
                   break;
                   
                   case 2:
                   	power = 2;
                   	currentPowerbar = p2;
                   break;
                   
                   case 3:
                   	power = 3;
                   	currentPowerbar = p3;
                   break;
                   
                   case 4:
                   	power = 4;
                   	currentPowerbar = p4;
                   break;
                   
                   case 5:
                   	power = 5;
                   	currentPowerbar = p5;
                   break;
                   
                   case 6:
                   	power = 6;
                   	currentPowerbar = p6;
                   break;
                   
                   case 7:
                   	power = 7;
                   	currentPowerbar = p7;
                   break;
                   
                   case 8:
                   	power = 8;
                   	currentPowerbar = p8;
                   break;
                   
                   case 9:
                   	power = 9;
                   	currentPowerbar = p9;
                   break;
                   
                   case 10:
                   	power = 10;
                   	currentPowerbar = p10;
                   break;
                   
                   case 11:
                   	power = 11;
                   	currentPowerbar = p11;
                   break;
                   
                   case 12:
                   	power = 12;
                   	currentPowerbar = p12;
                   break;
                   
                   case 13:
                   	power = 13;
                   	currentPowerbar = p13;
                   break;
                   
                   case 14:
                   	power = 14;
                   	currentPowerbar = p14;
                   break;
                   
                   case 15:
                   	power = 15;
                   	currentPowerbar = p15;
                   break;
                   
                   default:
                   	power = 0;
                   	currentPowerbar = p0;
                   break;
               }
               
               //display power bar
               apply_surface ( xposPowerbar, yposPowerbar, currentPowerbar, screen);
                   	
               //numerical power
               //apply_surface( 3 * SCREEN_WIDTH / 4, 3 * SCREEN_HEIGHT / 4, message, screen);
               
                //Update the screen
                if( SDL_Flip( screen ) == -1 )
                {
                   std::cout<<"Error in updating sceen"<<std::endl;
                   return 1;
                }
                 
                 usleep(10000);
             }
         }
         
         //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            std::cout<<"Error in updating sceen"<<std::endl;
            return 1;
        }
         
     }
     
     //clean up the surfaces
     clean_up();
     
     return 0;
}
             
