#ifndef _GAME_OVER_SCENE_H
#define _GAME_OVER_SCENE_H

#include "Scene.h"
#include "../gameStructure/layer.h"
#include "../gameStructure/Label.h"
#include "../gameStructure/Button.h"

class GameOverScene : public  Scene
{
public:
	GameOverScene(){ init(); }
	virtual void init();
	virtual void run();
	virtual void cleanup();
	~GameOverScene(){ cleanup(); }
private:
	Layer bg;
	Label* label;
	Button* closebutton;
	Button* restart;
};

#endif//_GAME_OVER_SCENE_H