#ifndef _POPULATE_ENEMIES_H_
#define _POPULATE_ENEMIES_H_

#include "IFactory.h"

class PopulateEnemies{
public:
	PopulateEnemies(){ };	
	~PopulateEnemies(){};

	//virtual bool init();
	std::vector<Npc*> populateVector();

private:

	Factory* factory;
	std::vector<Npc*> npcVector;
};


#endif//_POPULATE_ENEMIES_H_
