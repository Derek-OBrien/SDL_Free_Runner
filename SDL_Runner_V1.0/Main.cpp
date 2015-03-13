
#include "gameStructure\GameManager.h"



int main(int argc, char* args[]){
	
	//Start up SDL and create window
	GameManager::getInstance()->init(
		"SDL Free Runner",								//Name
		SDL_WINDOWPOS_UNDEFINED,						//Position
		SDL_WINDOWPOS_UNDEFINED,						//Position
		GameManager::getInstance()->getGameHeight(),	//Height
		GameManager::getInstance()->getGameWidth(),		//Width
		SDL_WINDOW_SHOWN);								//Flag


	return 0;
}