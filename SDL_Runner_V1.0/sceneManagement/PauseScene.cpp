#include "PauseScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "../dao/AssetsDao.h"
#include "../gameStructure/LWindow.h"

void PauseScene::init(){
	Scene::init();

	Path path = AssetsDAO::getInstance()->read("sceneBg");
	bg.create(path.getText());

	label = new Label();
}

void PauseScene::run()
{
	if (!initCompleted)
	{
		init();
	}
	thisSceneState = RUNNING;

	std::cout << "Pause Scene Running!" << std::endl;
	label->create("-[Pause]-", 50, { 0, 0, 0 });
	while(thisSceneState == RUNNING){
		
		SDL_Event e;	//Event handler


		//Handle events on queue
		while (SDL_PollEvent(&e) != 0){
			if (e.type == SDL_KEYDOWN){
				if (e.key.keysym.sym == SDLK_SPACE){
					//Destroy Scene and load Game Scene
					thisSceneState = DESTROY;
					bg.cleanup();
					label->cleanup();
				}
			}
		}

		bg.render(255);

		label->render(500,500);
		SDL_RenderPresent(LWindow::getInstance()->getRenderer());

	}

	GameScene* nextScene = new GameScene();
	SceneManager::getInstance()->runwithscene(nextScene);
}