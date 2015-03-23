#include "PauseScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "../dao/AssetsDao.h"

void PauseScene::init(){
	Scene::init();

	Path path = AssetsDAO::getInstance()->read("pause");
	std::string imagePath = path.getText();
	bg.loadMedia(imagePath);

}

void PauseScene::run()
{
	if (!initCompleted)
	{
		init();
	}
	thisSceneState = RUNNING;

	std::cout << "Pause Scene Running!" << std::endl;

	while(thisSceneState == RUNNING){
		
		SDL_Event e;	//Event handler


		//Handle events on queue
		while (SDL_PollEvent(&e) != 0){
			if (e.type == SDL_KEYDOWN){
				if (e.key.keysym.sym == SDLK_SPACE){
					//Destroy Scene and load Game Scene
					thisSceneState = DESTROY;
					bg.cleanup();
				}
			}
		}

		bg.render();
	}

	GameScene* nextScene = new GameScene();
	SceneManager::getInstance()->runwithscene(nextScene);
}