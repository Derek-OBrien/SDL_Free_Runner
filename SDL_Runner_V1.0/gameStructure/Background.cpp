
#include "Background.h"
#include "LWindow.h"

bool BackGround::init(){

	if (!GameObject::init()){
		GameObject::init();
	}

	background = new GameObject();

	return true;
}

void BackGround::create(std::string name){

	loadMedia(name);
}

bool BackGround::loadMedia(std::string path){

	bool success = true;
//	std::string pathToFile = path;

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

void BackGround::render(){
	//SDL_SetRenderDrawColor(LWindow::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	//SDL_RenderClear(LWindow::getInstance()->getRenderer());

	bg_Texture.render(0, 0);
}


void BackGround::cleanup(){
	bg_Texture.cleanup();
}