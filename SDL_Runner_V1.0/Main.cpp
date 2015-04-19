/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Main.cpp
-

-
*/
#include "sceneManagement\SceneManager.h"
#include "sceneManagement\SplashScene.h"

#include <SDL.h>

int main(int argc, char* args[]){
	
	SplashScene* splash = new SplashScene();

	bool quit = false;
	SDL_Event e;	//Event handler
	while (!quit){ //Run Main Loop untill player quits

		//Create & Run Game
		SceneManager::getInstance()->runwithscene(splash);
	}

	return 0;
}