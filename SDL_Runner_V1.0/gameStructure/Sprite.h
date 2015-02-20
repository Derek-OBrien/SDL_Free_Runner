#ifndef _SPRITE_H_
#define _SPRITE_H_

/*
	Derek O Brien
	Sprite header file
*/

#include "LTexture.h"

class Sprite : public GameObject{
public:
	Sprite(){ this->init(); };
	~Sprite(){ this->cleanup(); };

	virtual bool init();
	virtual void cleanup();

	bool loadMedia(LTexture texture);

	//Setters
	void setPathToFile(std::string path){ pathToFile = path; };
	void setSpriteHeight(float height){ mSpriteHeight = height; };
	void setSpriteWidth(float width){ mSpriteWidth = width; };

	//Getters
	std::string getPathToFile(){ return pathToFile; };
	float getSpriteHeight(){ return mSpriteHeight; };
	float getSpriteWidth(){ return mSpriteWidth; };

private:
	std::string pathToFile;
	float mSpriteHeight;
	float mSpriteWidth;
	
};

#endif//_SPRITE_H_