/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Label.cpp
-

-
*/
#include "Label.h"
#include "../dao/AssetsDao.h"

//Global Font
TTF_Font* myFont = NULL;

//Label Init 
bool Label::init(){
	if (!GameObject::init()){
		GameObject::init();
	}
	//Checkif TTf Was init
	if (!TTF_WasInit()){
		TTF_Init();
	}
	temp = new LTexture();

	//Get font from xml file
	Path fontPath = AssetsDAO::getInstance()->read("font", "path", "assets");
	myFont = TTF_OpenFont(fontPath.getText().c_str(), 50);
	return true;
}

//Create Label
void Label::create(std::string displayText, int size, SDL_Color color){
	if (!init()){
		init();
	}
	textTexture = new LTexture();
	textTexture = loadTTFMedia(displayText, size, color);
}

//Render Label
void Label::render(int x, int y){
	textTexture->render(x - textTexture->getWidth()/2, y);
}

//Load Label Font
LTexture* Label::loadTTFMedia(std::string displayText, int size, SDL_Color color){


	if (myFont == NULL){
		std::cout << "Failed to load font : baveuse3 " << "\nTTF_Error :" << TTF_GetError() << std::endl;
	}
	else{
		//Create Texture from Text
		if (!temp->loadFromRenderedText(displayText, color, myFont)){
			std::cout << "Unable to render Text " << std::endl;
		}
	}
	textTexture = temp;
	return textTexture;
}



//Clean Up Label
void Label::cleanup(){
	textTexture->cleanup();
}
