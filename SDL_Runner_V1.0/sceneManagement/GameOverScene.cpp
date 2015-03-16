#include "GameOverScene.h"
#include "SceneManager.h"

void GameOverScene::init()
{
	Scene::init();
}

void GameOverScene::run()
{
	if(!initCompleted)
	{
		init();
	}
	thisSceneState = RUNNING;

	int lifetimeofscene = 2000;

	while(thisSceneState == RUNNING)
	{
		std::cout << "Game Over Scene Running!" << std::endl;
		lifetimeofscene--;
		if(lifetimeofscene <1)
			thisSceneState = DESTROY;
	}
	//Scene* nextScene = new Scene();
	//SceneManager::getInstance()->runwithscene(nextScene);
}