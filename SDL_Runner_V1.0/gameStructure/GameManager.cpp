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
#include "../sceneManagement/GameOverScene.h"

GameManager* GameManagerInstance = 0;//instance of the object to be used
GameManager* GameManager::getInstance(){
	if (GameManagerInstance == 0){						//if the instance is null
		GameManagerInstance = new GameManager();		//create the instance 
	}													//otherwise
	return GameManagerInstance;						//return the instance
}


//init game manager
bool GameManager::init(){

	player = new Player();
	obstical = new Obstical();

	bg = new ScrollingBackground();
	bg->create("gameBg");
	fg = new ScrollingBackground();
	fg->create("gameFg");

	timer = new LTimer();
	timer->create();

	hud = new HudLayer();
	hud->create("hud");

	collided = false;
	return true;
}


/*
	call each game objects render
	Z-order goes in order there called => 1st = 0
	*/
void GameManager::render(){
	//Clear Screen 
	SDL_SetRenderDrawColor(LWindow::getInstance()->getRenderer(), 0x00, 0x00, 0x00, 255);
	SDL_RenderClear(LWindow::getInstance()->getRenderer());

	bg->render("gameBg");		//Render Background
	obstical->render();	//Render Obstical
	player->render();	//Render Player
	fg->render("gameFg");		//Render ForeGround 
	hud->render();		//Render Hud Layer

	SDL_RenderPresent(LWindow::getInstance()->getRenderer());

}

void GameManager::update(){
	bg->update();
	fg->update();
	obstical->update();
	hud->update();
}

void GameManager::handleInput(){
	bool quit = false;
	SDL_Event e;	//Event handler

	Scene* scene = SceneManager::getInstance()->getCurrentScene();
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0){

		//Handle input for player actions
		player->handleInput(e);
		hud->handleInput(e);

		//If space pressed Pause Game
		if (e.type == SDL_KEYDOWN){
			if (e.key.keysym.sym == SDLK_SPACE){
				std::cout << "Space Pressed Pause Game Scene" << std::endl;
				
				if (timer->Paused()){
					timer->unpause();
					scene->setSceneState(RUNNING);
				}
				else{
					scene->setSceneState(PAUSED);
					timer->pause();
				}
			}
		}
		//Quit 
		if (e.type == SDL_QUIT){
			scene->cleanup();
			cleanup();
		}
	}//End of Handle Input
}


//Check Collision
void GameManager::checkCollision(){
	
	if (CollisionManager::getInstance()->checkCollision(player->getPlayerCollisionBox(), obstical->getObsticalCollisionBox() )){

		Scene* scene = SceneManager::getInstance()->getCurrentScene();
		scene->setSceneState(DESTROY);

		player->setPlayerState(DEAD);
		player->cleanup();


	}
}


//Clean up Everything 
void GameManager::cleanup(){
	player->cleanup();
	obstical->cleanup();
	bg->cleanup();
	fg->cleanup();

	LWindow::getInstance()->cleanup();
	SDL_Quit();
}
