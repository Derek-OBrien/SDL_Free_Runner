#ifndef _LOAD_WINDOW_MANAGER_
#define _LOAD_WINDOW_MANAGER_

#include <SDL.h>	//Include SDL Header
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>


//Load Window Manager looks after loading up the SDL window
class LoadWindowManager{
public:
	LoadWindowManager(){  };
	~LoadWindowManager(){ this->cleanup(); };

	virtual bool init(const char* title, int height, int width, int flags);
	virtual void cleanup();

	bool loadMedia();
	SDL_Window* gWindow = NULL;					//The window we'll be rendering to
	SDL_Surface* gScreenSurface = NULL;			//The surface contained by the window
	SDL_Surface* loadSurface(std::string path);	//Loads individual image
	SDL_Surface* gPNGSurface = NULL;			//Current displayed PNG image


	//Screen dimension constants
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 640;
};
#endif //_LOAD_WINDOW_MANAGER_