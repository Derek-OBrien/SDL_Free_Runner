#ifndef _COLLECTABLE_H_
#define _COLLECTABLE_H_
/*
-		Derek O Brien K00105572
-		collectable header file
*/

#include "Player.h"		//include player

//collectable class is subclass of Character
class Collectable : public GameObject{

public:
	Collectable(){ this->init(); };		//Constructor
	~Collectable(){ this->cleanup(); };		//DeConstructor

	virtual bool init();
	virtual void cleanup();

private:
	

};

#endif//_COLLECTABLE_H_