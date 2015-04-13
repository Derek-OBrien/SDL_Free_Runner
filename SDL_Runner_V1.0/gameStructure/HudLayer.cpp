
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

	coinText = "0";
	coinLabel->create(coinText.c_str(), 50, RED);
}

//Render Layer
void HudLayer::render(){
	scoreLabel->render((GAME_WIDTH / 2), 10);
	coinLabel->render(100, 10);
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
	display.str("");
	display << score;
	textTexture = scoreLabel->loadTTFMedia(display.str().c_str(), 50, RED);
}

//Update Hudlayer
void HudLayer::update(){
	updateScore();
}

//update coin count
void HudLayer::updateCoinCount(){
	coinCount += 1;
	display.str("");
	display << coinCount;
	textTexture = coinLabel->loadTTFMedia(display.str().c_str(), 50, RED);
}

//Get Score
std::string HudLayer::getScore(){ 
	return display.str(); 
};

//Get HighScore from xml
std::string HudLayer::getHighScore(){
	//read current high score
	highScore = dao->getInstance()->read("highScore", "highScore", "score").getText();
	return highScore;
}

//Check if current score = high score
bool HudLayer::checkIfHighScore(){
	int high, current;
	std::string temp1 = getHighScore();	//get high score text
	std::string temp2 = getScore();		//get score text
	bool check = false;	

	//Convert Strings to Integers
	high = std::stoi(temp1);
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