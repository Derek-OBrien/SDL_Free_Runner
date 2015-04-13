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
	std::vector<Collectable*> populateCollectVector();

	void update();
	void render();
	//void release();
	void cleanup();
private:

	Factory* factory;
	std::vector<Npc*> birdVector;
	//std::vector<Npc*> bugVector;
	std::vector<Collectable*> coinVector;

	int npcX, npcY;
};




#endif//_POPULATE_ENEMIES_H_
