#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_
#include "Scene.h"

//Sceen Manager Class manages which scene is called
class SceneManager{
public:
	//get instance
	static SceneManager* getInstance();
	void init();
	void cleanup();
	//runwithscene
	void runwithscene(Scene* Scene);

	//get current running scene
	Scene* getCurrentScene(){ return currentRunningScene; };

private:
	SceneManager(){ init(); };
	~SceneManager(){ cleanup(); };
	Scene* currentRunningScene;
};



#endif//_SCENE_MANAGER_H_