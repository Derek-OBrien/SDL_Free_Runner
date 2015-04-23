/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: CollisionManager.cpp
-

-
*/

#include "CollisionManager.h"//include collisionManager header file

//Singleton
CollisionManager *collisionManagerInstance = 0;
CollisionManager *CollisionManager::getInstance(){
	if (collisionManagerInstance == 0){						//if nulll
		collisionManagerInstance = new CollisionManager();	//create instance
	}														//otherwise
	return collisionManagerInstance;						//return instance
}

//Check for collision between player and object 
//first check state of player
bool CollisionManager::checkCollision( SDL_Rect* a, SDL_Rect* b){
	
	//Check if bounding box's intersect
	if (SDL_HasIntersection(a, b) == SDL_TRUE){
		isCollide = true;
	}
	else{
		isCollide = false;
	}
	
	return isCollide;
}



