/*
-		Derek O Brien K00105572
-		obstical cpp file

-       Sub class of Sprite
-       Has a runAI method to update logic (print statement “running AI for obstical”)
-       Has an update method (print statement “updating obstical”)
*/

#include "Obstical.h"

//Obstical init
bool Obstical::init(){
	return true;
}


//Obstical cleanup
void Obstical::cleanup(){
	delete this;
}