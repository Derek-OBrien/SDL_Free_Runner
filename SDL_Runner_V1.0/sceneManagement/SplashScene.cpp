
#include "../gameStructure/LWindow.h"
#include "SceneManager.h"
#include "SplashScene.h"
#include "MenuScene.h"

void SplashScene::init(){
	Scene::init();

	//Load Game Window on init
	LWindow::getInstance()->init(
		"SDL Free Runner",		//Name
		SDL_WINDOWPOS_UNDEFINED,//Position
		SDL_WINDOWPOS_UNDEFINED,//Position
		GAME_HEIGHT,			//Height
		GAME_WIDTH,				//Width
		SDL_WINDOW_SHOWN);		//Flag

	bg.loadMedia("../SDL_Runner_V1.0/assets/backgrounds/splash.png");
}

void SplashScene::run(){

	if (!initCompleted){
		init();
	}

	thisSceneState = RUNNING;

	int lifetimeofscene = 100;


	while (thisSceneState == RUNNING){
		std::cout << "SplashScene  Running!" << std::endl;
		lifetimeofscene--;


		if (lifetimeofscene < 1){
			bg.cleanup();
			thisSceneState = DESTROY;
		}

		//Render everything
		bg.render();
	}

	//Next Scene to load
	MenuScene* nextScene = new MenuScene();
	SceneManager::getInstance()->runwithscene(nextScene);
}


