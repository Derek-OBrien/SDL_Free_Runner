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
#include "SoundManager.h"
#include "../sceneManagement/SceneManager.h"
#include "../sceneManagement/GameOverScene.h"

#include <Windows.h>

GameManager* GameManagerInstance = 0;			//instance of the object to be used
GameManager* GameManager::getInstance(){
	if (GameManagerInstance == 0){						//if the instance is null
		GameManagerInstance = new GameManager();		//create the instance 
	}													//otherwise
	return GameManagerInstance;						//return the instance
}


/*
	Game Manager Init()
	Create all game elements here
	Each elements constructor calls its own init menthod
	@return bool
	*/
bool GameManager::init(){

	player = new Player();

	bg_city = new ScrollingBackground();
	bg = new ScrollingBackground();
	fg = new ScrollingBackground();

	timer = new LTimer();
	hud = new HudLayer();

	shield = new Collectable();
	popEnemies = new PopulateEnemies();


	collided = false;
	return true;
}

/*
	Game Manager create
	Call each game elemets create function

	*/
void GameManager::create(){

	if (!init()){
		init();
	}
	player->create();
	bg_city->create("cityBg");
	bg->create("gameBg");
	fg->create("gameFg");
	timer->create();
	hud->create("hud");
	shield->create("shield", 100, 100);
	birdVector = popEnemies->populateBirdVector();
	coinVector = popEnemies->populateCollectVector();
}

/*
	call each game objects render
	Z-order goes in order there called => 1st = 0
	*/
void GameManager::render(){
	//Clear Screen 
	SDL_SetRenderDrawColor(LWindow::getInstance()->getRenderer(), 0x00, 0x00, 0x00, 255);
	SDL_RenderClear(LWindow::getInstance()->getRenderer());

	//Render Backgrounds
	bg_city->render("cityBg");
	bg->render("gameBg");

	//Render Player & Game Objects
	player->render();
	shield->render();

	for (int i = 0; i < (int)birdVector.size(); i++){
		birdVector.at(i)->render();
	}

	for (int i = 0; i < (int)coinVector.size(); i++){
		coinVector.at(i)->render();
	}


	fg->render("gameFg");//Render ForeGround 
	hud->render();		//Render Hud Layer

	//Refresh Screen
	SDL_RenderPresent(LWindow::getInstance()->getRenderer());
}

/*
	Game Manager Update Function
	Calls all game elements update functions
	*/
void GameManager::update(){
	//Scroll Bacckgrounds
	bg_city->update();
	bg->update();
	fg->update();

	//Update Score Count
	hud->update();

	//Update Npc & Coins Positions
	shield->update();
	popEnemies->update();
}

/*
	Handle all input in game scene
	Calls Palyer & Hud input functions
	*/
void GameManager::handleInput(){
	bool quit = false;
	SDL_Event e;	//Event handler

	//Get current running scene
	Scene* scene = SceneManager::getInstance()->getCurrentScene();

	//Handle events on queue
	while (SDL_PollEvent(&e) != 0){

		//Handle input for player actions
		player->handleInput(e);
		//Handle input for Hud Elements
		hud->handleInput(e);

	}
}


/*
	Check collision between player and game objects
	Calls CollisionManager singleton and takes in game elements bouding box to check for collision
	*/
void GameManager::checkCollision(){
	//Get Player State
	int stateCheck = player->getPlayerState();

	//Check for Collision with Power Up
	if (CollisionManager::getInstance()->checkCollision(player->getPlayerCollisionBox(), shield->getCollectableCollisionBox())){

		//Reset Shield Position
		shield->resetPosition();

		//Activate power up
		player->powerUp();
		stateCheck = player->getPlayerState();
		SoundManager::getInstance()->playSfx("sfx");

	}

	else{
		for (int i = 0; i < (int)birdVector.size(); i++){
			//Check For Collision with Collectable
			if (CollisionManager::getInstance()->checkCollision(player->getPlayerCollisionBox(), coinVector.at(i)->getCollectableCollisionBox())){
				//Reset Position and update coin count#
				SoundManager::getInstance()->playSfx("sfx");
				coinVector.at(i)->resetPosition();
				hud->updateCoinCount();
			}
			//Check For collision with enemy
			if (CollisionManager::getInstance()->checkCollision(player->getPlayerCollisionBox(), birdVector.at(i)->getNpcCollisionBox())){

				//check player state for power up
				if (stateCheck == (int)POWERUP){
					//Remove bird
					birdVector.at(i)->resetPosition();
					player->setPlayerState(ALIVE);
					player->loadMedia(player->getName());
					
				}
				else{

					//change player state and clean up player
					player->setPlayerState(DEAD);
					player->cleanup();

					//Save current score & check if high score
					hud->saveScore();
					hud->checkIfHighScore();

					//Change to game over scene
					Scene* scene = SceneManager::getInstance()->getCurrentScene();
					scene->setSceneState(DESTROY);
				}
			}
		}
	}
}


//Clean up Everything 
void GameManager::cleanup(){
	//Clean up player
	player->cleanup();

	//Clean up background and Foreground layers
	bg_city->cleanup();
	bg->cleanup();
	fg->cleanup();

	//Clean up game objects
	shield->cleanup();
	popEnemies->cleanup();
}
