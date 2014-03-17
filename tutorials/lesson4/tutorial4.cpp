/* Connor Brant
SDL Tutorial 4
*/

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

    //Screen attributs 
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int SCREEN_BPP = 32;
    
    //the surfaces to be used
    SDL_Surface *image = NULL;
    SDL_Surface *screen = NULL;
    
    //event structure
    SDL_Event event;
    
    SDL_Surface *load_image(std::string filename)
    {
    	//The image thats loaded
    	SDL_Surface *loadedImage = NULL;
    	
    	//Optimized image to be used
    	SDL_Surface *optimizedImage = NULL;
    	
    	//Load Image
    	loadedImage = IMG_Load(filename.c_str());
    	
    	if(loadedImage != NULL)
    	{
    	    //Create optimized image
    	    optimizedImage = SDL_DisplayFormat(loadedImage);
    	    
    	    //Free old image
    	    SDL_FreeSurface(loadedImage);
    	}
    	
    	// return optimized image
    	return optimizedImage;
    	
   }
   
   void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
   {
       //Temporary Rectangle to hold offsets
       SDL_Rect offset;
       
       offset.x = x;
       offset.y = y;
       
       //Blit the surface
       SDL_BlitSurface(source, NULL, destination, &offset);
       
   }
   
   bool init()
   {
       if( SDL_Init(SDL_INIT_EVERYTHING) ==-1)
       {
           return false;
       }
       
       //set up screen
       screen= SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
       
       if( screen == NULL)
         return false;
         
       //set up window caption
       SDL_WM_SetCaption("Event test", NULL);
       
       return true;
   }
   
   
   bool load_files()
   {
       image = load_image("x.png");
       
       if (image == NULL)
         return false;
         
       return true;
       
   }
   
   
   void clean_up()
   {
       SDL_FreeSurface(image);
       
       SDL_Quit();
   }
   
   
   int main(int argc, char * args[])
   {
       //flag for quit
       bool quit = false;
       
       if (init() == false)
         return 1;
       
       if(load_files() == false)
         return 1;
       
       
       apply_surface(0 , 0, image, screen);
       
       if(SDL_Flip(screen) == -1)
         return 1;
       
       while(quit ==false)
       {
           //while there is an event to handle
           while(SDL_PollEvent(&event))
           {
               //if the user Xs out the window
               if(event.type == SDL_QUIT)
               {
                   //Quit the program
                   quit=true;
               }
               
           }
             
       }
       
       clean_up();
       
       return 0;
   }
