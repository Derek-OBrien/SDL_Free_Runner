#ifndef _POPULATE_ENEMIES_H_
#define _POPULATE_ENEMIES_H_

#include "IFactory.h"

class PopulateEnemies{
public:
	PopulateEnemies(){ };	
	~PopulateEnemies(){};

	//virtual bool init();
	std::vector<Npc*> populateBirdVector();
	std::vector<Npc*> populateBugVector();

private:

	Factory* factory;
	std::vector<Npc*> birdVector;
	std::vector<Npc*> bugVector;

};


#endif//_POPULATE_ENEMIES_H_
