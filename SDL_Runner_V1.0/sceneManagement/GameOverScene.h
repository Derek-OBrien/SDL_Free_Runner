#ifndef _GAME_OVER_SCENE_H
#define _GAME_OVER_SCENE_H

#include "Scene.h"
#include "../gameStructure/layer.h"

class GameOverScene : public  Scene
{
public:
	GameOverScene(){ init(); }
	virtual void init();
	virtual void run();
	~GameOverScene(){}
private:
	Layer bg;
};

#endif//_GAME_OVER_SCENE_H