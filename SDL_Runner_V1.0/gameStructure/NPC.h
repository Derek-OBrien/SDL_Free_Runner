
#ifndef _NPC_H_
#define _NPC_H_

#include "Collectable.h"

class Npc : public Character{
public:
	Npc(){ init(); };
	~Npc(){ cleanup(); };

	bool init();
	void create(std::string npcName);
	void cleanup(){};
	void render();
	void update();

	SDL_Rect* getNpcCollisionBox(){ return npcBoundingBox; };

private:
	Character* npc;
	SDL_Rect* npcBoundingBox;

	std::string npcName;
	int npcPosX, npcPosY;
};

#endif//_NPC_H_