
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
	path = AssetsDAO::getInstance()->read(name);
	bg->loadMedia(path.getText());
}

//Render Background
void ScrollingBackground::render(std::string name){
	if (name == "gameBg"){
		bg->scrollingRender(255);
	}
	else{
		bg->scrollingRender(127);
	}
}

//Update
void ScrollingBackground::update(){

}

//Clean Up Method
void ScrollingBackground::cleanup(){
	bg->cleanup();
}