#ifndef _LAYER_H_
#define _LAYER_H_

#include "GameObject.h"

class Layer : public GameObject{
public:
	Layer(){ this->init(); };
	~Layer(){ this->cleanup(); };

	void create(std::string name);
	virtual bool init();
	virtual void cleanup();
	virtual void render();

	bool loadMedia(std::string path);

private:

	GameObject* background;
	LTexture bg_Texture;

};

#endif//_BACKGROUND_H_