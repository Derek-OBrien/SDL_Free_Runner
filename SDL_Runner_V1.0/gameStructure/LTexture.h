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

	//Loads image at specified path
	bool loadFromFile(std::string path, SDL_Renderer* gRenderer);

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue){ SDL_SetTextureColorMod(mTexture, red, green, blue); };

	//Set blending
	void setBlendMode(SDL_BlendMode blending){ SDL_SetTextureBlendMode(mTexture, blending); };

	//Set alpha modulation
	void setAlpha(Uint8 alpha){ SDL_SetTextureAlphaMod(mTexture, alpha); };

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Gets image dimensions
	int getWidth(){ return mWidth; };
	int getHeight(){ return mHeight; };

	//Setters
	void setSDLRenderer(SDL_Renderer* renderer){ gRenderer = renderer; };

	SDL_Renderer* getSDLRenderer(){ return gRenderer; };
private:
	//The actual hardware texture
	SDL_Texture* mTexture;
	SDL_Renderer* gRenderer;
	//Image dimensions
	int mWidth;
	int mHeight;
};

#endif//_L_TEXTURE_H_