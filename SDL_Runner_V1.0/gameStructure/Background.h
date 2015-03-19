#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "GameObject.h"

class BackGround : public GameObject{
public:
	BackGround(){ this->init(); };
	~BackGround(){ this->cleanup(); };

	virtual bool init();
	virtual void cleanup();
	virtual void render();

	bool loadMedia(std::string path);

private:

	GameObject* background;
	LTexture bg_Texture;

};

#endif//_BACKGROUND_H_