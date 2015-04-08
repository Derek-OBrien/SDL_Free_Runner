/*
-		Derek O Brien K00105572
-		Collision manager cpp file

		CollisionManager
-       Singleton
-       registerWithCollisionManager (collision manager will take GameObject’s)
-       registerPlayer (takes in a player object)
-       checkCollisions (this will check player against any all types of objects)
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
	
	
	if (SDL_HasIntersection(a, b) == true){
		isCollide = true;
	}
	else{
		isCollide = false;
	}
	
	

	return isCollide;
}



