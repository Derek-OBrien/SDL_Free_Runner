
#include "../gameStructure/LWindow.h"
#include "SceneManager.h"
#include "SplashScene.h"
#include "MenuScene.h"
#include "../dao/AssetsDao.h"

void SplashScene::init(){
	Scene::init();

	std::cout << "SplashScene  Init!" << std::endl;

	//Load Game Window on init
	LWindow::getInstance()->init(
		"SDL Free Runner",		//Name
		SDL_WINDOWPOS_UNDEFINED,//Position
		SDL_WINDOWPOS_UNDEFINED,//Position
		GAME_HEIGHT,			//Height
		GAME_WIDTH,				//Width
		SDL_WINDOW_SHOWN);		//Flag

	Path path = AssetsDAO::getInstance()->read("splash");
	bg.create(path.getText());
}

void SplashScene::run(){

	if (!initCompleted){
		init();
	}

	std::cout << "SplashScene  Running!" << std::endl;
	thisSceneState = RUNNING;
	int lifetimeofscene = 100;


	//Scene Run Loop
	while (thisSceneState == RUNNING){
		//Render everything
		lifetimeofscene--;
		if (lifetimeofscene < 1){
			bg.cleanup();
			thisSceneState = DESTROY;
		}


		bg.render();
		SDL_RenderPresent(LWindow::getInstance()->getRenderer());

	}

	//Next Scene to load
	MenuScene* nextScene = new MenuScene();
	SceneManager::getInstance()->runwithscene(nextScene);
}


void SplashScene::cleanup(){
	bg.cleanup();
}