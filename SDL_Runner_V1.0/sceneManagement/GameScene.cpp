#include "GameScene.h"
#include "SceneManager.h"
#include "PauseScene.h"
#include "GameOverScene.h"

#include "../gameStructure/GameManager.h"

void GameScene::init(){
	Scene::init();
	GameManager::getInstance()->init();		//Init Game Scene
}

void GameScene::run(){

	if (!initCompleted){
		init();
	}
	//thisSceneState = RUNNING;
	setSceneState(RUNNING);

	while (getSceneState() == RUNNING){
		//std::cout << "Game Scene Running!" << std::endl;

		GameManager::getInstance()->render();
		GameManager::getInstance()->update();
		GameManager::getInstance()->handleInput();
		GameManager::getInstance()->checkCollision();

		
	}

	//Go To Pause Scene
	while (getSceneState()== PAUSED){
		std::cout << "Game Scene Paused" << std::endl;

		PauseScene* nextScene = new PauseScene();
		SceneManager::getInstance()->runwithscene(nextScene);
	}

	//Go to Game Over
	while (getSceneState() == DESTROY){
		std::cout << "Game Scene Destroyed" << std::endl;

		GameOverScene* nextScene = new GameOverScene();
		SceneManager::getInstance()->runwithscene(nextScene);
	}

	GameManager::getInstance()->cleanup();
}