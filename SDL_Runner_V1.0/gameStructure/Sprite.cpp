
#include "Sprite.h"

//Sprite init
bool Sprite::init(){
	return true;
}


//Sprite cleanup
void Sprite::cleanup(){
	delete this;
}

bool Sprite::loadMedia(LTexture texture ){
	//Loading success flag
	bool success = true;
	std::string path;		//path to file
	SDL_Renderer * gRenderer = NULL;

	//Load sprite sheet texture
	if (!texture.loadFromFile(path, gRenderer)){
		printf("Failed to load sprite sheet texture!\n");
		success = false;
	}
	else{
		//Set Sprite position
	}

	return success;
}
