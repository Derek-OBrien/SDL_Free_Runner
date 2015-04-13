#include "GameScene.h"
#include "SceneManager.h"
#include "GameOverScene.h"

#include "../gameStructure/GameManager.h"
#include "../gameStructure/SoundManager.h"

//Init All
void GameScene::init(){
	Scene::init();
	GameManager::getInstance()->init();		//Init Game Scene
	SoundManager::getInstance()->init();
	SoundManager::getInstance()->loadAudio("bgmusic", BG_MUSIC);
}

/*
		Main Game Loop
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
		//Handle input
		GameManager::getInstance()->handleInput();
		//Continously check for collision
		GameManager::getInstance()->checkCollision();
		//Update game elements
		GameManager::getInstance()->update();
		//Render everything
		GameManager::getInstance()->render();

		//Go To Pause Scene
		while (getSceneState() == PAUSED){
			GameManager::getInstance()->handleInput();
		}
	}


	//Go to Game Over
	if (getSceneState() == DESTROY){
		std::cout << "Game Scene Destroyed" << std::endl;
		SoundManager::getInstance()->stopMusic();
		GameManager::getInstance()->cleanup();

		GameOverScene* nextScene = new GameOverScene();
		SceneManager::getInstance()->runwithscene(nextScene);
	}

	GameManager::getInstance()->cleanup();
}