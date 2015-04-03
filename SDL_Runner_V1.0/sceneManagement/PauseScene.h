#ifndef _PAUSE_SCENE_H
#define _PAUSE_SCENE_H

#include "Scene.h"
#include "../gameStructure/Layer.h"
#include "../gameStructure/Label.h"

class PauseScene : public  Scene{

public:
	PauseScene(){init();}
	virtual void init();
	virtual void run();
	~PauseScene(){}
private:
	
	Layer bg;
	Label* label;
};
#endif//_PAUSE_SCENE_H