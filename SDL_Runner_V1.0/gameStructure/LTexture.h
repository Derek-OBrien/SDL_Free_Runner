#ifndef _L_TEXTURE_H_
#define _L_TEXTURE_H_

//Texture wrapper class

#include "GameObject.h"

class LTexture{
public:

	LTexture(){ this->init(); };			//Initializes variables
	~LTexture(){ this->cleanup(); };		//Deallocates memory

	virtual bool init();
	virtual void cleanup();		//Deallocates texture
	
	LTexture loadmedia(std::string path);
	LTexture loadTTFMedia(std::string displayText, int size, SDL_Color color);
	bool loadFromFile(std::string path);
#ifdef _SDL_TTF_H
	bool loadFromRenderedText(std::string text, SDL_Color color);
#endif

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