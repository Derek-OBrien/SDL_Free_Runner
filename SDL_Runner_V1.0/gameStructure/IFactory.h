#ifndef _I_FACTORY_H_
#define _I_FACTORY_H_

/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: IFactory.h
-

-		
*/
#include "Npc.h"
#include <iostream>
#include <memory>


/* IFactory Interface */
class IFactory{
public:
	// pure virtual methods need to be implemented in sub classes
	virtual bool init() = 0;
	virtual void cleanup() = 0;

	virtual Npc* createBirdNpc() = 0;

	virtual Collectable* createCollectable() = 0;
};

#endif//_I_FACTORY_H_



#ifndef _FACTORY_H_
#define _FACTORY_H_

class Factory{
public:

	Factory(){ };			// constructor
	~Factory(){ this->cleanup(); };		// deconstructor
	virtual bool init();				// initialization	
	virtual void cleanup();				// delete EnemyFactory	

	virtual Npc* createBirdNpc();

	virtual Collectable* createCollectable();

private:

	Npc* npcObject;
	Collectable* collObject;
};

#endif//_FACTORY_H_