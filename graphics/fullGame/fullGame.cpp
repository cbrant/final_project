/* Connor Brant
CSE20212
Final Project
fullGame.cpp

Main program used to create the course. Functionality
draws from object classes. Used lazyfoo.net tutorials as a guide.

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
#include <cmath>
#include "Hole.h"
#include "Disc.h"
#include "Player.h"

#define _USE_MATH_DEFINES

const int SCREEN_WIDTH = 750;
const int SCREEN_HEIGHT = 590;
const int SCREEN_BPP = 32;

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
SDL_Surface *frisbee21 = NULL;
SDL_Surface *frisbee22 = NULL;
SDL_Surface *frisbee23 = NULL;
SDL_Surface *frisbee24 = NULL;
SDL_Surface *frisbee25 = NULL;
SDL_Surface *frisbee26 = NULL;
SDL_Surface *frisbee27 = NULL;
SDL_Surface *frisbee28 = NULL;
SDL_Surface *frisbee29 = NULL;
SDL_Surface *frisbee30 = NULL;
SDL_Surface *frisbee31 = NULL;
SDL_Surface *frisbee32 = NULL;
SDL_Surface *frisbee33 = NULL;
SDL_Surface *frisbee34 = NULL;
SDL_Surface *frisbee35 = NULL;
SDL_Surface *frisbee36 = NULL;
SDL_Surface *frisbee37 = NULL;
SDL_Surface *frisbee38 = NULL;
SDL_Surface *frisbee39 = NULL;
SDL_Surface *frisbee40 = NULL;
SDL_Surface *frisbee41 = NULL;
SDL_Surface *frisbee42 = NULL;
SDL_Surface *frisbee43 = NULL;
SDL_Surface *frisbee44 = NULL;
SDL_Surface *frisbee45 = NULL;
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
SDL_Surface *horzText = NULL;
SDL_Surface *vertText = NULL;
SDL_Surface *hitText = NULL;
SDL_Surface *scoreText = NULL;
SDL_Surface *scoreHoleText = NULL;
SDL_Surface *screen = NULL;

//Initialize font
TTF_Font *font = NULL;
TTF_Font *font2 = NULL;
SDL_Color textColor = { 0, 0, 0 };
SDL_Color textColor2 = { 240, 100, 0 };

//Music that will be played
Mix_Music *music = NULL;

//Event structure
SDL_Event event;

//array containing graphic controller variables
double stats[]={0,0,0};

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
    std::cout<<"Initializing..."<<std::endl;
    
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
    SDL_WM_SetCaption( "ND Frolf: The Video Game", NULL );
    
    std::cout<<"Initialization successful"<<std::endl;
    return true;
}

bool load_files( std::string backgroundFile, std::string musicFile )
{
    std::cout<<"Loading files..."<<std::endl;
    
    //Background
    background = load_image( backgroundFile );
    
    //Frisbee images
    frisbee1 = load_image("../../pictures/discs/white/ultimate_disc_white_1.png" );
    frisbee2 = load_image("../../pictures/discs/white/ultimate_disc_white_2.png" );
    frisbee3 = load_image("../../pictures/discs/white/ultimate_disc_white_3.png" );
    frisbee4 = load_image("../../pictures/discs/white/ultimate_disc_white_4.png" );
    frisbee5 = load_image("../../pictures/discs/white/ultimate_disc_white_5.png" );
    frisbee6 = load_image("../../pictures/discs/white/ultimate_disc_white_6.png" );
    frisbee7 = load_image("../../pictures/discs/white/ultimate_disc_white_7.png" );
    frisbee8 = load_image("../../pictures/discs/white/ultimate_disc_white_8.png" );
    frisbee9 = load_image("../../pictures/discs/white/ultimate_disc_white_9.png" );
    frisbee10 = load_image("../../pictures/discs/white/ultimate_disc_white_10.png" );
    frisbee11 = load_image("../../pictures/discs/white/ultimate_disc_white_11.png" );
    frisbee12 = load_image("../../pictures/discs/white/ultimate_disc_white_12.png" );
    frisbee13 = load_image("../../pictures/discs/white/ultimate_disc_white_13.png" );
    frisbee14 = load_image("../../pictures/discs/white/ultimate_disc_white_14.png" );
    frisbee15 = load_image("../../pictures/discs/white/ultimate_disc_white_15.png" );
    frisbee16 = load_image("../../pictures/discs/white/ultimate_disc_white_16.png" );
    frisbee17 = load_image("../../pictures/discs/white/ultimate_disc_white_17.png" );
    frisbee18 = load_image("../../pictures/discs/white/ultimate_disc_white_18.png" );
    frisbee19 = load_image("../../pictures/discs/white/ultimate_disc_white_19.png" );
    frisbee20 = load_image("../../pictures/discs/white/ultimate_disc_white_20.png" );
    frisbee21 = load_image("../../pictures/discs/white/ultimate_disc_white_21.png" );
    frisbee22 = load_image("../../pictures/discs/white/ultimate_disc_white_22.png" );
    frisbee23 = load_image("../../pictures/discs/white/ultimate_disc_white_23.png" );
    frisbee24 = load_image("../../pictures/discs/white/ultimate_disc_white_24.png" );
    frisbee25 = load_image("../../pictures/discs/white/ultimate_disc_white_25.png" );
    frisbee26 = load_image("../../pictures/discs/white/ultimate_disc_white_26.png" );
    frisbee27 = load_image("../../pictures/discs/white/ultimate_disc_white_27.png" );
    frisbee28 = load_image("../../pictures/discs/white/ultimate_disc_white_28.png" );
    frisbee29 = load_image("../../pictures/discs/white/ultimate_disc_white_29.png" );
    frisbee30 = load_image("../../pictures/discs/white/ultimate_disc_white_30.png" );
    frisbee31 = load_image("../../pictures/discs/white/ultimate_disc_white_31.png" );
    frisbee32 = load_image("../../pictures/discs/white/ultimate_disc_white_32.png" );
    frisbee33 = load_image("../../pictures/discs/white/ultimate_disc_white_33.png" );
    frisbee34 = load_image("../../pictures/discs/white/ultimate_disc_white_34.png" );
    frisbee35 = load_image("../../pictures/discs/white/ultimate_disc_white_35.png" );
    frisbee36 = load_image("../../pictures/discs/white/ultimate_disc_white_36.png" );
    frisbee37 = load_image("../../pictures/discs/white/ultimate_disc_white_37.png" );
    frisbee38 = load_image("../../pictures/discs/white/ultimate_disc_white_38.png" );
    frisbee39 = load_image("../../pictures/discs/white/ultimate_disc_white_39.png" );
    frisbee40 = load_image("../../pictures/discs/white/ultimate_disc_white_40.png" );
    frisbee41 = load_image("../../pictures/discs/white/ultimate_disc_white_41.png" );
    frisbee42 = load_image("../../pictures/discs/white/ultimate_disc_white_42.png" );
    frisbee43 = load_image("../../pictures/discs/white/ultimate_disc_white_43.png" );
    frisbee44 = load_image("../../pictures/discs/white/ultimate_disc_white_44.png" );
    frisbee45 = load_image("../../pictures/discs/white/ultimate_disc_white_45.png" );
    
    //Powerbar images
    p0 = load_image("../../pictures/powerbars/0.bmp");
    p1 = load_image("../../pictures/powerbars/1.bmp");
    p2 = load_image("../../pictures/powerbars/2.bmp");
    p3 = load_image("../../pictures/powerbars/3.bmp");
    p4 = load_image("../../pictures/powerbars/4.bmp");
    p5 = load_image("../../pictures/powerbars/5.bmp");
    p6 = load_image("../../pictures/powerbars/6.bmp");
    p7 = load_image("../../pictures/powerbars/7.bmp");
    p8 = load_image("../../pictures/powerbars/8.bmp");
    p9 = load_image("../../pictures/powerbars/9.bmp");
    p10 = load_image("../../pictures/powerbars/10.bmp");
    p11 = load_image("../../pictures/powerbars/11.bmp");
    p12 = load_image("../../pictures/powerbars/12.bmp");
    p13 = load_image("../../pictures/powerbars/13.bmp");
    p14 = load_image("../../pictures/powerbars/14.bmp");
    p15 = load_image("../../pictures/powerbars/15.bmp");
    
    //arrow images
    arrow0 = load_image("../../pictures/arrows/0.png");
    left15 = load_image("../../pictures/arrows/15_left.png");
    left30 = load_image("../../pictures/arrows/30_left.png");
    left45 = load_image("../../pictures/arrows/45_left.png");
    right15 = load_image("../../pictures/arrows/15_right.png");
    right30 = load_image("../../pictures/arrows/30_right.png");
    right45 = load_image("../../pictures/arrows/45_right.png");
    
    //angle images
    angle0 = load_image("../../pictures/angle_arrows/Angle_arrow0.bmp");
    angle3 = load_image("../../pictures/angle_arrows/Angle_arrow3.bmp");
    angle6 = load_image("../../pictures/angle_arrows/Angle_arrow6.bmp");
    angle9 = load_image("../../pictures/angle_arrows/Angle_arrow9.bmp");
    angle12 = load_image("../../pictures/angle_arrows/Angle_arrow12.bmp");
    angle15 = load_image("../../pictures/angle_arrows/Angle_arrow15.bmp");
    
    //Open the font
    font = TTF_OpenFont( "../../fonts/BEBAS.ttf", 24 );
    font2 = TTF_OpenFont( "../../fonts/BEBAS.ttf", 80 );
    
    if( background ==NULL || frisbee45 == NULL || font==NULL  )
    {
      std::cout<<"Files did not load correctly"<<std::endl;
      return false;
    }
    
    //Load music
    music = Mix_LoadMUS ( musicFile.c_str());

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
    //free all surfaces
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
    SDL_FreeSurface (frisbee21);
    SDL_FreeSurface (frisbee22);
    SDL_FreeSurface (frisbee23);
    SDL_FreeSurface (frisbee24);
    SDL_FreeSurface (frisbee25);
    SDL_FreeSurface (frisbee26);
    SDL_FreeSurface (frisbee27);
    SDL_FreeSurface (frisbee28);
    SDL_FreeSurface (frisbee29);
    SDL_FreeSurface (frisbee30);
    SDL_FreeSurface (frisbee31);
    SDL_FreeSurface (frisbee32);
    SDL_FreeSurface (frisbee33);
    SDL_FreeSurface (frisbee34);
    SDL_FreeSurface (frisbee35);
    SDL_FreeSurface (frisbee36);
    SDL_FreeSurface (frisbee37);
    SDL_FreeSurface (frisbee38);
    SDL_FreeSurface (frisbee39);
    SDL_FreeSurface (frisbee40);
    SDL_FreeSurface (frisbee41);
    SDL_FreeSurface (frisbee42);
    SDL_FreeSurface (frisbee43);
    SDL_FreeSurface (frisbee44);
    SDL_FreeSurface (frisbee45);
    SDL_FreeSurface (arrow0);
    SDL_FreeSurface (left45);
    SDL_FreeSurface (left30);
    SDL_FreeSurface (left15);
    SDL_FreeSurface (right45);
    SDL_FreeSurface (right30);
    SDL_FreeSurface (right15);
    SDL_FreeSurface (angle0);
    SDL_FreeSurface (angle3);
    SDL_FreeSurface (angle6);
    SDL_FreeSurface (angle9);
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
    SDL_FreeSurface (horzText);
    SDL_FreeSurface (vertText);
    SDL_FreeSurface (scoreText);
    SDL_FreeSurface (scoreHoleText);
    SDL_FreeSurface (hitText);
    
    // free music
    Mix_FreeMusic(music);
    
    //close fonts
    TTF_CloseFont(font);
    TTF_CloseFont(font2);

    //Quit Mixer
    Mix_CloseAudio();
    
    TTF_Quit();
    
    std::cout<<"Quitting SDL..."<<std::endl;
    
    //quit sdl
    SDL_Quit();
    
}

void fly_away(int direction)
{
    //current frisbee image
    SDL_Surface* currentFrisbee = frisbee1;
   
    //horizontal angle for the fribee to be thrown  
    double angle = 0;
    
    //pick horizontal angle
    switch(direction)
    {
    	case -3:
    	  angle = -45.0 * (M_PI / 180);
    	break;
    	case -2:
    	  angle = -30.0 * (M_PI  / 180);
    	break;
    	case -1:
    	  angle = -15.0 * (M_PI  / 180);
    	break;
    	case 0:
    	  angle = 0.0 * (M_PI  / 180);
    	break;
    	case 1:
    	  angle = 15.0 * (M_PI  / 180);
    	break;
    	case 2:
    	  angle = 30.0 * (M_PI  / 180);
    	break;
    	case 3:
    	  angle = 45.0 * (M_PI  / 180);
    	break;
    	default:
    	  angle = 0.0 * (M_PI  / 180);
    	break;
    }
    
    //calculate display distance to fly
    double maxDistance = ( SCREEN_HEIGHT ) / 4;
    double distDifference =( SCREEN_HEIGHT - frisbee1->h  / 2 ) - maxDistance ; 
    double increment = distDifference / 45;
        
    //center the frisbee on the screen  and save original spot
    double xposFrisbee= ( SCREEN_WIDTH - frisbee1->w ) / 2 ;
    double yposFrisbee= ( SCREEN_HEIGHT - frisbee1->h  / 2 ) ; 
    double yposFrisbeeOrig= ( SCREEN_HEIGHT - frisbee1->h  / 2 ) ; 
    
    int i;
    
    for( i=1; i<46 ; i++)
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
            case(21):
            	currentFrisbee = frisbee21;
            break;
            case(22):
            	currentFrisbee = frisbee22;
            break;
            case(23):
            	currentFrisbee = frisbee23;
            break;
            case(24):
            	currentFrisbee = frisbee24;
            break;
            case(25):
            	currentFrisbee = frisbee25;
            break;
            case(26):
            	currentFrisbee = frisbee26;
            break;
            case(27):
            	currentFrisbee = frisbee27;
            break;
            case(28):
            	currentFrisbee = frisbee28;
            break;
            case(29):
            	currentFrisbee = frisbee29;
            break;
            case(30):
            	currentFrisbee = frisbee30;
            break;
            case(31):
            	currentFrisbee = frisbee31;
            break;
            case(32):
            	currentFrisbee = frisbee32;
            break;
            case(33):
            	currentFrisbee = frisbee33;
            break;
            case(34):
            	currentFrisbee = frisbee34;
            break;
            case(35):
            	currentFrisbee = frisbee35;
            break;
            case(36):
            	currentFrisbee = frisbee36;
            break;
            case(37):
            	currentFrisbee = frisbee37;
            break;
            case(38):
            	currentFrisbee = frisbee38;
            break;
            case(39):
            	currentFrisbee = frisbee39;
            break;
            case(40):
            	currentFrisbee = frisbee40;
            break;
            case(41):
            	currentFrisbee = frisbee41;
            break;
            case(42):
            	currentFrisbee = frisbee42;
            break;
            case(43):
            	currentFrisbee = frisbee43;
            break;
            case(44):
            	currentFrisbee = frisbee44;
            break;
            case(45):
            	currentFrisbee = frisbee45;
            break;
            default:
            	currentFrisbee = NULL;
            break;
        }
        
        //calculate frisbee position with trig
        yposFrisbee = yposFrisbee - increment;
        xposFrisbee= (( SCREEN_WIDTH - currentFrisbee->w ) / 2) + ( (yposFrisbeeOrig - yposFrisbee)  * tan(angle) );
        
        //apply frisbee and background
        apply_surface( 0, 0, background, screen);
        apply_surface( xposFrisbee, yposFrisbee, currentFrisbee, screen);
        
        usleep(1000);
        
        //Update the screen
        SDL_Flip( screen );
              
    }
}

double* play( std::string backgroundFile, std::string musicFile, double horzDist, double vertDist, int score, int scoreHole )
{
    //quit program flag
    bool quit = false;
   
    //initilize everything
    if( init() == false ) 
    {
      clean_up();
      exit(0);
    }
             
    //load in our files
    if( load_files( backgroundFile, musicFile ) == false )
    {
      clean_up();
      exit(0);
    }     
      
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
    double power = 0;
    
    //angle variable (horizontal)
    double angle = 0;
    
    //alpha variable (vertical)
    double alpha = 0; 
    
    //max and min for power 
    int maxPower = 15;
    int minPower =0;
    
    //set score surfaces
    std::stringstream ss3,ss4;
    ss3.str(""); // empty the stringstream
    ss3.clear();
    ss4.str(""); // empty the stringstream
    ss4.clear();
    ss3 << score;
    ss4 << scoreHole;
    std::string s5= "Total Score: " + ss3.str();
    std::string s6= "Hole Score: " + ss4.str();
    scoreText = TTF_RenderText_Solid( font, s5.c_str(), textColor ); 
    scoreHoleText = TTF_RenderText_Solid( font, s6.c_str(), textColor );
    
    int xposScore = ( ( SCREEN_WIDTH - scoreText->w ) - 2)  ;
    int yposScore = 10;
    
    //textual representation of the distance to hole
    std::stringstream ss1,ss2;
    ss1.str(""); // empty the stringstream
    ss1.clear();
    ss2.str(""); // empty the stringstream
    ss2.clear();
    ss1 << abs(horzDist);
    ss2 << vertDist;
    std::string s1= ss1.str();
    std::string s2= ss2.str();
    std::string s3;
    if(horzDist < 0)
      s3= s1+ "m <--- ";
    else
      s3= s1+ "m --->";
      
    std::string s4= "Distance to hole: "+s2 + "m";
               
    horzText = TTF_RenderText_Solid( font, s3.c_str(), textColor );
    vertText = TTF_RenderText_Solid( font, s4.c_str(), textColor );
    
    //place distance counters
    int xposDistance = xposPowerbar;
    int yposDistance = yposPowerbar + currentPowerbar->h + 25;
     
     //set up the keystates        
     Uint8* keystates = SDL_GetKeyState( NULL );          
     
     //display hit screen 
    if(horzDist == 0 && vertDist == 0)
    {
         hitText = TTF_RenderText_Solid( font2, "NICE SHOT!", textColor2);
         apply_surface( 0, 0, background, screen);
         apply_surface( (SCREEN_WIDTH - hitText->w ) / 2, (SCREEN_HEIGHT - hitText->h ) / 2, hitText, screen);
         SDL_Flip( screen );
         usleep(2000000);
         stats[0] = power;
         stats[1] = alpha;
         stats[2] = angle; 
         return stats;
     }
     
    //Display missed hole
    if(horzDist == -6 && vertDist == -6)
    {
         hitText = TTF_RenderText_Solid( font2, "You Missed the Hole!", textColor2);
         apply_surface( 0, 0, background, screen);
         apply_surface( (SCREEN_WIDTH - hitText->w ) / 2, (SCREEN_HEIGHT - hitText->h ) / 2, hitText, screen);
         SDL_Flip( screen );
         usleep(2000000);
         stats[0] = power;
         stats[1] = alpha;
         stats[2] = angle; 
         return stats;
     }
     
     //Display end screen
     if(horzDist == -7 && vertDist == -7)
    {
         hitText = TTF_RenderText_Solid( font2, "Congrats!", textColor2);
         scoreText = TTF_RenderText_Solid( font2, s5.c_str(), textColor2 );
         apply_surface( 0, 0, background, screen);
         apply_surface( (SCREEN_WIDTH - hitText->w ) / 2, (SCREEN_HEIGHT - hitText->h ) / 4 - 50, hitText, screen);
         apply_surface( (SCREEN_WIDTH - scoreText->w ) / 2, 3 * (SCREEN_HEIGHT - scoreText->h ) / 4, scoreText, screen);
         SDL_Flip( screen );
         usleep(7000000);
         stats[0] = power;
         stats[1] = alpha;
         stats[2] = angle; 
         return stats;
     }


     
    //loop until the user quits       
    while( quit == false )
    {
         //ensures that the program closes when the user exits
         while( SDL_PollEvent( &event ) )
         {
             if( event.type == SDL_QUIT )
             {
                 quit = true;
                 clean_up();
                 exit(1);
             }
         }
            
         //apply the background and frisbee and current powerbar and arrow and angle and distances
         apply_surface( 0, 0, background, screen);
         apply_surface( xposFris, yposFris, frisbee1, screen);
         apply_surface( xposPowerbar, yposPowerbar, currentPowerbar, screen);
         apply_surface( xposArrow, yposArrow, currentArrow, screen);
         apply_surface( xposAngle, yposAngle, currentAngle, screen);
         apply_surface( xposDistance, yposDistance, horzText, screen);
         apply_surface( xposDistance, yposDistance +35 , vertText, screen);
         apply_surface( xposScore, yposScore, scoreText, screen);
         apply_surface( xposScore, yposScore + 35, scoreHoleText, screen);
         
         
         //If there is no music playing
         if( Mix_PlayingMusic() == 0 )
         {
             //Play the music
             Mix_PlayMusic( music, -1 ); 
         }
         
         //get the state of all of the keys
         SDL_PumpEvents();
         
         //monitor user keystrokes
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
         
         //check current horizontal angle
         switch( arrowCount )
         {
             case -3:
                 currentArrow = left45;
                 angle = -45;
             break;
             case -2:
                 currentArrow = left30;
                 angle = -30;
             break;
             case -1:
                 currentArrow = left15;
                 angle = -15;
             break;
             case 0:
                 currentArrow = arrow0;
                 angle = 0;
             break;
             case 1:
                 currentArrow = right15;
                 angle = 15;
             break;
             case 2:
                 currentArrow = right30;
                 angle = 30;
             break;
             case 3:
                 currentArrow = right45;
                 angle = 45;
             break;
             default:
                 currentArrow = arrow0;
                 angle = 0;
             break;
         }   
         
         //check current vertical angle
         switch( angleCount )
         {
             case 0:
             	currentAngle = angle0;
             	alpha = 0;    
             break;
             case 1:
             	currentAngle = angle3;   
             	alpha = 3;
             break;
             case 2:
             	currentAngle = angle6;   
             	alpha = 6; 
             break;
             case 3:
             	currentAngle = angle9;
             	alpha = 9;    
             break;
             case 4:
             	currentAngle = angle12;
             	alpha = 12;    
             break;
             case 5:
             	currentAngle = angle15;   
             	alpha = 15; 
             break;
             default:
             	currentAngle = angle0;
             	alpha = 0;
            break;
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
                 
                 if( keystates[SDLK_RETURN] )
                 {
                     fly_away(arrowCount);
                     stats[0] = power;
         	     stats[1] = alpha;
         	     stats[2] = angle; 
                     return stats;
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
               
               //apply the background and frisbee
               apply_surface( 0, 0, background, screen);
               apply_surface( xposFris, yposFris, frisbee1, screen);
               
               //display power bar
               apply_surface ( xposPowerbar, yposPowerbar, currentPowerbar, screen);              
               
               //numerical power
               //apply_surface( 3 * SCREEN_WIDTH / 4, 3 * SCREEN_HEIGHT / 4, message, screen);
               
                //Update the screen
                if( SDL_Flip( screen ) == -1 )
                {
                   std::cout<<"Error in updating screen"<<std::endl;
                }
                 
                 usleep(10000);
             }
         }
         
         //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            std::cout<<"Error in updating screen"<<std::endl;
        }
         
        usleep(50000); 
     }
     
     //clean up the surfaces
     //clean_up();
     
     stats[0] = power;
     stats[1] = alpha;
     stats[2] = angle;
     return stats;
}


void playHole(int holeName, Hole currentHole, Player jimmy, int *score )
{
    //array of things to pass from graphics to disc class
    double* stuff;   
    int scoreHole = 0 ;
    Disc disc;
    int past = 0;
    int diff;
    
    std::string currentPic;
    
     while( !disc.checkHole(currentHole.getX(), currentHole.getY()) && !past)
    {
    	currentPic = disc.pickScreen(holeName);
    	
    	//cout << currentPic << endl;
    	
    	//play the current hole
        stuff = play(currentPic, jimmy.getSong(), currentHole.getY() - disc.getY(), currentHole.getX() - disc.getX(), *score, scoreHole);
        //throw the frisbee
        disc.letFly(stuff[0],stuff[1],stuff[2],jimmy.getPower(),jimmy.getAccuracy(), currentHole);
        //track score
        (*score)++;
        scoreHole++;
        
        //see if disc has passed hole
         if(disc.getX() > currentHole.getX()) {
        	past = 1;
        	//cout << "You passed the hole. Auto score set to 8." << endl;
        	diff = 8 - scoreHole;
        	scoreHole = 8;
        	(*score) += diff;
        }
    } 
    	// determine which end screen to show
   	if( past )
		play(currentPic,jimmy.getSong(), -6, -6, *score, scoreHole);  
        else
		play(currentPic,jimmy.getSong(), 0,0, *score, scoreHole);
	
	if( holeName == 5)
		play("../../pictures/Pat_being_a_goon.png",jimmy.getSong(), -7,-7, *score, 0);
}


int title_screen(){

    init();

    //Load the images
    background = load_image( "../../pictures/title_screen.png" );

    //Apply the background to the screen
    apply_surface( 0, 0, background, screen );


    //Update the screen
    SDL_Flip( screen );
	
    //mouse offsets
    int x = 0;
    int y = 0;
    bool quit;

    int choice;
    while(quit == false){

	if(SDL_PollEvent( &event)){

	    if(event.type == SDL_MOUSEBUTTONDOWN)
	    {
               //if left was pressed
		if(event.button.button == SDL_BUTTON_LEFT)
		{
			//get offsets
			x = event.button.x;
			y = event.button.y;

			//choose which button mouse is over

			if((x > 54) && (x < 352) && (y>266) && (y < 346)){
				choice = 1;
				std::cout << "Chose Mickle" << std::endl;
				quit = true;
			}
			if((x > 463) && (x < 718) && (y>266) && (y < 346)){
				choice = 2;
				std::cout << "Chose Lance" << std::endl;
				quit = true;
			}
			if((x > 18) && (x < 400) && (y>368) && (y < 450)){
				choice = 3;
				std::cout << "Chose Freechild" << std::endl;
				quit = true;
			}
			if((x > 447) && (x < 731) && (y>368) && (y < 450)){
				choice = 4;
				std::cout << "Chose Dan" << std::endl;
				quit = true;
			}			
		}
	    }
        }
    }

return choice;
}


int main( int argv, char* argc[])
{
    //create the hole objects
    Hole Hole1 = Hole(100, -5);
    Hole Hole2 = Hole(80, 20);
    Hole Hole3 = Hole(75, -10);
    Hole Hole4 = Hole(90, 0);
    Hole Hole5 = Hole(60, 15);
    
    int score = 0;
    int currentHole = 1;    
    int player;   
    
    //call title screen
    player = title_screen();
    //return num 1-4
    //create all four playable characters
    Player jimmy = Player("Jimmy Mickle",5,4,"../../music/Harder_than_you_think.wav");
    Player nick = Player("Nick Lance",4,5,"../../music/Mind_heist.wav");
    Player dylan = Player("Dylan Freechild",3,5,"../../music/Who_did_that_to_you.wav");
    Player dan = Player("Dan Bolivar",2,2,"../../music/Hymn.wav");
    Player *myPlayer = NULL;
 
    //choose player from title screen
    switch(player) {
    	case 1:
    		myPlayer = &jimmy;
    		break;
    	case 2:
    		myPlayer = &nick;
    		break;
    	case 3:
    		myPlayer = &dylan;
    		break;
    	case 4:
    		myPlayer = &dan;
    		break;
    	default:
    		myPlayer = &jimmy;
		break;
    }
    
    // choose the current hole to play
    while( currentHole < 6)
    {
        switch( currentHole )
        {
            case 1: 
              playHole(1, Hole1, *myPlayer, &score);
            break;
            case 2: 
              playHole(2, Hole2, *myPlayer, &score);
            break;
            case 3: 
              playHole(3, Hole3, *myPlayer, &score);
            break;
            case 4: 
              playHole(4, Hole4, *myPlayer, &score);
            break;
            case 5: 
              playHole(5, Hole5, *myPlayer, &score);
            break;
        }  
        
        //increment current hole
        currentHole++;
    }
    
    clean_up();
    
    return 0;
}
