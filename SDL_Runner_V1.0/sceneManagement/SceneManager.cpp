#include "SceneManager.h"
#include "PauseScene.h"

static SceneManager *instance = 0;

SceneManager* SceneManager::getInstance(){
	if(instance == 0){
		instance = new SceneManager();
	}
	return instance;
}


void SceneManager::init(){
	currentRunningScene = 0;
}

void SceneManager::cleanup(){
	delete instance;
}


void SceneManager::runwithscene(Scene* scene){

	if(currentRunningScene != 0 ){
		delete currentRunningScene;
	}

	currentRunningScene = scene;
	currentRunningScene->run();
}

