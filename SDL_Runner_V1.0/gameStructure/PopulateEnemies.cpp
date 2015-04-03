

#include "PopulateEnemies.h"

/*bool PopulateEnemies::init(){
factory = new Factory();
if (!factory->init()){
factory->init();
}

return true;
}*/


std::vector<Npc*> PopulateEnemies::populateBirdVector(){

	factory = new Factory();

	birdVector.push_back(factory->createBirdNpc());
	birdVector.push_back(factory->createBirdNpc());
	birdVector.push_back(factory->createBirdNpc());
	birdVector.push_back(factory->createBirdNpc());
	birdVector.push_back(factory->createBirdNpc());

	return birdVector;
}


std::vector<Npc*> PopulateEnemies::populateBugVector(){

	factory = new Factory();

	bugVector.push_back(factory->createBugNpc());
	bugVector.push_back(factory->createBugNpc());
	bugVector.push_back(factory->createBugNpc());
	bugVector.push_back(factory->createBugNpc());
	bugVector.push_back(factory->createBugNpc());

	return bugVector;
}
