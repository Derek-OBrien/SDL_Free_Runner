#ifndef _L_TEXTURE_H_
#define _L_TEXTURE_H_

/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: LTexture.h
-

-		Game Texture class.
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