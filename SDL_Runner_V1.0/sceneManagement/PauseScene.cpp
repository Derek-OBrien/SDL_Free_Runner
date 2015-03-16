#include "PauseScene.h"
#include "SceneManager.h"

void PauseScene::init(){
	Scene::init();

	bg.loadMedia("../SDL_Runner_V1.0/assets/backgrounds/pause.png");
}

void PauseScene::run()
{
	if(!initCompleted)
	{
		init();
	}
	thisSceneState = RUNNING;

	int lifetimeofscene = 2000;

	while(thisSceneState == RUNNING){
		std::cout << "Pause Scene Running!" << std::endl;
		

		bg.render();
	}

	Scene* nextScene = new Scene();
	SceneManager::getInstance()->runwithscene(nextScene);
}