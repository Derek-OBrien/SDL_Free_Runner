#ifndef _PAUSE_SCENE_H
#define _PAUSE_SCENE_H

#include "Scene.h"
#include "../gameStructure/Background.h"

class PauseScene : public  Scene{

public:
	PauseScene(){init();}
	virtual void init();
	virtual void run();
	~PauseScene(){}
private:
	
	BackGround bg;
};
#endif//_PAUSE_SCENE_H