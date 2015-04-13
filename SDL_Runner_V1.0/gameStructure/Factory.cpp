/*
-          Is an abstract factory, used to create enemy types (boss, enemy)
*/

#include "IFactory.h"

//Factory init
bool Factory::init(){


	return true;
}


//Factory cleanup
void Factory::cleanup(){
	npcObject->cleanup();
	collObject->cleanup();
}


//Create Obstical
Npc*Factory::createBirdNpc(){
	npcObject = new Npc();
	return npcObject;
}

Npc*Factory::createBugNpc(){
	npcObject = new Npc();
	return npcObject;
}

//Create Collectable
Collectable* Factory::createCollectable(){
	collObject = new Collectable();
	return collObject;
}



