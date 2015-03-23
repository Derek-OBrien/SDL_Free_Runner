#ifndef _OBSTICAL_H_
#define _OBSTICAL_H_
/*
-		Derek O Brien K00105572
-		obstical header file
*/

#include "Sprite.h"

//obstical class is subclass of Character
class Obstical : public Sprite{

public:
	Obstical(){ init(); };			//Constructor
	~Obstical(){ cleanup(); };		//DeConstructor

	virtual bool init();
	virtual void cleanup();

	//Load, Render, Update
	virtual void render();		//render obstical
	virtual void update();		//update obstical

	GameObject* getObstical(){ return obstical; };

	SDL_Rect* getObsticalCollisionBox(){ return obsticalBoundingBox; };
private:
	
	Sprite* obstical;
	SDL_Rect* obsticalBoundingBox;

	//Position of the Obstical
	int obsticalPosX, obsticalPosY;
};

#endif//_OBSTICAL_H_