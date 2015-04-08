#ifndef _LAYER_H_
#define _LAYER_H_

#include "GameObject.h"
#include "../dao/AssetsDao.h"

/*
	Base class for all background and foreground layers
*/
class Layer : public GameObject{
public:
	Layer(){ init(); };
	~Layer(){ cleanup(); };

	virtual void create(std::string name);
	virtual bool init();
	virtual void cleanup();
	virtual void render(int alpha);
	virtual void scrollingRender(int alpha, std::string name);

	bool loadMedia(std::string path);

private:
	GameObject* layer;
	LTexture bg_Texture;

	int scrollingOffset;
};

#endif//_BACKGROUND_H_