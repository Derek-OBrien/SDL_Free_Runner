/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: HudLayer.cpp
-

-
*/
#include "HudLayer.h"


//Hud Layer init
bool HudLayer::init(){
	//super init
	if (!Layer::init()){
		Layer::init();
	}
	
	//create everything
	dao = new AssetsDAO();

	pauseButton = new Button();
	closeButton = new Button();
	scoreLabel = new Label();
	coinLabel = new Label();

	textTexture = new LTexture();
	return true;
}

//Create Hud Layer
void HudLayer::create(std::string name){

	//init
	if (!init()){
		init();
	}

	//Create buttons
	pauseButton->create("pausebutton");
	closeButton->create("closebutton");

	//set defaults
	scoreText = "0";
	scoreLabel->create(scoreText.c_str(), 50, RED);

	coinText = "Coins";
	coinLabel->create(coinText.c_str(), 50, RED);
}

//Render Layer
void HudLayer::render(){
	scoreLabel->render((GAME_WIDTH / 2), 20);
	coinLabel->render(150, 20);
	pauseButton->render("pausebutton");	//Render Pause Button
	closeButton->render("closebutton");
}

//Handle Layer Input
void HudLayer::handleInput(SDL_Event &e){
	pauseButton->handleMouseEvent(&e);
	closeButton->handleMouseEvent(&e);
}

//update score 
void HudLayer::updateScore(){
	score += 1;
	scoreDisplay.str("");
	scoreDisplay << score;
	textTexture = scoreLabel->loadTTFMedia(scoreDisplay.str().c_str(), 50, RED);
}

//Update Hudlayer
void HudLayer::update(){
	updateScore();
}

//update coin count
void HudLayer::updateCoinCount(){
	coinCount += 1;
	countDisplay.str("");
	countDisplay << coinCount;
	textTexture = coinLabel->loadTTFMedia(countDisplay.str().c_str(), 50, RED);
}

//Get Score
std::string HudLayer::getScore(){ 
	return scoreDisplay.str();
};

//Get HighScore from xml
int HudLayer::getHighScore(){
	//read current high score
	highScore = dao->getInstance()->readInt("highScore", "highScore", "score");
	return highScore;
}

//Check if current score = high score
bool HudLayer::checkIfHighScore(){
	int high, current;
	std::string temp2 = getScore();		//get score text
	bool check = false;	

	//Convert Strings to Integers
	high = getHighScore();
	current = std::stoi(temp2);

	//If new high score save current as high score
	if (high < current){
		check = true;
		saveHighScore();
	}
	return check;
}


//Save Score
void HudLayer::saveScore(){
	dao->getInstance()->update(getScore(), "currentScore", "score");
}
//Save High Score
void HudLayer::saveHighScore(){
	dao->getInstance()->update(getScore(), "highScore", "score");
}

//Clean Up
void HudLayer::cleanup(){
	pauseButton->cleanup();
	closeButton->cleanup();
	scoreLabel->cleanup();
	coinLabel->cleanup();
	textTexture->cleanup();
}