#include "Scene.h"

Scene::Scene(){
	initCompleted = false;
	thisSceneState = PAUSED;
}

void Scene::init(){
	initCompleted = true;
}

void Scene::run()
{
	if(!initCompleted)
	{
		init();
	}
	thisSceneState = RUNNING;
	while(thisSceneState == RUNNING){
		std::cout << "Update world" << std::endl;
		std::cout << "Checking Collisions" << std::endl;
		std::cout << "Handle Input" << std::endl;
	}
}

void Scene::cleanup()
{
	std::cout << "Destroying Assets" << std::endl;
}


Scene::~Scene(){
	cleanup();
	std::cout << "Shutting down Scene" << std::endl;
}