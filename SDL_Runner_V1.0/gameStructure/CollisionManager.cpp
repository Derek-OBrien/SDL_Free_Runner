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

//Register game object with collision manager
void CollisionManager::registerGameObject(GameObject *o){

}

//Register player with collision manager
void CollisionManager::registerPlayer(Player *p){

}


//Check for collision between player and object 
//first check state of player
bool CollisionManager::checkCollision( SDL_Rect* a, SDL_Rect* b){
	
	int leftA, rightA, topA, bottomA;
	int leftB, rightB, topB, bottomB;
	
	//Calculate the sides of rect A
	leftA = a->x;
	rightA = a->x + a->w;
	topA = a->y;
	bottomA = a->y + a->h;

	//Calculate the sides of rect B
	leftB = b->x;
	rightB = b->x + b->w;
	topB = b->y;
	bottomB = b->y + b->h;
	
	//If any of the sides from A are outside of B
	if (bottomA >= topB){
		isCollide =  true;
	}
	else{
		isCollide = false;
	}

	return isCollide;
}



