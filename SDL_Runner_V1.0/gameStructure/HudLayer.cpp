
#include "HudLayer.h"


//Hud Layer init
bool HudLayer::init(){

	if (!Layer::init()){
		Layer::init();
	}
	
	pauseButton = new Button();
	closeButton = new Button();
	scoreLabel = new Label();
	return true;
}

//Create Layer
void HudLayer::create(std::string name){

	if (!init()){
		init();
	}
	pauseButton->create("pausebutton");
	closeButton->create("closebutton");

	textColor = { 255, 0, 0, 255 };
	scoreText = "0";
	scoreLabel->create(scoreText.c_str(), 50, textColor);
}

//Render Layer
void HudLayer::render(){
	scoreLabel->render((GAME_WIDTH / 2), 10);
	pauseButton->render("pausebutton");	//Render Pause Button
	closeButton->render("closebutton");
}

//Handle Layer Input
void HudLayer::handleInput(SDL_Event &e){
	pauseButton->handleMouseEvent(&e);
	closeButton->handleMouseEvent(&e);
}

//update
void HudLayer::update(){
	//update Score + coin count
	scoreLabel->updateScore(scoreText, 50, textColor);
}

//Clean Up
void HudLayer::cleanup(){
	pauseButton->cleanup();
	closeButton->cleanup();
	scoreLabel->cleanup();
}