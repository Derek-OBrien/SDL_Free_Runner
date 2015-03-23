#include "GameOverScene.h"
#include "SceneManager.h"
#include "../dao/AssetsDao.h"

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

	while(thisSceneState == RUNNING){
		bg.render();
	}
}