

#include "PopulateEnemies.h"

/*bool PopulateEnemies::init(){
factory = new Factory();
if (!factory->init()){
factory->init();
}

return true;
}*/


std::vector<Npc*> PopulateEnemies::populateVector(){

	factory = new Factory();

	npcVector.push_back(factory->createNpc());
	npcVector.push_back(factory->createNpc());
	npcVector.push_back(factory->createNpc());
	npcVector.push_back(factory->createNpc());
	npcVector.push_back(factory->createNpc());

	return npcVector;
}
