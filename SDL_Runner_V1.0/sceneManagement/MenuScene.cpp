#include "MenuScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "../gameStructure/LWindow.h"

#include "../dao/AssetsDao.h"

void MenuScene::init(){
	Scene::init();
	std::cout << "MenuScene  Init!" << std::endl;

	AssetsDAO *dao = AssetsDAO::getInstance();
	bg.create(dao->read("sceneBg", "path", "assets").getText());

	player1btn = new Button();
	player2btn = new Button();
	closeButton = new Button();
	label = new Label();
}

void MenuScene::run(){

	if (!initCompleted){
		init();
	}
	std::cout << "Menu Scene Running!" << std::endl;

	//Create Buttons & Label
	player1btn->create("player1btn");
	player2btn->create("player2btn");
	closeButton->create("closebutton");
	label->create("-[Select Your Runner]-", 50, GREEN);
	
	thisSceneState = RUNNING;
	bool quit = false;
	SDL_Event e;	//Event handler

	while (thisSceneState == RUNNING && !quit){
			
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0){
			//Handle mouse in put for buttons
			player1btn->handleMouseEvent(&e);
			player2btn->handleMouseEvent(&e);
			closeButton->handleMouseEvent(&e);
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

		bg.render(255);
		player1btn->render("player1btn");
		player2btn->render("player2btn");
		closeButton->render("closebutton");
		label->render((GAME_WIDTH / 2), 20);

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
	player2btn->cleanup();
	player1btn->cleanup();
	closeButton->cleanup();
	bg.cleanup();
	label->cleanup();
}