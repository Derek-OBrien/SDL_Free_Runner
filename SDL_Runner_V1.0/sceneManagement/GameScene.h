#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: GameScene.h
-

-
*/
#include "Scene.h"

class GameScene : public  Scene{
public:
	GameScene(){init();}
	virtual void init();
	virtual void run();

	virtual void setSceneState(SceneState state){ thisSceneState = state; };
	virtual SceneState getSceneState() { return thisSceneState; };
	
	~GameScene(){}
private:

};

#endif//_GAME_SCENE_H_