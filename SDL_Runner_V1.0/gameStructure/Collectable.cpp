/*
-		Derek O Brien K00105572
-		obstical cpp file

-       Sub class of Sprite
-       Has a runAI method to update logic (print statement “running AI for Collectable”)
-       Has an update method (print statement “updating Collectable”)
*/

#include "Collectable.h"


//Collectable init
bool Collectable::init(){

	if (!Sprite::init()){
		Sprite::init();
	}
	return true;
}

void Collectable::create(std::string name, int posX, int posY){

	if (!init()){
		init();
	}

	collectable = new Collectable();
	collectableBB = new SDL_Rect();
	collectable->setObjectType(OT_COLLECTABLE);

	ImageDetails collectableDetails = AssetsDAO::getInstance()->readImageDetails(name);
	collectable->setName(collectableDetails.name);

	collectable->loadMedia(collectable->getName());
	
	collPosX = collectableDetails.posX + posX;
	collPosY = collectableDetails.posY + posY;

	//Set Object bounding Box
	collectable->setObjectBoundingBox(collPosX, collPosY, collectableDetails.spriteHeight, collectableDetails.spriteWidth);

	collectableBB = collectable->getObjectBoundingBox();
}

//Render Collectable Object
void Collectable::render(){
	collectable->render(collPosX, collPosY);
}

void Collectable::update(){

	collPosX -= FORCE_X * 0.8;
	collectable->setPositionX(collPosX);
	collectable->getObjectBoundingBox()->x = collPosX;

	//if it goes off screen celanup
	if (collPosX < 0){
		resetPosition();
	}
}

void Collectable::resetPosition(){
	collPosX = GAME_WIDTH + 100;
	collectable->setPositionX(collPosX);
	collectable->getObjectBoundingBox()->x = collPosX;
}
//Collectable cleanup
void Collectable::cleanup(){
	collectable->~Sprite();
	collectable->setObjectBoundingBox(NULL, NULL, NULL, NULL);
}
