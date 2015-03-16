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

GameManager* GameManagerInstance = 0;//instance of the object to be used
GameManager* GameManager::getInstance(){
	if (GameManagerInstance == 0){						//if the instance is null
		GameManagerInstance = new GameManager();		//create the instance 
	}													//otherwise
	return GameManagerInstance;						//return the instance
}


//init game manager
bool GameManager::init(){
	gameOver = new GameOverScene();

	mGameRunning = true;
	collided = false;

	bg = new ScrollingBackground();
	ground = bg->getGround();
	player = new Player();	//Constructor Calls player->init();

	playerBody = player->getPlayer();

	//GameLoop();//call update loop
	return true;
}

//Game manager gameloop
void GameManager::GameLoop(){
	
	bool quit = false;
	SDL_Event e;	//Event handler
	while (mGameRunning){ //Run Main Loop untill player quits

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0){
			//User requests quit
			if (e.type == SDL_QUIT){
				mGameRunning = false;
			}

			player->handleInput(e);
		}

		//Clear Screen 
		SDL_SetRenderDrawColor(LWindow::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(LWindow::getInstance()->getRenderer());
		
		
		//Render everything
		render();
		SDL_RenderPresent(LWindow::getInstance()->getRenderer());

		//Call each obstical’s update
		bg->update();
		player->update();

		//Call the collision manager to check collisions
		collided = CollisionManager::getInstance()->checkCollision(playerBody->getObjectBoundingBox(), ground->getObjectBoundingBox());
		
		if (collided == true){
		}
	}
	//Call deconstructor to clean up 
	cleanup();
}

void GameManager::render(){
	bg->renderBg();		//Render Background
	player->render();	//Render Player
	bg->renderFg();
}


//Clean up Everything 
void GameManager::cleanup(){
	player->cleanup();
	bg->cleanup();

	SDL_DestroyRenderer(LWindow::getInstance()->getRenderer());	//Move to Game over Scene
	SDL_DestroyWindow(LWindow::getInstance()->getWindow());		//Move to Game over Scene
	SDL_Quit();
}
