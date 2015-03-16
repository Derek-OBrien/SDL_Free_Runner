
#include "Background.h"
#include "LWindow.h"

bool BackGround::init(){


	return true;
}


bool BackGround::loadMedia(std::string path){

	bool success = true;
	std::string pathToFile = path;
	//Load press texture
	if (!bg_Texture.loadFromFile(pathToFile)){
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
	SDL_SetRenderDrawColor(LWindow::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(LWindow::getInstance()->getRenderer());

	bg_Texture.render(0, 0);
	SDL_RenderPresent(LWindow::getInstance()->getRenderer());

}


void BackGround::cleanup(){
	bg_Texture.cleanup();
}