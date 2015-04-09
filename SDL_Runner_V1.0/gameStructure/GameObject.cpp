/*
-		Derek O Brien K00105572
-		Gamobject cpp file

-		Base class for all game objects
-		Has an enum type for the type of game object it is (enemy, player, object)
*/

#include "GameObject.h"	//Include GameObject header


//Game Object init()
bool GameObject::init(){
	initCompleted = true;
	eTypeOfObject = OT_OBJECT;	//Sets type to default object

	return true;
}


//Set up Object Bounding box
void GameObject::setObjectBoundingBox(int x, int y, int height, int width){

	objectBoundingBox.h = height;		//set height of bounding box
	objectBoundingBox.w = width;			//set width of bounding box
	objectBoundingBox.x = x;	//set X position of bounding box
	objectBoundingBox.y = y;	//set Y position of bounding box

	//objectBoundingBox = rect;
}


//Clean Up method
void GameObject::cleanup(){
	//delete this;
}