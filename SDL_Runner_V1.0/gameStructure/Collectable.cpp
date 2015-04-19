/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Collectable.cpp
-

-		
*/

#include "Collectable.h"


//Collectable init
bool Collectable::init(){

	if (!Sprite::init()){
		Sprite::init();
	}


	return true;
}

/*
	Create Collectable Sprite
*/
void Collectable::create(std::string name, int posX, int posY){

	//Check if collectable was init
	if (!init()){
		init();
	}

	//Create Collectable
	collectable = new Collectable();
	collectableBB = new SDL_Rect();
	collectable->setObjectType(OT_COLLECTABLE);

	//Read in and load image from xml file
	collectable->setName(name);
	collectable->loadMedia(collectable->getName());
	
	//Set initial position
	collPosX = posX;//collectableDetails.posX + posX;
	collPosY = posY;//collectableDetails.posY + posY;

	//Set Object bounding Box
	collectable->setObjectBoundingBox(collPosX, collPosY, collectable->getObjectBoundingBox()->h, collectable->getObjectBoundingBox()->w);
	collectableBB = collectable->getObjectBoundingBox();
}

//Render Collectable Object
void Collectable::render(){
	collectable->render(collPosX, collPosY);
}

//Update Collectable position
void Collectable::update(int vel){

	collPosX -= vel ;
	collectable->setPositionX(collPosX);
	collectable->getObjectBoundingBox()->x = collPosX;

	//if it goes off screen celanup
	if (collPosX < 0){
		resetPosition();
	}
}

//Reset collectable position
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
