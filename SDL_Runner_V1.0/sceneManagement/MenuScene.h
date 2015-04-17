#ifndef _MENU_SCENE_H
#define _MENU_SCENE_H
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: MenuScene.h
-

-
*/
#include "Scene.h"
#include "../gameStructure/Layer.h"
#include "../gameStructure/Button.h"
#include "../gameStructure/Label.h"

class MenuScene : public  Scene{
public:
	MenuScene(){init();}
	~MenuScene(){ cleanup(); }

	virtual void init();		//init
	virtual void run();			//run scene
	virtual void cleanup();		//cleaup scene

private:
	//Scene Elements
	Layer bg;
	Button* player1btn;
	Button* player2btn;
	Button* closeButton;
	Label* label;
};



#endif