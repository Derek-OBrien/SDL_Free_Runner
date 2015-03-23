#ifndef _MENU_SCENE_H
#define _MENU_SCENE_H

#include "Scene.h"
#include "../gameStructure/Background.h"
#include "../gameStructure/Button.h"

class MenuScene : public  Scene{
public:
	MenuScene(){init();}
	~MenuScene(){ cleanup(); }

	virtual void init();
	virtual void run();
	virtual void cleanup();

private:

	BackGround bg;
	Button* playbutton;
	Button* closebutton;
};



#endif