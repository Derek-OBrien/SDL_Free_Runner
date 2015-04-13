#ifndef _L_TEXTURE_H_
#define _L_TEXTURE_H_

//Texture wrapper class
/*
	Author		: Derek O' Brien
	File		: LTexture.h
	Description	: Base texture class for all in game textures
*/
#include "GameObject.h"

class LTexture{
public:

	LTexture(){ init(); };			//Initializes variables
	~LTexture(){ cleanup(); };		//Deallocates memory

	virtual bool init();		//Initializes variables
	virtual void cleanup();		//Deallocates texture
	LTexture loadmedia(std::string path);	//load texture media
	bool loadFromFile(std::string path);	//get media from file

	//load TTF media
	bool loadFromRenderedText(std::string text, SDL_Color color, TTF_Font* myFont);

	//render texture
	void render(int x, int y, SDL_Rect* clip = NULL);

	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);

	//Gets image dimensions
	int getWidth(){ return mWidth; };
	int getHeight(){ return mHeight; };

private:

	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};

#endif//_L_TEXTURE_H_