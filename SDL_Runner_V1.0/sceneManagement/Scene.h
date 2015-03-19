#ifndef _SCENE_H_
#define _SCENE_H_
#include <iostream>

enum  SceneState{RUNNING, PAUSED, DESTROY};

class Scene{
public:
	Scene(); //constructor
	~Scene(); //deconstructor

	
	virtual void init();
	virtual void run();
	virtual void cleanup();
	virtual void setSceneState(SceneState state) { thisSceneState = state; };
	virtual SceneState getSceneState(){ return thisSceneState; };
	
protected:
	bool initCompleted;
	SceneState thisSceneState; 
};




#endif