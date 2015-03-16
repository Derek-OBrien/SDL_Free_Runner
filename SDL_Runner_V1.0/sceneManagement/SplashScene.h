#ifndef _SPLASH_SCENE_H
#define _SPLASH_SCENE_H

#include "Scene.h"
#include "../gameStructure/Background.h"

class SplashScene : public  Scene{
public:
	SplashScene(){ init(); }
	~SplashScene(){}

	virtual void init();
	virtual void run();


private:
	BackGround bg;
};

#endif//_SPLASH_SCENE_H