#ifndef _WORLD_MANAGER_H_
#define _WORLD_MANAGER_H_
/*
-          Singleton
-          Holds all other game object pointers
-          Gives access to other classes to those objects.
*/
//#include "GameObject.h"
#include "IFactory.h"
#include <vector>
using namespace std;

class WorldManager{
public:
	static WorldManager* getInstance();

	Player* getPlayerInstance();
	Factory*  getFactoryInstance();

	void populateVector(GameObject *o);

	void cleanup();
private:
	WorldManager(){};
	~WorldManager(){};

	Factory * factoryInstance;
	Player * playerInstance;	

};

#endif//_WORLD_MANAGER_H_


/* Singletons have one one reference */
//any object that is accessing this one
//will be accessing the same instance
//this means that all local variables will
//be the same
//we can also access this object from anywhere in our
//program
//Alternative to singleton is //single instance//...