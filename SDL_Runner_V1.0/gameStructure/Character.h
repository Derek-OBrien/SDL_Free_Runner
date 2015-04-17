#ifndef _CHARACTER_H_
#define _CHARACTER_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Character.h
-

-		
*/

#include "Sprite.h"

//Character class inherits from gameObject class

class Character: public Sprite{	
public:
	Character(){ init(); };	//Constructor
	~Character(){ cleanup(); };	//DeConstructor

	virtual bool init();
	virtual void create(){};
	virtual void cleanup();


private:


};

#endif//_CHARACTER_H_
