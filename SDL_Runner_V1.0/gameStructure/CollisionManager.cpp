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
	
	int A_l, A_r, A_t, A_b;
	int B_l, B_r, B_t, B_b;
	
	//Calculate the sides of rect A
	A_l = a->x;
	A_r = a->x + a->w;
	A_t = a->y;
	A_b = a->y + a->h;

	//Calculate the sides of rect B
	B_l = b->x;
	B_r = b->x + b->w;
	B_b = b->y;
	B_t = b->y + b->h;
	
	//if right of a >= left of b
	if (A_r <= B_l){
		isCollide =  true;
	}
	else{
		isCollide = false;
	}

	return isCollide;
}



