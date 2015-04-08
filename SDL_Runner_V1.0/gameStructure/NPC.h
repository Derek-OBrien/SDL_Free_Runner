
#ifndef _NPC_H_
#define _NPC_H_

#include "Collectable.h"

class Npc : public Character{
public:
	Npc(){ init(); };
	~Npc(){ cleanup(); };

	virtual bool init();
	virtual void create(std::string npcName, int posX, int posY);
	virtual void cleanup(){};
	virtual void render();
	virtual void update();

	SDL_Rect* getNpcCollisionBox(){ return npcBoundingBox; };

private:
	Character* npc;
	SDL_Rect* npcBoundingBox;

	std::string npcName;
	int npcPosX, npcPosY;
};

#endif//_NPC_H_