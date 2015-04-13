
#include "ScrollingBackground.h"


//Init menthod
bool ScrollingBackground::init(){

	if (!Layer::init()){
		Layer::init();
	}

	bg = new Layer();
	return true;
}

//Create Background
void ScrollingBackground::create(std::string name){
	if (!init()){
		init();
	}
	path = AssetsDAO::getInstance()->read(name, "path", "assets");
	bg->loadMedia(path.getText());
}

//Render Background
void ScrollingBackground::render(std::string name){
	if (name == "gameBg"){
		bg->scrollingRender(255, name);
	}
	else if (name == "cityBg"){
		bg->scrollingRender(255, name);
	}
	else{
		bg->scrollingRender(127, name);
	}
}

//Update
void ScrollingBackground::update(){}

//Clean Up Method
void ScrollingBackground::cleanup(){
	bg->cleanup();
}