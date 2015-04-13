#ifndef _GAME_OVER_SCENE_H
#define _GAME_OVER_SCENE_H

#include "Scene.h"
//#include "../gameStructure/layer.h"
//#include "../gameStructure/Label.h"
//#include "../gameStructure/Button.h"
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