#ifndef _LABEL_H_
#define _LABEL_H_

#include "GameObject.h"
#include <sstream>

class Label : public GameObject{
public:
	Label(){ init(); };
	~Label(){ cleanup(); };

	virtual bool init();
	virtual void create(std::string displayText, int size, SDL_Color color);
	virtual void render(int x, int y);
	virtual void cleanup();

	virtual LTexture* loadTTFMedia(std::string displayText, int size, SDL_Color color);

private:
	LTexture* textTexture;
};

#endif//_LABEL_H_