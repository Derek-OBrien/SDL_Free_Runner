#ifndef _COLLISION_MANAGER_H_
#define _COLLISION_MANAGER_H_

#include "WorldManager.h"

class CollisionManager{
public:
	static CollisionManager* getInstance();		//Singleton 

	void registerPlayer(Player *p);				//register player with collision manager
	void registerGameObject(GameObject *o);		//register gameObject with collision manager
	bool checkCollision(GameObject *o, Player *p);	//check for collision between player and object

private:
	CollisionManager(){};//constructor
	~CollisionManager(){};//deconstructor

	bool isCollide;//bool for collision
	
};

#endif//_COLLISION_MANAGER_H_