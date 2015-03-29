/*
-          Is an abstract factory, used to create enemy types (boss, enemy)
*/

#include "IFactory.h"

//Factory init
bool Factory::init(){
	if (!npcObject->init()){
		npcObject->init();
	}
	return true;
}


//Factory cleanup
void Factory::cleanup(){
}


//Create Obstical
std::shared_ptr<Npc> Factory::createNpc(){
	init();
	return std::shared_ptr<Npc>(new Npc());
}

/*//Create Collectable
std::shared_ptr<Collectable> Factory::createCollectable(){

	return std::shared_ptr<Collectable>(new Collectable());
}*/



