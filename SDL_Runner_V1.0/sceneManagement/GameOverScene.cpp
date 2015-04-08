#include "GameOverScene.h"
#include "SceneManager.h"
#include "../dao/AssetsDao.h"
#include "../gameStructure/LWindow.h"

void GameOverScene::init(){
	Scene::init();

	Path path = AssetsDAO::getInstance()->read("sceneBg");
	bg.loadMedia(path.getText());

	label = new Label();
	closebutton = new Button();
	restart = new Button();

	hud = new HudLayer();
	scoreLabel = new Label();
}

void GameOverScene::run()
{
	if (!initCompleted)
	{
		init();
	}
	thisSceneState = RUNNING;

	label->create("-[Game Over]-", 50, { 0, 0, 0 });
	closebutton->create("closebutton");
	restart->create("restart");
	scoreLabel = hud->getScore();

	bool quit = false;
	SDL_Event e;	//Event handler

	while(thisSceneState == RUNNING){

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0){
			closebutton->handleMouseEvent(&e);
			restart->handleMouseEvent(&e);
			//User requests quit
			if (e.type == SDL_QUIT){
				quit = true;
				SDL_Quit();
				LWindow::getInstance()->cleanup();
				cleanup();
			}
		}

		bg.render(255);
		label->render((GAME_WIDTH / 2), 80);
		closebutton->render("closebutton");
		restart->render("restart");
		SDL_RenderPresent(LWindow::getInstance()->getRenderer());

	}
}

void GameOverScene::cleanup(){
	label->cleanup();
	closebutton->cleanup();
	restart->cleanup();
	bg.cleanup();
}