#include "Scene.h"

//Scene Init
void Scene::init(){
	thisSceneState = PAUSED;
	initCompleted = true;
}

void Scene::run()
{
	if(!initCompleted){
		init();
	}
	thisSceneState = RUNNING;
	while(thisSceneState == RUNNING){
		std::cout << "Update world" << std::endl;
		std::cout << "Checking Collisions" << std::endl;
		std::cout << "Handle Input" << std::endl;
	}
}

void Scene::cleanup(){
	std::cout << "Destroying Assets" << std::endl;
}
