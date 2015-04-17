#ifndef _HUDLAYER_H_
#define _HUDLAYER_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: HudLayer.h
-

-		
*/
#include "Layer.h"
#include "Button.h"
#include "Label.h"

//HudLayer sub class of Layer
class HudLayer : public Layer{
public:
	HudLayer(){ init(); };		//Constructor	- calls init()
	~HudLayer(){ cleanup(); };  //Deconstructor - calls cleanup

	bool init();	//init
	void create(std::string name);	//create
	void handleInput(SDL_Event &e);	//handle input on layer
	void update();	//update layer
	void render();	//render layer
	void cleanup();	//cleanup layer

	std::string getScore();		//get game score
	std::string getHighScore();	//get high score
	bool checkIfHighScore();	//checkif current score = high score

	void saveScore();		//save current score
	void saveHighScore();	//save high score
	void updateScore();		//update score label
	void updateCoinCount();	//update coin coint label
	
private:
	AssetsDAO* dao;		//Dao for accesin xml details

	Button* pauseButton;	//pause button
	Button* closeButton;	//close button

	Label* scoreLabel;		//score label
	std::string scoreText;	//score label text

	LTexture* textTexture;	//text texture
	int score;					//score
	std::stringstream scoreDisplay;	//display label
	std::string highScore;	//high score text
	
	Label* coinLabel;		//coin label
	std::string coinText;	//coin label text
	int coinCount;			//coin count
	std::stringstream countDisplay;	//display label

};

#endif//_HUDLAYER_H_