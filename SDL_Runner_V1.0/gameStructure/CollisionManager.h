#ifndef _COLLISION_MANAGER_H_
#define _COLLISION_MANAGER_H_

#include <SDL.h>

class CollisionManager{
public:
	static CollisionManager* getInstance();		//Singleton 

	bool checkCollision(SDL_Rect* a, SDL_Rect* b);	//check for collision between player and object

private:
	CollisionManager(){};//constructor
	~CollisionManager(){};//deconstructor

	bool isCollide;//bool for collision
	
};

#endif//_COLLISION_MANAGER_H_