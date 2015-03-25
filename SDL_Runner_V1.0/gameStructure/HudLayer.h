#ifndef _HUDLAYER_H_
#define _HUDLAYER_H_

#include "Layer.h"
#include "Button.h"

class HudLayer : public Layer{
public:
	HudLayer(){ init(); };
	~HudLayer(){ cleanup(); };

	bool init();
	void create(std::string name);
	void handleInput(SDL_Event &e);
	void update();
	void render();
	void cleanup();


private:
	Layer* hud;
	Button* pauseButton;
	Button* closeButton;

};

#endif//_HUDLAYER_H_