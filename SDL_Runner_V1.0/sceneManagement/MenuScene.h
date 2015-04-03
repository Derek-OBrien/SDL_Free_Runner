#ifndef _MENU_SCENE_H
#define _MENU_SCENE_H

#include "Scene.h"
#include "../gameStructure/Layer.h"
#include "../gameStructure/Button.h"
#include "../gameStructure/Label.h"

class MenuScene : public  Scene{
public:
	MenuScene(){init();}
	~MenuScene(){ cleanup(); }

	virtual void init();
	virtual void run();
	virtual void cleanup();

private:

	Layer bg;
	Button* player1btn;
	Button* player2btn;
	Button* closeButton;
	Label* label;
};



#endif