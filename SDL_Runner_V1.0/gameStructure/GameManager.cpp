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
#include "../sceneManagement/PauseScene.h"
#include "../sceneManagement/GameOverScene.h"

#include <Windows.h>

GameManager* GameManagerInstance = 0;//instance of the object to be used
GameManager* GameManager::getInstance(){
	if (GameManagerInstance == 0){						//if the instance is null
		GameManagerInstance = new GameManager();		//create the instance 
	}													//otherwise
	return GameManagerInstance;						//return the instance
}


//init game manager
bool GameManager::init(){

	//	SoundManager::getInstance()->loadAudio("bgmusic");
	player = new Player();

	bg_city = new ScrollingBackground();
	bg_city->create("cityBg");
	bg = new ScrollingBackground();
	bg->create("gameBg");
	fg = new ScrollingBackground();
	fg->create("gameFg");

	timer = new LTimer();
	timer->create();
	hud = new HudLayer();
	hud->create("hud");

	popEnemies = new PopulateEnemies();
	birdVector = popEnemies->populateBirdVector();
	bugVector = popEnemies->populateBugVector();

	for (int i = 0; i < birdVector.size(); i++){
		switch (i){
		case 0:
			npcX = GAME_WIDTH + (GAME_WIDTH *0.2);
			npcY = 250;
			birdVector.at(i)->create("bird", npcX, npcY);
			break;
		case 1:
			npcX = GAME_WIDTH + (GAME_WIDTH *0.4);
			npcY = 300;
			birdVector.at(i)->create("bird", npcX, npcY);
			break;
		case 2:
			npcX = GAME_WIDTH + (GAME_WIDTH*0.6);
			npcY = 370;
			birdVector.at(i)->create("bird", npcX, npcY);
			break;
		case 3:
			npcX = GAME_WIDTH + (GAME_WIDTH*0.1);///slideunder
			npcY = 450;
			birdVector.at(i)->create("bird", npcX, npcY);
			break;
		case 4:
			npcX = GAME_WIDTH + (GAME_WIDTH*0.7);///slide under
			npcY = 450;
			birdVector.at(i)->create("bird", npcX, npcY);
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < bugVector.size(); i++){
		bugVector.at(i)->create("bug", GAME_WIDTH, 500);
	}

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

	bg_city->render("cityBg");
	bg->render("gameBg");		//Render Background
	player->render();	//Render Player



	for (int i = 0; i < birdVector.size(); i++){

		birdVector.at(i)->render();

	}

	for (int i = 0; i < bugVector.size(); i++){
		bugVector.at(i)->render();
	}



	fg->render("gameFg");		//Render ForeGround 
	hud->render();		//Render Hud Layer
	SDL_RenderPresent(LWindow::getInstance()->getRenderer());

}

void GameManager::update(){
	//SoundManager::getInstance()->playMusic();
	bg_city->update();
	bg->update();
	fg->update();
	hud->update();

	for (int i = 0; i < birdVector.size(); i++){
		birdVector.at(i)->update();
	}
	for (int i = 0; i < bugVector.size(); i++){
		bugVector.at(i)->update();
	}
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
					SoundManager::getInstance()->resumeMusic();
				}
				else{
					scene->setSceneState(PAUSED);
					timer->pause();
					SoundManager::getInstance()->pauseMusic();
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

	for (unsigned int i = 0; i < bugVector.size(); i++){


		if (CollisionManager::getInstance()->checkCollision(player->getPlayerCollisionBox(), bugVector.at(i)->getNpcCollisionBox())){

			Scene* scene = SceneManager::getInstance()->getCurrentScene();
			scene->setSceneState(DESTROY);

			player->setPlayerState(DEAD);
			player->cleanup();
		}
		if (CollisionManager::getInstance()->checkCollision(player->getPlayerCollisionBox(), birdVector.at(i)->getNpcCollisionBox())){

			Scene* scene = SceneManager::getInstance()->getCurrentScene();
			scene->setSceneState(DESTROY);

			player->setPlayerState(DEAD);
			player->cleanup();
		}
	}
}


//Clean up Everything 
void GameManager::cleanup(){
	player->cleanup();

	bg_city->cleanup();
	bg->cleanup();
	fg->cleanup();
	hud->cleanup();
	for (int i = 0; i < birdVector.size(); i++){
		birdVector.at(i)->cleanup();
	}
	for (int i = 0; i < bugVector.size(); i++){
		bugVector.at(i)->cleanup();
	}
	LWindow::getInstance()->cleanup();
	SDL_Quit();
}
