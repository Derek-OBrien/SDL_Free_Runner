
#include "Layer.h"
#include "LWindow.h"

//Layer Init
bool Layer::init(){
	if (!GameObject::init()){
		GameObject::init();
	}
	return true;
}

//Create Layer
void Layer::create(std::string name){
	if (!init()){
		init();
	}
	layer = new GameObject();
	layer->setObjectType(OT_LAYER);

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

	bg_Texture.setAlpha(alpha);
	bg_Texture.render(0, 0);
}

//Render Scrolling Layer
void Layer::scrollingRender(int alpha, std::string name){

	if(name == "cityBg"){
		scrollingOffset -=3;
	}
	--scrollingOffset;
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