#ifndef _CHARACTER_H_
#define _CHARACTER_H_

/*
-		Derek O Brien K00105572
-		Character header file
*/

#include "GameObject.h"

//Character class inherits from gameObject class
class Character: public GameObject{	
public:
	Character(){ this->init(); };	//Constructor
	~Character(){ this->cleanup(); };	//DeConstructor

	virtual bool init();
	virtual void cleanup();

	void setSpriteDimensions(int height, int width){ mSpriteHeight = height; mSpriteWidth = width; };	//Set sprite dimensions
	int getSpriteWidth(){ return mSpriteWidth; };	//Get Sprite width
	int getSpriteHeight(){ return mSpriteHeight; };	//Get Sprite Height



private:

	int mSpriteWidth;	//Hold sprite width
	int mSpriteHeight;	//Hold sprite height

};

#endif//_CHARACTER_H_
