#ifndef _SPRITE_H_
#define _SPRITE_H_

/*
	Derek O Brien
	Sprite header file
*/

#include "GameObject.h"
#include "LTexture.h"
#include "GameDefines.h"

//Sprite image details struct
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
	Sprite(){ init(); };	//COnstructor
	~Sprite(){ cleanup(); };//deconstructor

	virtual bool init();	//init
	virtual void cleanup();	//cleaup
	void render(int posX, int posY);	//render
	void runAnimation(int posX, int posY);//create sprite animation
	bool loadMedia(std::string name);	//load sprite media

	int getPosX();	//get sprite X position
	int getPosY();	//get sprite Y position

	void setSpritePosX(int posX){ spritePosX = posX; };
	void setSpritePosY(int posY){ spritePosY = posY; };
private:

	ImageDetails imageDetails;	//sprite details
	SDL_Rect gSpriteClips[30];	//frames for animation
	SDL_Rect* currentFrame;		//current animation frame
	LTexture spriteTexture;		//sprite texture

	int frame = 0;
	int spritePosX, spritePosY;
};

#endif//_SPRITE_H_