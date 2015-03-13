#ifndef _SCROLLING_BACKGROUND_H_
#define _SCROLLING_BACKGROUND_H_

#include "LTexture.h"
#include "GameDefines.h"

class ScrollingBackground : public GameObject{
public:

	ScrollingBackground(){ this->init(); };
	~ScrollingBackground(){ this->cleanup(); };

	virtual bool init();
	virtual void render();
	virtual void update();
	virtual void cleanup();

	bool loadmedia();
	
private:
	LTexture bg_Texture;
	SDL_Rect bg_Clips[1];
	SDL_Rect* currentFrame;

	int frame;
	int scrollingOffset;

};

#endif//_SCROLLING_BACKGROUND_H_