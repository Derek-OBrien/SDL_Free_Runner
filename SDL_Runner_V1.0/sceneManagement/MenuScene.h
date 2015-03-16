#ifndef _MENU_SCENE_H
#define _MENU_SCENE_H

#include "Scene.h"
#include "../gameStructure/Background.h"
class MenuScene : public  Scene
{
public:
	MenuScene(){init();}
	virtual void init();
	virtual void run();
	~MenuScene(){}
private:

	BackGround bg;

};



#endif