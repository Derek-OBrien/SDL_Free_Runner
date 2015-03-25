
#include "HudLayer.h"

//Hud Layer init
bool HudLayer::init(){

	if (!Layer::init()){
		Layer::init();
	}
	
	hud = new Layer();
	pauseButton = new Button();
	closeButton = new Button();
	return true;
}

//Create Layer
void HudLayer::create(std::string name){

	if (!init()){
		init();
	}
	Path path = AssetsDAO::getInstance()->read(name);
	hud->loadMedia(path.getText());
	pauseButton->create("pausebutton");
	closeButton->create("closebutton");
}

//Render Layer
void HudLayer::render(){
	hud->render(255);
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
}

//Clean Up
void HudLayer::cleanup(){
	hud->cleanup();
	pauseButton->cleanup();
	closeButton->cleanup();
}