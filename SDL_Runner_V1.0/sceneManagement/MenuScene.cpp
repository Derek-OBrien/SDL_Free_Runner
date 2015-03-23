#include "MenuScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "../gameStructure/LWindow.h"

#include "../dao/AssetsDao.h"

void MenuScene::init(){
	Scene::init();
	std::cout << "MenuScene  Init!" << std::endl;

	Path path = AssetsDAO::getInstance()->read("menu");
	bg.create(path.getText());

	playbutton = new Button();
	closebutton = new Button();
}

void MenuScene::run(){

	if (!initCompleted){
		init();
	}
	std::cout << "Menu Scene Running!" << std::endl;

	playbutton->create("playbutton");
	closebutton->create("closebutton");

	thisSceneState = RUNNING;
	bool quit = false;
	SDL_Event e;	//Event handler

	while (thisSceneState == RUNNING && !quit){
			
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0){
			//Handle mouse in put for buttons
			playbutton->handleMouseEvent(&e);
			closebutton->handleMouseEvent(&e);
			
			//User requests quit
			if (e.type == SDL_QUIT){
				quit = true;
				SDL_Quit();
				LWindow::getInstance()->cleanup();
			}
		}

		//Render Background and Buttons
		SDL_SetRenderDrawColor(LWindow::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(LWindow::getInstance()->getRenderer());

		bg.render();
		playbutton->render("playbutton");
		closebutton->render("closebutton");

		SDL_RenderPresent(LWindow::getInstance()->getRenderer());
	}
	
	//Clean up this scene and load next scene
	if (thisSceneState == DESTROY){
		cleanup();
		GameScene* nextScene = new GameScene();
		SceneManager::getInstance()->runwithscene(nextScene);
	}
}


void MenuScene::cleanup(){
	closebutton->cleanup();
	playbutton->cleanup();
	bg.cleanup();
}