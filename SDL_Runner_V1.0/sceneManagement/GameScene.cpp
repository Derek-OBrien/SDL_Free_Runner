#include "GameScene.h"
#include "SceneManager.h"
#include "PauseScene.h"
#include "GameOverScene.h"

#include "../gameStructure/GameManager.h"
#include "../gameStructure/SoundManager.h"

void GameScene::init(){
	Scene::init();
	GameManager::getInstance()->init();		//Init Game Scene
	SoundManager::getInstance()->init();
	SoundManager::getInstance()->loadAudio("bgmusic", BG_MUSIC);
}

void GameScene::run(){

	if (!initCompleted){
		init();
	}
	SoundManager::getInstance()->playMusic();

	//thisSceneState = RUNNING;
	setSceneState(RUNNING);

	while (getSceneState() == RUNNING){
		GameManager::getInstance()->handleInput();

		GameManager::getInstance()->render();
		GameManager::getInstance()->checkCollision();
		GameManager::getInstance()->update();

		//Go To Pause Scene
		while (getSceneState() == PAUSED){
			//	std::cout << "Game Scene Paused" << std::endl;
			GameManager::getInstance()->handleInput();
		}
	}



	//Go to Game Over
	if (getSceneState() == DESTROY){
		std::cout << "Game Scene Destroyed" << std::endl;
		SoundManager::getInstance()->stopMusic();

		GameOverScene* nextScene = new GameOverScene();
		SceneManager::getInstance()->runwithscene(nextScene);
	}

	GameManager::getInstance()->cleanup();
}