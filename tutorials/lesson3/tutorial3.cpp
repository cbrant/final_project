/* Connor Brant
SDL Tutorial 3
*/

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

    //Screen attributs 
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int SCREEN_BPP = 32;
    
    //the surfaces to be used
    SDL_Surface * message = NULL;
    SDL_Surface * background = NULL;
    SDL_Surface * screen = NULL;
    
SDL_Surface *load_image( std::string filename)
{
    //Temp storage for the image that's loaded
    SDL_Surface *loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface *optimizedImage = NULL;
    
    //load image
    loadedImage = IMG_Load(filename.c_str());
    
    //if nothing went wrong in loading the image
    if( loadedImage != NULL)
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat(loadedImage);
        
        //Free the old image
        SDL_FreeSurface( loadedImage);
    }
    
    return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface * source, SDL_Surface * destination)
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
    
    //Blit the surface
    SDL_BlitSurface(source, NULL, destination, &offset);
}

int main(int argc, char * args[])
{
    //initilize all SDL subsystems 
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
      return 1;
    
    //setup the screen
    screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    
    //ensure the screen is initilized
    if(screen == NULL)
      return 1;
      
    //Set window caption
    SDL_WM_SetCaption("Tutorial3",NULL);
    
    //Load the images
    message = load_image("hello.jpg");
    background = load_image("background.bmp");
    
    //apply background to screen
    apply_surface(0,0,background,screen);
    apply_surface(320,0,background,screen);
    apply_surface(0,240,background,screen);
    apply_surface(320,240,background,screen);
    
    //apply hello to screen
    apply_surface(180,140,message,screen);
    
    //update screen
    if(SDL_Flip(screen) == -1)
      return 1;
    
    //wait 5 seconds
    SDL_Delay(5000);
    
    //Free the surfaces
    SDL_FreeSurface(message);
    SDL_FreeSurface(background);
    
    //Quit SDL
    SDL_Quit();
    
    //Return
    return 0;
}
