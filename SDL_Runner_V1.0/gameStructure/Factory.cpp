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
	delete this;
}


//Create Obstical
std::shared_ptr<Obstical> Factory::createObstical(){
	
	return std::shared_ptr<Obstical>(new Obstical());
}

//Create Collectable
std::shared_ptr<Collectable> Factory::createCollectable(){

	return std::shared_ptr<Collectable>(new Collectable());
}



