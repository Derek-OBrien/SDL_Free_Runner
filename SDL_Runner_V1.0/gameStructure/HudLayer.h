#ifndef _HUDLAYER_H_
#define _HUDLAYER_H_

#include "Layer.h"
#include "Button.h"
#include "Label.h"

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

	Label* getScore(){ return scoreLabel; };

private:
	Button* pauseButton;
	Button* closeButton;

	Label* scoreLabel;
	SDL_Color textColor;
	std::string scoreText;

	
};

#endif//_HUDLAYER_H_