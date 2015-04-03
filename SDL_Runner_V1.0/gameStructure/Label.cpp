
#include "Label.h"
#include "../dao/AssetsDao.h"
TTF_Font* myFont = NULL;

//Label Init 
bool Label::init(){
	if (!GameObject::init()){
		GameObject::init();
	}
	return true;
}

//Create Label
void Label::create(std::string displayText, int size, SDL_Color color){
	textTexture = new LTexture();
	textTexture = loadTTFMedia(displayText, size, color);
}

//Render Label
void Label::render(int x, int y){
	textTexture->render(x - textTexture->getWidth()/2, y);
}

//Load Label Font
LTexture* Label::loadTTFMedia(std::string displayText, int size, SDL_Color color){
	bool success = true;

	LTexture* temp = new LTexture();
	//load font via dao
	Path fontPath = AssetsDAO::getInstance()->read("font");
	myFont = TTF_OpenFont(fontPath.getText().c_str(), size);

	if (myFont == NULL){
		std::cout << "Failed to load font : baveuse3 " << "\nTTF_Error :" << TTF_GetError() << std::endl;
		success = false;
	}
	else{
		//Create Texture from Text
		if (!temp->loadFromRenderedText(displayText, color, myFont)){
			std::cout << "Unable to render Text " << std::endl;
			success = false;
		}
	}
	textTexture = temp;
	return textTexture;
}


//Update Score Count
void Label::updateScore(std::string displayText, int size, SDL_Color color){
	score += 1;
	display.str("");
	display << score;
	textTexture = loadTTFMedia(display.str().c_str(), size, color);

}


//Clean Up Label
void Label::cleanup(){
	textTexture->cleanup();
	display << NULL;
	score = NULL;
//	TTF_CloseFont(myFont);	
}
