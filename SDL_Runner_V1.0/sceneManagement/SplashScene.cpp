
#include "../gameStructure/LWindow.h"
#include "SceneManager.h"
#include "SplashScene.h"
#include "MenuScene.h"
#include "../dao/AssetsDao.h"

void SplashScene::init(){
	Scene::init();

	std::cout << "SplashScene  Init!" << std::endl;
	int height = SDL_DisplayMode().h;
	int width = SDL_DisplayMode().w;
	//Load Game Window on init
	LWindow::getInstance()->init(
		"In The Smoke",		//Name
		SDL_WINDOWPOS_UNDEFINED,//Position
		SDL_WINDOWPOS_UNDEFINED,//Position
		GAME_HEIGHT,			//Height
		GAME_WIDTH,				//Width
		SDL_WINDOW_SHOWN );		//Flag

	AssetsDAO* dao = AssetsDAO::getInstance();
	bg.create(dao->read("sceneBg", "path", "assets").getText());

	label = new Label();
}

void SplashScene::run(){

	if (!initCompleted){
		init();
	}

	std::cout << "SplashScene  Running!" << std::endl;
	thisSceneState = RUNNING;
	int lifetimeofscene = 100;
	label->create("-[In The Smoke]-", 70, GREEN);


	//Scene Run Loop
	while (thisSceneState == RUNNING){
		//Render everything
		lifetimeofscene--;
		if (lifetimeofscene < 1){
			bg.cleanup();
			thisSceneState = DESTROY;
		}


		bg.render(255);
		label->render((GAME_WIDTH / 2), (GAME_HEIGHT /5));

		SDL_RenderPresent(LWindow::getInstance()->getRenderer());

	}

	//Next Scene to load
	MenuScene* nextScene = new MenuScene();
	SceneManager::getInstance()->runwithscene(nextScene);
}


void SplashScene::cleanup(){
	bg.cleanup();
	label->cleanup();
}