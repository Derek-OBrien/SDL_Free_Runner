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
#include "../sceneManagement/SceneManager.h"
#include "../sceneManagement/PauseScene.h"

GameManager* GameManagerInstance = 0;//instance of the object to be used
GameManager* GameManager::getInstance(){
	if (GameManagerInstance == 0){						//if the instance is null
		GameManagerInstance = new GameManager();		//create the instance 
	}													//otherwise
	return GameManagerInstance;						//return the instance
}


//init game manager
bool GameManager::init(){

	mGameRunning = true;
	collided = false;

	bg = new ScrollingBackground();
	ground = bg->getGround();

	player = new Player();	//Constructor Calls player->init();
	playerBody = player->getPlayer();

	obstical = new Obstical();
	obsticalBody = obstical->getObstical();

	return true;
}

//Game manager gameloop
void GameManager::GameLoop(){
	//Run Main Loop untill player quits
	while (mGameRunning){ 
		
		//Render everything
		render();
		
		//Check Collision
		checkCollision();

		//Handle input
		handleInput();

		//Update everything
		update();
	}
	//Call deconstructor to clean up 
	cleanup();
}

/*
	call each game objects render
	Z-order goes in order there called => 1st = 0
	*/
void GameManager::render(){
	//Clear Screen 
	SDL_SetRenderDrawColor(LWindow::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(LWindow::getInstance()->getRenderer());

	bg->renderBg();		//Render Background

	obstical->render();	//Render Obstical
	player->render();	//Render Player

	bg->renderFg();		//Render ForeGround Smoke
	SDL_RenderPresent(LWindow::getInstance()->getRenderer());

}

void GameManager::update(){
	obstical->update();
}

void GameManager::handleInput(){
	bool quit = false;
	SDL_Event e;	//Event handler

	Scene* scene = SceneManager::getInstance()->getCurrentScene();

	//Handle events on queue
	while (SDL_PollEvent(&e) != 0){
		//User requests quit

		//Handle input for player actions
		player->handleInput(e);

		//If space pressed Pause Game
		if (e.type == SDL_KEYDOWN){
			if (e.key.keysym.sym == SDLK_SPACE){
				std::cout << "Space Pressed Pause Game Scene" << std::endl;
				
				scene->setSceneState(PAUSED);

			}
		}

		//Quit 
		if (e.type == SDL_QUIT){
			scene->setSceneState(DESTROY);
			scene->cleanup();
			cleanup();
		}
	}//End of Handle Input
}

//Check Collision
void GameManager::checkCollision(){
	
}

//Clean up Everything 
void GameManager::cleanup(){
	player->cleanup();
	bg->cleanup();

	SDL_DestroyRenderer(LWindow::getInstance()->getRenderer());	//Move to Game over Scene
	SDL_DestroyWindow(LWindow::getInstance()->getWindow());		//Move to Game over Scene

	SDL_Quit();
}
