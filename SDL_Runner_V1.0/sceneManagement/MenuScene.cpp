#include "MenuScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "../gameStructure/LWindow.h"

void MenuScene::init(){
	Scene::init();


	bg.loadMedia("../SDL_Runner_V1.0/assets/backgrounds/menu.png");
}

void MenuScene::run(){

	if (!initCompleted){
		init();
	}

	thisSceneState = RUNNING;

	int lifetimeofscene = 100;

	while (thisSceneState == RUNNING){
		std::cout << "Menu Scene Running!" << std::endl;
		//SDL_Event e;	//Event handler

		lifetimeofscene--;


		if (lifetimeofscene < 1){
			bg.cleanup();
			thisSceneState = DESTROY;
		}


/*		//Handle events on queue
		while (SDL_PollEvent(&e) != 0){
			//User requests quit
			if (e.type == SDL_KEYDOWN){
				if (e.key.keysym.sym = SDLK_SPACE){
					thisSceneState = DESTROY;
					bg.cleanup();
				}
			}
		}
*/
		bg.render();
	}

	GameScene* nextScene = new GameScene();
	SceneManager::getInstance()->runwithscene(nextScene);
}