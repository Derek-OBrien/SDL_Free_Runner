/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: GameScene.cpp
-

-
*/

//Includes
#include "GameScene.h"
#include "SceneManager.h"
#include "GameOverScene.h"

#include "../gameStructure/GameManager.h"
#include "../gameStructure/SoundManager.h"

//Init All
void GameScene::init(){
	Scene::init();			//init scene
	GameManager::getInstance()->init();		//Init Game Manager
	SoundManager::getInstance()->init();	//Init Sound Manager
	SoundManager::getInstance()->loadAudio("bgmusic", BG_MUSIC);	//Load Background Audio

	std::cout << "GameScene init" << std::endl;
}

/*
		Game Scene run
		Contains main game loop
*/
void GameScene::run(){
	//Check init 
	if (!initCompleted){
		init();
	}
	//Play bg music
	SoundManager::getInstance()->playMusic();
	//Create all game elements
	GameManager::getInstance()->create();
	//Set scene to running
	setSceneState(RUNNING);

	//Game Loop
	while (getSceneState() == RUNNING){
		//Continously Handle input
		GameManager::getInstance()->handleInput();

		//Continously check for collision
		GameManager::getInstance()->checkCollision();
		
		//Continously Update game elements
		GameManager::getInstance()->update();
		
		//Continously Render everything
		GameManager::getInstance()->render();

		//Go To Pause Scene
		while (getSceneState() == PAUSED){
			//Handle input on pause scene
			GameManager::getInstance()->handleInput();
		}
	}


	//Go to Game Over
	if (getSceneState() == DESTROY){
		std::cout << "Game Scene Destroyed" << std::endl;
		//Stop music and clean up game
		SoundManager::getInstance()->stopMusic();
		GameManager::getInstance()->cleanup();

		//Load Game Over Scene
		GameOverScene* nextScene = new GameOverScene();
		SceneManager::getInstance()->runwithscene(nextScene);
	}

	//Clean up game Manager
	GameManager::getInstance()->cleanup();
}