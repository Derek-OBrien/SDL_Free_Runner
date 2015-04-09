#include "GameOverScene.h"
#include "SceneManager.h"
#include "../dao/AssetsDao.h"
#include "../gameStructure/LWindow.h"

void GameOverScene::init(){
	Scene::init();

	dao = AssetsDAO::getInstance();

	bg.loadMedia(dao->getInstance()->read("sceneBg", "path", "assets").getText());

	//Init labels
	label = new Label();
	scoreLabel = new Label();
	highScoreLabel = new Label();

	//init buttons
	closebutton = new Button();
	restart = new Button();
}

void GameOverScene::run()
{
	if (!initCompleted){
		init();
	}
	thisSceneState = RUNNING;


	//Read Scores from XML 
	currentScore = dao->getInstance()->read("currentScore", "currentScore", "score").getText();
	highScore = dao->getInstance()->read("highScore", "highScore", "score").getText();


	//Create Labels
	label->create("-[Game Over]-", 50, BLACK);
	scoreLabel->create(("-[Your Score : " + currentScore + "]-"), 50, RED);
	highScoreLabel->create(("-[High Score : " + highScore + "]-"), 50, RED);


	//Create Buttons
	closebutton->create("closebutton");
	restart->create("restart");


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

		//Render Everything
		bg.render(255);
		label->render((GAME_WIDTH / 2), 80);
		scoreLabel->render((GAME_WIDTH / 2), 200);
		highScoreLabel->render((GAME_WIDTH / 2), 300);

		closebutton->render("closebutton");
		restart->render("restart");
		SDL_RenderPresent(LWindow::getInstance()->getRenderer());

	}
}

void GameOverScene::cleanup(){
	label->cleanup();
	scoreLabel->cleanup();
	highScoreLabel->cleanup();

	closebutton->cleanup();
	restart->cleanup();
	bg.cleanup();
}
