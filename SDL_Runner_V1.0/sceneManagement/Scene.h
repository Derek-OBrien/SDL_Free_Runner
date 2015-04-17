#ifndef _SCENE_H_
#define _SCENE_H_

/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Scene.h
-

-
*/
#include <iostream>
#include "../gameStructure/GameDefines.h"
//Base Scene Class

//typedef enum  SceneState{RUNNING, PAUSED, DESTROY};
class Scene{
public:
	Scene(){ init(); }; //constructor
	~Scene(){ cleanup(); }; //deconstructor

	
	virtual void init();	//init
	virtual void run();		//run with scene
	virtual void cleanup();	//cleanup

	virtual void setSceneState(SceneState state) { thisSceneState = state; };
	virtual SceneState getSceneState(){ return thisSceneState; };
	
protected:
	bool initCompleted;
	SceneState thisSceneState; 
};




#endif