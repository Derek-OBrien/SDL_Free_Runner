
#include "gameStructure\GameManager.h"



int main(int argc, char* args[]){
	GameManager* gManager = new GameManager();
	
	//Start up SDL and create window
	while (!SDL_QUIT){
		if (!gManager->init()){
			std::cout << "Failed to initialize Game Manager!!! :(\n" << std::endl;
		}
	}
	return 0;
}