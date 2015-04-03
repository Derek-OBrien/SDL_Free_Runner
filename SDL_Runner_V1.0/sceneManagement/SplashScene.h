#ifndef _SPLASH_SCENE_H
#define _SPLASH_SCENE_H

#include "Scene.h"
#include "../gameStructure/Layer.h"
#include "../gameStructure/Label.h"

class SplashScene : public  Scene{
public:
	SplashScene(){ init(); }
	~SplashScene(){ cleanup(); }

	virtual void init();
	virtual void run();
	virtual void cleanup();

private:
	Layer bg;
	Label* label;

};

#endif//_SPLASH_SCENE_H