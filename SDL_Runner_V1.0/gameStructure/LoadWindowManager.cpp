
#include "LoadWindowManager.h"


bool LoadWindowManager::init(const char* title, int height, int width, int flags){
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else{
		//Create window
		gWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
		if (gWindow == NULL){
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags)){
				printf(" 1 SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			else{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}

	loadMedia();

	//Apply the PNG image
	SDL_BlitSurface(gPNGSurface, NULL, gScreenSurface, NULL);

	//Update the surface
	SDL_UpdateWindowSurface(gWindow);
	return success;
}

//Cleanup
void LoadWindowManager::cleanup(){
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


bool LoadWindowManager::loadMedia(){
	//Loading success flag
	bool success = true;

	//Load PNG surface
	gPNGSurface = loadSurface("../SDL_Runner_V1.0/assets/background.png");
	if (gPNGSurface == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}

	return success;
}


SDL_Surface* LoadWindowManager::loadSurface(std::string path){
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}