/*
-		Derek O Brien K00105572
-		Character cpp file

-       Base class for all characters, subclass of game object
*/

#include "Character.h"	//Include Character header 
#include "GameManager.h"

//Character Init
bool Character::init(){
	return true;
}

//Character Clean Up
void Character::cleanup(){
	delete this;
}