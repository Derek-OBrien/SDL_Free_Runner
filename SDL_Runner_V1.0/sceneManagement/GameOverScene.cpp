#include "GameOverScene.h"
#include "SceneManager.h"
#include "../dao/AssetsDao.h"
#include "../gameStructure/LWindow.h"

void GameOverScene::init(){
	Scene::init();

	Path path = AssetsDAO::getInstance()->read("gameOver");
	bg.loadMedia(path.getText());

}

void GameOverScene::run()
{
	if (!initCompleted)
	{
		init();
	}
	thisSceneState = RUNNING;

	std::cout << "Game Over Scene Running!" << std::endl;
	bool quit = false;
	SDL_Event e;	//Event handler

	while(thisSceneState == RUNNING){

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0){
			//User requests quit
			if (e.type == SDL_QUIT){
				quit = true;
				SDL_Quit();
				LWindow::getInstance()->cleanup();
			}
		}

		bg.render(255);
		SDL_RenderPresent(LWindow::getInstance()->getRenderer());

	}
}