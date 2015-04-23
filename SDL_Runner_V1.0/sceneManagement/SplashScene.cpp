/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: SplashScene.cpp
-

-
*/
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
		"In The Smoke",		//Name
		0,//Position
		0,//Position
		GAME_HEIGHT,			//Height
		GAME_WIDTH,				//Width
		SDL_WINDOW_FULLSCREEN);// || SDL_WINDOW_ALLOW_HIGHDPI);		//Flag

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


		bg.render(255);
		label->render((GAME_WIDTH / 2), (GAME_HEIGHT /5));

		SDL_RenderPresent(LWindow::getInstance()->getRenderer());

		if (lifetimeofscene < 1){
			bg.cleanup();
			thisSceneState = DESTROY;
		}
	}

	//Next Scene to load
	MenuScene* nextScene = new MenuScene();
	SceneManager::getInstance()->runwithscene(nextScene);
}


void SplashScene::cleanup(){
	bg.cleanup();
	label->cleanup();
}