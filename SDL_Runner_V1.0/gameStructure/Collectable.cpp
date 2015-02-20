/*
-		Derek O Brien K00105572
-		obstical cpp file

-       Sub class of Sprite
-       Has a runAI method to update logic (print statement “running AI for Collectable”)
-       Has an update method (print statement “updating Collectable”)
*/

#include "Collectable.h"


//Collectable init
bool Collectable::init(){
	return true;
}


//Collectable cleanup
void Collectable::cleanup(){
	delete this;
}
