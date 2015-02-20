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
bool CollisionManager::checkCollision(GameObject *o, Player *p){
	registerGameObject(o);			//register object
	registerPlayer(p);				//register player

	isCollide = false;				//set collide to false
	
	return isCollide;
}



