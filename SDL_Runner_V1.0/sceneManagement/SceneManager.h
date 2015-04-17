#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Scene.h
-

-
*/

#include "Scene.h"

//Sceen Manager Class manages which scene is called
class SceneManager{
public:

	static SceneManager* getInstance(); 	//get instance
	void init();	//init
	void cleanup();	//Cleanup
	void runwithscene(Scene* Scene); 	//runwithscene


	//get current running scene
	Scene* getCurrentScene(){ return currentRunningScene; };

private:
	SceneManager(){ init(); };
	~SceneManager(){ cleanup(); };
	Scene* currentRunningScene;
};



#endif//_SCENE_MANAGER_H_