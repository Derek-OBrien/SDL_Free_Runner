#include "GameScene.h"
#include "SceneManager.h"
#include "PauseScene.h"


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

	}

	//Go To Pause Scene
	while (getSceneState()== PAUSED){
		std::cout << "Game Scene Paused" << std::endl;
		Scene* scene = SceneManager::getInstance()->getCurrentScene();

		PauseScene* nextScene = new PauseScene();
		SceneManager::getInstance()->runwithscene(nextScene);
	}

	GameManager::getInstance()->cleanup();
}