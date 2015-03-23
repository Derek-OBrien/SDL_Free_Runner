/*
-		Derek O Brien K00105572
-		obstical cpp file

-       Sub class of Sprite
-       Has a runAI method to update logic (print statement “running AI for obstical”)
-       Has an update method (print statement “updating obstical”)
*/

#include "Obstical.h"
#include "LWindow.h"

//Obstical init
bool Obstical::init(){

	if (!Sprite::init()){
		Sprite::init();
	}
	obstical = new Sprite();
	obstical->setObjectType(OT_OBSTICAL);
	obstical->setName("blade");
	
	obstical->loadMedia(obstical->getName());

	obsticalPosX = obstical->getPosX();
	obsticalPosY = obstical->getPosY();
	obsticalBoundingBox = new SDL_Rect();
	obsticalBoundingBox = obstical->getObjectBoundingBox();
	return true;
}


//Render Obstical
void Obstical::render(){

	obstical->render(obsticalPosX, obsticalPosY);
}


//Obstical update: updates obstical postion
void Obstical::update(){

	obsticalPosX -= FORCE_X;
	obstical->setPositionX(obsticalPosX);
	obstical->getObjectBoundingBox()->x = obsticalPosX;

	//if it goes off screen reset to orignal position
	if (obsticalPosX < -GAME_WIDTH){
		obsticalPosX = GAME_WIDTH;
		obstical->setPositionX(obsticalPosX);
		obstical->getObjectBoundingBox()->x = obsticalPosX;
	}
}


//Obstical cleanup
void Obstical::cleanup(){
	obstical->cleanup();
}