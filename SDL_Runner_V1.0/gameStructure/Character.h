#ifndef _CHARACTER_H_
#define _CHARACTER_H_

/*
-		Derek O Brien K00105572
-		Character header file
*/

#include "Sprite.h"

//Character class inherits from gameObject class

class Character: public Sprite{	
public:
	Character(){ init(); };	//Constructor
	~Character(){ cleanup(); };	//DeConstructor

	virtual bool init();
	virtual void cleanup();


private:


};

#endif//_CHARACTER_H_
