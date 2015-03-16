#ifndef _SCROLLING_BACKGROUND_H_
#define _SCROLLING_BACKGROUND_H_

#include "Background.h"
class ScrollingBackground : public BackGround{
public:

	ScrollingBackground(){ this->init(); };
	~ScrollingBackground(){ this->cleanup(); };

	virtual bool init();
	void renderBg();
	void renderFg();
	virtual void update();
	virtual void cleanup();


	bool loadmedia();
	

	GameObject* getGround(){ return ground; };

private:
	LTexture bg_Texture;
	LTexture bg_Texture_ForeGround;

	GameObject* ground;
	SDL_Rect* groundBoundingBox;

	int frame;
	int scrollingOffset;

};

#endif//_SCROLLING_BACKGROUND_H_