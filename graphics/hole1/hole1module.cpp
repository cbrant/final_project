/* Connor Brant
CSE20212
Final Project
hole1module.cpp

Main program used to create hole1 of the course. Functionality is
hardcoded now but will draw from object classes as development 
continues. Currently user should be able to aim disc and start/stop
power bar. Used lazyfoo.net tutorials as a guide.

TRYING TO TURN THIS ALL INTO FUNCTIONS TO BE REUSED BY OTHER HOLES!

*/


//Libraries to be included
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

const int SCREEN_WIDTH = 771;
const int SCREEN_HEIGHT = 593;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 60;


//Surfaces
SDL_Surface *background = NULL;
SDL_Surface *frisbee1 = NULL;
SDL_Surface *frisbee2 = NULL;
SDL_Surface *frisbee3 = NULL;
SDL_Surface *frisbee4 = NULL;
SDL_Surface *frisbee5 = NULL;
SDL_Surface *frisbee6 = NULL;
SDL_Surface *frisbee7 = NULL;
SDL_Surface *frisbee8 = NULL;
SDL_Surface *frisbee9 = NULL;
SDL_Surface *frisbee10 = NULL;
SDL_Surface *frisbee11 = NULL;
SDL_Surface *frisbee12 = NULL;
SDL_Surface *frisbee13 = NULL;
SDL_Surface *frisbee14 = NULL;
SDL_Surface *frisbee15 = NULL;
SDL_Surface *frisbee16 = NULL;
SDL_Surface *frisbee17 = NULL;
SDL_Surface *frisbee18 = NULL;
SDL_Surface *frisbee19 = NULL;
SDL_Surface *frisbee20 = NULL;
SDL_Surface *arrow0 = NULL;
SDL_Surface *left45 = NULL;
SDL_Surface *left30 = NULL;
SDL_Surface *left15 = NULL;
SDL_Surface *right45 = NULL;
SDL_Surface *right30 = NULL;
SDL_Surface *right15 = NULL;
SDL_Surface *angle0 = NULL;
SDL_Surface *angle3 = NULL;
SDL_Surface *angle6 = NULL;
SDL_Surface *angle9 = NULL;
SDL_Surface *angle12 = NULL;
SDL_Surface *angle15 = NULL;
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


//Music that will be played
Mix_Music *music = NULL;

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
    
	//Initialize SDL_mixer
	
	if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}

    //set a window caption
    SDL_WM_SetCaption( "Hole 1", NULL );
    
    std::cout<<"Initilization successful"<<std::endl;
    return true;
}

bool load_files( std::string backgroundFile )
{
    std::cout<<"Loading files..."<<std::endl;
    
    //Background
    background = load_image( backgroundFile );
    
    //Frisbee images
    frisbee1 = load_image("ultimate_disc_white_1.png" );
    frisbee2 = load_image("ultimate_disc_white_2.png" );
    frisbee3 = load_image("ultimate_disc_white_3.png" );
    frisbee4 = load_image("ultimate_disc_white_4.png" );
    frisbee5 = load_image("ultimate_disc_white_5.png" );
    frisbee6 = load_image("ultimate_disc_white_6.png" );
    frisbee7 = load_image("ultimate_disc_white_7.png" );
    frisbee8 = load_image("ultimate_disc_white_8.png" );
    frisbee9 = load_image("ultimate_disc_white_9.png" );
    frisbee10 = load_image("ultimate_disc_white_10.png" );
    frisbee11 = load_image("ultimate_disc_white_11.png" );
    frisbee12 = load_image("ultimate_disc_white_12.png" );
    frisbee13 = load_image("ultimate_disc_white_13.png" );
    frisbee14 = load_image("ultimate_disc_white_14.png" );
    frisbee15 = load_image("ultimate_disc_white_15.png" );
    frisbee16 = load_image("ultimate_disc_white_16.png" );
    frisbee17 = load_image("ultimate_disc_white_17.png" );
    frisbee18 = load_image("ultimate_disc_white_18.png" );
    frisbee19 = load_image("ultimate_disc_white_19.png" );
    frisbee20 = load_image("ultimate_disc_white_20.png" );
    
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
    
    //angle images
    angle0 = load_image("Angle_arrow0.bmp");
    angle3 = load_image("Angle_arrow3.bmp");
    angle6 = load_image("Angle_arrow6.bmp");
    angle9 = load_image("Angle_arrow9.bmp");
    angle12 = load_image("Angle_arrow12.bmp");
    angle15 = load_image("Angle_arrow15.bmp");
    
    //Open the font
    font = TTF_OpenFont( "lazy.ttf", 42 );
    
    if( background ==NULL || frisbee2 == NULL || font==NULL  )
    {
      std::cout<<"Files did not load correctly"<<std::endl;
      return false;
    }
    
	//Load music
	music = Mix_LoadMUS ( "Harder_than_you_think.wav");

	//Possible problem loading music
	if(music == NULL)
	{
		std::cout<<"Music did not load correctly"<<std::endl;
		return false;

	}

    std::cout<<"Files loaded correctly"<<std::endl;
    return true;
}

void clean_up()
{
    SDL_FreeSurface( background );
    SDL_FreeSurface (frisbee1);
    SDL_FreeSurface (frisbee2);
    SDL_FreeSurface (frisbee3);
    SDL_FreeSurface (frisbee4);
    SDL_FreeSurface (frisbee5);
    SDL_FreeSurface (frisbee6);
    SDL_FreeSurface (frisbee7);
    SDL_FreeSurface (frisbee8);
    SDL_FreeSurface (frisbee9);
    SDL_FreeSurface (frisbee10);
    SDL_FreeSurface (frisbee11);
    SDL_FreeSurface (frisbee12);
    SDL_FreeSurface (frisbee13);
    SDL_FreeSurface (frisbee14);
    SDL_FreeSurface (frisbee15);
    SDL_FreeSurface (frisbee16);
    SDL_FreeSurface (frisbee17);
    SDL_FreeSurface (frisbee18);
    SDL_FreeSurface (frisbee19);
    SDL_FreeSurface (frisbee20);
    SDL_FreeSurface (arrow0);
    SDL_FreeSurface (left45);
    SDL_FreeSurface (left30);
    SDL_FreeSurface (left15);
    SDL_FreeSurface (right45) ;
    SDL_FreeSurface (right30);
    SDL_FreeSurface (right15);
    SDL_FreeSurface (angle0);
    SDL_FreeSurface (angle3);
    SDL_FreeSurface (angle6) ;
    SDL_FreeSurface (angle9) ;
    SDL_FreeSurface (angle12);
    SDL_FreeSurface (angle15);
    SDL_FreeSurface (message);
    SDL_FreeSurface (p0);
    SDL_FreeSurface (p1);
    SDL_FreeSurface (p2);
    SDL_FreeSurface (p3);
    SDL_FreeSurface (p4);
    SDL_FreeSurface (p5);
    SDL_FreeSurface (p6);
    SDL_FreeSurface (p7);
    SDL_FreeSurface (p8);
    SDL_FreeSurface (p9);
    SDL_FreeSurface (p10);
    SDL_FreeSurface (p11);
    SDL_FreeSurface (p12);
    SDL_FreeSurface (p13);
    SDL_FreeSurface (p14);
    SDL_FreeSurface (p15);
    
	Mix_FreeMusic(music);

    TTF_CloseFont(font);

	//Quit Mixer
	Mix_CloseAudio();
    
    TTF_Quit();
    
    std::cout<<"Quitting SDL..."<<std::endl;
    
    SDL_Quit();
    
}

void fly_away(int direction)
{
    //current frisbee image
    SDL_Surface* currentFrisbee = frisbee1;
    
    //horizontal angle
    //switch(direction)
    
    int maxDistance = ( SCREEN_HEIGHT ) / 4;
    int distDifference =( SCREEN_HEIGHT - frisbee1->h  / 2 ) - maxDistance ; 
    int increment = distDifference / 20;
        
    
    //center the frisbee on the screen  
    int xposFrisbee= ( SCREEN_WIDTH - frisbee1->w ) / 2 ;
    int yposFrisbee= ( SCREEN_HEIGHT - frisbee1->h  / 2 ) ; 
    
    int i;
    
    for( i=1; i<21 ; i++)
    {
        switch(i)
        {
            case(1):
            	currentFrisbee = frisbee1;
            break;
            case(2):
            	currentFrisbee = frisbee2;
            break;
            case(3):
            	currentFrisbee = frisbee3;
            break;
            case(4):
            	currentFrisbee = frisbee4;
            break;
            case(5):
            	currentFrisbee = frisbee5;
            break;
            case(6):
            	currentFrisbee = frisbee6;
            break;
            case(7):
            	currentFrisbee = frisbee7;
            break;
            case(8):
            	currentFrisbee = frisbee8;
            break;
            case(9):
            	currentFrisbee = frisbee9;
            break;
            case(10):
            	currentFrisbee = frisbee10;
            break;
            case(11):
            	currentFrisbee = frisbee11;
            break;
            case(12):
            	currentFrisbee = frisbee12;
            break;
            case(13):
            	currentFrisbee = frisbee13;
            break;
            case(14):
            	currentFrisbee = frisbee14;
            break;
            case(15):
            	currentFrisbee = frisbee15;
            break;
            case(16):
            	currentFrisbee = frisbee16;
            break;
            case(17):
            	currentFrisbee = frisbee17;
            break;
            case(18):
            	currentFrisbee = frisbee18;
            break;
            case(19):
            	currentFrisbee = frisbee19;
            break;
            case(20):
            	currentFrisbee = frisbee20;
            break;
            default:
            	currentFrisbee = NULL;
            break;
        }
        
        xposFrisbee= ( SCREEN_WIDTH - currentFrisbee->w ) / 2 ;
        yposFrisbee = yposFrisbee - increment;
        
        
        apply_surface( 0, 0, background, screen);
        apply_surface( xposFrisbee, yposFrisbee, currentFrisbee, screen);
        
        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            std::cout<<"Error in updating sceen"<<std::endl;
        }
              
    }
}

int play( std::string backgroundFile )
{
    //quit program flag
    bool quit = false;
   
    //initilize everything
    if( init() == false )
      return 1;
        
    //load in our files
    if( load_files( backgroundFile ) == false )
      return 1;
      
     //current powerbar image
    SDL_Surface* currentPowerbar = p0;
    
    //current arrow image
    SDL_Surface* currentArrow = arrow0;
    int arrowCount = 0;
    
    //current angle image
    SDL_Surface* currentAngle = angle0;
    int angleCount = 0;
      
    //center the frisbee on the screen  
    int xposFris= ( SCREEN_WIDTH - frisbee1->w ) / 2 ;
    int yposFris= ( SCREEN_HEIGHT - frisbee1->h  / 2 ) ; 
    
    //center powerbar on top of screen
    int xposPowerbar = (SCREEN_WIDTH - currentPowerbar->w) / 2;
    int yposPowerbar = 10;
    
    //center arrow to start 
    int xposArrow= ( SCREEN_WIDTH - arrow0->w ) / 2 ;
    int yposArrow= ( SCREEN_HEIGHT - arrow0->h  / 2 ) - ( 3 * arrow0->h / 4) ; 
    
    //place angle arrow on right of screen
    int xposAngle= ( SCREEN_WIDTH - angle0->w);
    int yposAngle= ( SCREEN_WIDTH - angle0->h) / 2;
    
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
            
         //apply the background and frisbee and current powerbar and arrow and angle
         apply_surface( 0, 0, background, screen);
         apply_surface( xposFris, yposFris, frisbee1, screen);
         apply_surface( xposPowerbar, yposPowerbar, currentPowerbar, screen);
         apply_surface( xposArrow, yposArrow, currentArrow, screen);
         apply_surface( xposAngle, yposAngle, currentAngle, screen);
         
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
         
         if( keystates[SDLK_UP])
         {
             if(angleCount<5)
             	angleCount++;
         }
         
         if( keystates[SDLK_DOWN])
         {
             if(angleCount>0)
             	angleCount--;
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
         
         switch( angleCount )
         {
             case 0:
             	currentAngle = angle0;    
             break;
             case 1:
             	currentAngle = angle3;    
             break;
             case 2:
             	currentAngle = angle6;    
             break;
             case 3:
             	currentAngle = angle9;    
             break;
             case 4:
             	currentAngle = angle12;    
             break;
             case 5:
             	currentAngle = angle15;    
             break;
             default:
             	currentAngle = angle0;
         }
         
         if( keystates[SDLK_SPACE] )
         {
             //std::cout<<"Space"<<std::endl;
             int i = 0;
             //boolean for increasing powerbar
             bool inc = true;
             //boolean for power loop quit
    	     bool PowerbarGoing = true;
             
             while( PowerbarGoing )
             {
                //update keystates
                SDL_PumpEvents();
                //SDL_PollEvent( &event );
                 
                 if( keystates[SDLK_RETURN] )
                 {
                     fly_away(arrowCount);
                     if(arrowCount<0)
                       return 1;
                     else
                     	return 0;
                     	//PowerbarGoing = false;
                 }
                   
                 
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
               apply_surface( xposFris, yposFris, frisbee1, screen);
               
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
         
        usleep(50000); 
     }
     
     //clean up the surfaces
     clean_up();
     
     return 0;
}



int main( int argv, char* argc[])
{
    int left;
    left = play("Start.png");
    if(left)
    	play("Hole1Left.png");
    else
    	play("Hole1Right.png");
    
    clean_up();
    
    return 0;
}
