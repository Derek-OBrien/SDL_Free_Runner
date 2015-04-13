#ifndef _SCENE_H_
#define _SCENE_H_
#include <iostream>

//Base Scene Class

typedef enum  SceneState{RUNNING, PAUSED, DESTROY};
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