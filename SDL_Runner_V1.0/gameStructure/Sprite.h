#ifndef _SPRITE_H_
#define _SPRITE_H_

/*
	Derek O Brien
	Sprite header file
*/

#include "GameObject.h"
#include "LTexture.h"
#include "GameDefines.h"

struct ImageDetails{

	std::string name;
	std::string pathToFile;
	int spriteHeight;
	int spriteWidth;
	int offsetX;
	int offsetY;
	int frames;
	int posX;
	int posY;

};

class Sprite : public GameObject{
public:
	Sprite(){ init(); };
	~Sprite(){ cleanup(); };

	virtual bool init();
	virtual void cleanup();
	void render(int posX, int posY);
	void runAnimation(int posX, int posY);
	bool loadMedia(std::string name);

	int getPosX();
	int getPosY();

private:

	ImageDetails imageDetails;
	SDL_Rect gSpriteClips[30];
	SDL_Rect* currentFrame;
	LTexture spriteTexture;

	int frame = 0;

};

#endif//_SPRITE_H_