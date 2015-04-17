/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly	
-		@file		: GameObject.cpp
-		

-		Base class for all game objects(Sprite, Character, Button etc)
*/


//Include GameObject header
#include "GameObject.h"


//Game Object init(), initilize base game object
bool GameObject::init(){
	initCompleted = true;
	eTypeOfObject = OT_OBJECT;	//Sets type to default object

	return true;
}


//Set up game object Bounding box
//params: x = x position, y = y position, h = height, w = width 
void GameObject::setObjectBoundingBox(int x, int y, int h, int w){

	objectBoundingBox.h = h;		//set height of bounding box
	objectBoundingBox.w = w;			//set width of bounding box
	objectBoundingBox.x = x;	//set X position of bounding box
	objectBoundingBox.y = y;	//set Y position of bounding box

}


//Clean Up method
void GameObject::cleanup(){
	//delete this;
}