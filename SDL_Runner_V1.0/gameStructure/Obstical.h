#ifndef _OBSTICAL_H_
#define _OBSTICAL_H_
/*
-		Derek O Brien K00105572
-		obstical header file
*/

#include "Player.h"		//include player

//obstical class is subclass of Character
class Obstical : public GameObject{

public:
	Obstical(){ this->init(); };		//Constructor
	~Obstical(){ this->cleanup(); };		//DeConstructor

	virtual bool init();
	virtual void cleanup();

private:
	

};

#endif//_OBSTICAL_H_