/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Factory.cpp
-

-
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
	return new Npc();
}


//Create Collectable
Collectable* Factory::createCollectable(){
	return new Collectable();
}



