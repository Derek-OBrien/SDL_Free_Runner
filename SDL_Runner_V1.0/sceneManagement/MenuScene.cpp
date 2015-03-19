#include "MenuScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "../gameStructure/LWindow.h"

#include "../dao/AssetsDao.h"

void MenuScene::init(){
	Scene::init();

	bg.loadMedia("../SDL_Runner_V1.0/assets/backgrounds/menu.png");
}

void MenuScene::run(){

	if (!initCompleted){
		init();
	}

	thisSceneState = RUNNING;

	while (thisSceneState == RUNNING){
		std::cout << "Menu Scene Running!" << std::endl;
		SDL_Event e;	//Event handler


	//Handle events on queue
		while (SDL_PollEvent(&e) != 0){
			if (e.type == SDL_KEYDOWN){
				if (e.key.keysym.sym == SDLK_SPACE){
					//Destroy Scene and load Game Scene
					thisSceneState = DESTROY;
					bg.cleanup();
				}
			}
		}

		bg.render();
	}

	GameScene* nextScene = new GameScene();
	SceneManager::getInstance()->runwithscene(nextScene);
}