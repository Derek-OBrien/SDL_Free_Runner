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
	Obstical(){ this->init(); };			//Constructor
	~Obstical(){ this->cleanup(); };		//DeConstructor

	virtual bool init();
	virtual void cleanup();

	//Load, Render, Update
	bool loadMedia();
	virtual void render();		//render obstical
	virtual void update();		//update obstical

	GameObject* getObstical(){ return obstical; };

private:
	
	GameObject* obstical;
	SDL_Rect* obsticalBoundingBox;
	LTexture gObsticalTexture;

	int scrollingOffset;
	//The X & Y offset of the dot
	int m_obsticalPosX, m_obsticalPosY;
};

#endif//_OBSTICAL_H_