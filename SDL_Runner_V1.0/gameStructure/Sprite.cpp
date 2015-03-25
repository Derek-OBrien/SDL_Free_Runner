
#include "Sprite.h"
#include "../dao/AssetsDao.h"
#include "LWindow.h"

//Sprite init
bool Sprite::init(){
	//Call Super init
	if (!GameObject::init()){
		GameObject::init();
	}

	return true;
}

//Load Sprite Image
bool Sprite::loadMedia(std::string name){
	bool success = true;

	imageDetails = AssetsDAO::getInstance()->readImageDetails(name);
	std::string imagepath = imageDetails.pathToFile;

	//Load texture
	if (!spriteTexture.loadFromFile(imagepath)){
		std::cout << "S: Failed to load sprite sheet for : " << name << std::endl;
		success = false;
	}
	else{
		std::cout << "S: Sprite Sheet Loaded for : " << name << std::endl;

		int temp, offsetX, size;
		offsetX = 0;
		size = imageDetails.frames;
		temp = imageDetails.offsetX;

		for (int i = 0; i < size; i++){

			gSpriteClips[i].x = offsetX;
			gSpriteClips[i].y = imageDetails.offsetY;
			gSpriteClips[i].w = imageDetails.spriteWidth;
			gSpriteClips[i].h = imageDetails.spriteHeight;

			offsetX += temp;
		}

		setObjectBoundingBox(imageDetails.posX, imageDetails.posY, imageDetails.spriteHeight, imageDetails.spriteWidth);
	}

	return success;
}

//Run animation 
void Sprite::runAnimation(int posX, int posY){
	currentFrame = &gSpriteClips[frame / 5];
	spriteTexture.render(posX,posY, currentFrame);

	++frame;
	//Cycle animation
	if (frame / 5 >= imageDetails.frames){
		frame = 0;
	}
}


//Render Sprite
void Sprite::render(int posX, int posY){	
	runAnimation( posX,  posY);

	//Render Bounding Box
	SDL_SetRenderDrawColor(LWindow::getInstance()->getRenderer(), 0xff, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(LWindow::getInstance()->getRenderer(), getObjectBoundingBox());
}


int Sprite::getPosX(){
	//set/get position via gameObject setpositon
	setPositionX(imageDetails.posX);
	return getPositionX();
}

int Sprite::getPosY(){
	//set/get position via gameObject setpositon
	setPositionY(imageDetails.posY);
	return getPositionY();
}

//Sprite cleanup
void Sprite::cleanup(){
//	spriteTexture.cleanup();
}

