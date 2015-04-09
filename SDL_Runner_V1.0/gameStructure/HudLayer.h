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

	std::string getScore();
	std::string getHighScore();
	bool checkIfHighScore();

	void saveScore();
	void saveHighScore();

	
private:
	AssetsDAO* dao;

	Button* pauseButton;
	Button* closeButton;

	Label* scoreLabel;
	std::string scoreText;

	LTexture* textTexture;
	int score;
	std::stringstream display;
	std::string highScore;
	
};

#endif//_HUDLAYER_H_