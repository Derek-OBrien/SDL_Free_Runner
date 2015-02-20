/*
-		Derek O Brien K00105572
-		Gamobject cpp file

-		Base class for all game objects
-		Has an enum type for the type of game object it is (enemy, player, object)
*/

#include "GameObject.h"	//Include GameObject header


//Game Object init()
bool GameObject::init(){
	eTypeOfObject = OT_OBJECT;	//Sets type to default object

	return true;
}

//Clean Up method
void GameObject::cleanup(){
	delete this;
}

//Set up Object Bounding box
void GameObject::setObjectBoundingBox(SDL_Rect rect, int height, int width){
	rect.h = height;		//set height of bounding box
	rect.w = width;			//set width of bounding box
	rect.x = getPositionX();	//set X position of bounding box
	rect.y = getPositionY();	//set Y position of bounding box

	objectBoundingBox = rect;
}