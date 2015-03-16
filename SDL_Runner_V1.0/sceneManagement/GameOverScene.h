#ifndef _GAME_OVER_SCENE_H
#define _GAME_OVER_SCENE_H

#include "Scene.h"

class GameOverScene : public  Scene
{
public:
	GameOverScene(){ init(); }
	virtual void init();
	virtual void run();
	~GameOverScene(){}
private:

};

#endif//_GAME_OVER_SCENE_H