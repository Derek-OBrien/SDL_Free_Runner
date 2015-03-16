#include "sceneManagement\SceneManager.h"
#include "sceneManagement\SplashScene.h"

#include <SDL.h>

int main(int argc, char* args[]){
	
	SplashScene* splash = new SplashScene();

	bool quit = false;
	SDL_Event e;	//Event handler
	while (!quit){ //Run Main Loop untill player quits

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0){

			//User requests quit
			if (e.type == SDL_QUIT){
				quit = true;
			}
		}

		//Create & Run Game
		SceneManager::getInstance()->runwithscene(splash);
	}

	return 0;
}