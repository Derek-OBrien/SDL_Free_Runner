/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: ScrollingBackground.cpp
-

-
*/
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
void ScrollingBackground::render(std::string name, int scrollSpeed){
	if (name == "gameBg"){
		bg->scrollingRender(255, name, scrollSpeed);
	}
	else if (name == "cityBg"){
		bg->scrollingRender(255, name, scrollSpeed);
	}
	else{
		bg->scrollingRender(90, name, scrollSpeed);
	}

}

//Update
void ScrollingBackground::update(){}

//Clean Up Method
void ScrollingBackground::cleanup(){
	bg->cleanup();
}