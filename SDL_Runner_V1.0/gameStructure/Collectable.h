#ifndef _COLLECTABLE_H_
#define _COLLECTABLE_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Collectable.h
-

-		
*/

#include "Player.h"		//include player

//collectable class is subclass of Sprite
class Collectable : public Sprite{

public:
	Collectable(){ init(); };		//Constructor
	~Collectable(){ cleanup(); };		//DeConstructor

	virtual bool init();		//Init
	virtual void create(std::string name, int posX, int posY);	//Creat
	virtual void update(int vel);		//Update
	void resetPosition();		//resetPosition
	virtual void render();		//Render
	virtual void cleanup();		//cleanup

	//Get objects boungin box
	SDL_Rect* getCollectableCollisionBox(){ return collectableBB; };

private:
	
	Sprite* collectable;
	SDL_Rect* collectableBB;
	//Position
	int collPosX, collPosY;
};

#endif//_COLLECTABLE_H_