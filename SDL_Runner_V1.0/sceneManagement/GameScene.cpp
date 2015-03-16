#include "GameScene.h"
#include "SceneManager.h"
#include "PauseScene.h"


#include "../gameStructure/GameManager.h"

void GameScene::init(){
	Scene::init();
}

void GameScene::run(){

	if(!initCompleted){
		init();
	}
	thisSceneState = RUNNING;

	SDL_Event e;	//Event handler

	//Handle events on queue
	/*while (SDL_PollEvent(&e) != 0){
		if (e.type == SDL_KEYDOWN){
			if (e.key.keysym.sym = SDLK_SPACE){
				thisSceneState = PAUSED;
				std::cout << "Space Pressed" << std::endl;
			}
		}
	}*/


	while(thisSceneState == RUNNING){
		std::cout << "Game Scene Running!" << std::endl;
		
		GameManager::getInstance()->init();		//Init
		GameManager::getInstance()->GameLoop();	//Run Game loop
	}

	while (thisSceneState == PAUSED){

		PauseScene* nextScene = new PauseScene();
		SceneManager::getInstance()->runwithscene(nextScene);
	}
	
}