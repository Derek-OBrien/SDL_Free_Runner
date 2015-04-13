#include "SceneManager.h"

//Create singleton
static SceneManager *instance = 0;
SceneManager* SceneManager::getInstance(){
	if(instance == 0){
		instance = new SceneManager();
	}
	return instance;
}

//Init Scnen
void SceneManager::init(){
	currentRunningScene = 0;
}

//Clean up Scne
void SceneManager::cleanup(){
	delete instance;
}

//Run selected Scene
void SceneManager::runwithscene(Scene* scene){

	if(currentRunningScene != 0 ){
		delete currentRunningScene;
	}

	currentRunningScene = scene;
	currentRunningScene->run();
}

