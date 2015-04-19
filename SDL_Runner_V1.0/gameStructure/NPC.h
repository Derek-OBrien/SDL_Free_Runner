#ifndef _NPC_H_
#define _NPC_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Npc.h
-

*/
#include "Collectable.h"

//Npc class Subclass of character
class Npc : public Character{
public:
	Npc(){ init(); };		//Constructor
	~Npc(){ cleanup(); };	//Deconstructor

	virtual bool init();	//Init
	virtual void create(std::string npcName, int posX, int posY);//Create
	virtual void cleanup();	//Cleanup
	virtual void render();	//Render
	virtual void update(int vel);	//Update

	void resetPosition();	//Reset Position
	//Get objects bounding box
	SDL_Rect* getNpcCollisionBox(){ return npcBoundingBox; };

private:
	Character* npc;
	SDL_Rect* npcBoundingBox;

	//Npc name & position
	std::string npcName;
	int npcPosX, npcPosY;
};

#endif//_NPC_H_