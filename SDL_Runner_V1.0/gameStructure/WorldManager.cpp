#include "WorldManager.h"

/*
-          Singleton
-          Holds all other game object pointers
-          Gives access to other classes to those objects.
*/

WorldManager * worldManagerInstance = 0;//instance of the object to be used


WorldManager* WorldManager::getInstance(){
	if (worldManagerInstance == 0){						//if the instance is null
		worldManagerInstance = new WorldManager();		//create the instance 
	}													//otherwise
	return worldManagerInstance;						//return the instance
}

/*Player* WorldManager::getPlayerInstance(){	
	return playerInstance = new Player;				//return instance of player
}

Factory* WorldManager::getFactoryInstance(){
	return factoryInstance = new Factory;
}*/
