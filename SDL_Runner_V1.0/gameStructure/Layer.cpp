
#include "Layer.h"
#include "LWindow.h"

bool Layer::init(){

	if (!GameObject::init()){
		GameObject::init();
	}

	background = new GameObject();

	return true;
}

void Layer::create(std::string name){

	loadMedia(name);
}

bool Layer::loadMedia(std::string path){

	bool success = true;

	//Load press texture
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

void Layer::render(){
	SDL_SetRenderDrawColor(LWindow::getInstance()->getRenderer(), 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(LWindow::getInstance()->getRenderer());

	bg_Texture.render(0, 0);

}


void Layer::cleanup(){
	bg_Texture.cleanup();
}