/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Layer.cpp
-

-
*/
#include "Layer.h"
#include "LWindow.h"

//Layer Init
bool Layer::init(){
	//Super init
	if (!GameObject::init()){
		GameObject::init();
	}

	layer = new GameObject();
	layer->setObjectType(OT_LAYER);


	return true;
}

//Create Layer
void Layer::create(std::string name){
	//check if layer has init
	if (!init()){
		init();
	}


	//load layer media
	loadMedia(name);
}

//Load Layer Media
bool Layer::loadMedia(std::string path){

	bool success = true;
	//Load texture
	if (!bg_Texture.loadFromFile(path)){
		printf("BG: Failed to load Bg texture!\n");
		success = false;
	}
	else{
		printf("BG: Texture Loaded\n");
		success = true;
	}

	return success;
}

//Render Layer
void Layer::render(int alpha){
	//set alpha transperency of layer
	bg_Texture.setAlpha(alpha);
	bg_Texture.render(0, 0);
}

//Render Scrolling Layer
void Layer::scrollingRender(int alpha, std::string name, int scrollSpeed){

	//Set up scrolling speed
	scrollingOffset -= scrollSpeed;
	--scrollingOffset;

	//Move city image( very rear image slight bit faster)
	if (name == "cityBg"){
		scrollingOffset -= 5;
	}
	
	//Reset image
	if (scrollingOffset < -bg_Texture.getWidth()){
		scrollingOffset = 0;
	}

	//Render Textures
	bg_Texture.setAlpha(alpha);
	bg_Texture.render(scrollingOffset, 0);
	bg_Texture.render(scrollingOffset + bg_Texture.getWidth(), 0);
}


//Cleanup 
void Layer::cleanup(){
	bg_Texture.cleanup();
}