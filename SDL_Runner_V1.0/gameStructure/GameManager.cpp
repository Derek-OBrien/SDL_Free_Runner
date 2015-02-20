/*
-          Is the main controller
-          Gets a pointer to a vector of enemies from the worldmanager
-          Gets a pointer to the player from the worldmanager
-          Has the main update method which does the following

Calls the player update
Calls each enemy’s  update
Calls each enemy’s runAI
Calls the collision manager to check collisions
Print statement (“render”)
*/

#include "GameManager.h"	//Include game manager header



//init game manager
bool GameManager::init(){
	mGameRunning = true;
	GameLoop();//call update loop
	return true;
}

//Game manager gameloop
void GameManager::GameLoop(){

	//Create SDL Window & Render Background
	loadWindow = new LoadWindowManager();
	loadWindow->init("SDL FREE RUNNER", loadWindow->SCREEN_HEIGHT, loadWindow->SCREEN_WIDTH, SDL_WINDOW_SHOWN);
	
	bool quit = false;
	SDL_Event e;	//Event handler
	while (!quit){ //Run Main Loop untill player quits
		std::cout << "Game Manager Running!!! :)\n" << std::endl;

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0){
			//User requests quit
			if (e.type == SDL_QUIT){
				quit = true;
			}

			//Handle input for the Player

		}


		//Call each obstical’s update


		//Call the collision manager to check collisions


		//Render everything

	}
	//Call deconstructor to clean up 
	cleanup();
}

//Clean up Everything 
void GameManager::cleanup(){
	loadWindow->cleanup();
	SDL_Quit();
}
