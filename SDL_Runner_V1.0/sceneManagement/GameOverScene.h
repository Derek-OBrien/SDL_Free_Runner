#ifndef _GAME_OVER_SCENE_H
#define _GAME_OVER_SCENE_H

/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: GameOverScene.h
-

-
*/
#include "Scene.h"
#include "../gameStructure/HudLayer.h"

class GameOverScene : public  Scene
{
public:
	GameOverScene(){ init(); }	//constructor
	virtual void init();		//init
	virtual void run();			//run scene
	virtual void cleanup();		//cleanup scene
	~GameOverScene(){ cleanup(); }	//deconstructor

private:
	AssetsDAO* dao;
	Layer bg;
	Label* label;
	Label* scoreLabel;
	Label* highScoreLabel;
	Button* closebutton;
	Button* restart;

	std::string currentScore;
	std::string highScore;
};

#endif//_GAME_OVER_SCENE_H