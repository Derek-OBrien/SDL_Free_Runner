#ifndef _LAYER_H_
#define _LAYER_H_

/*
	Author		: Derek O' Brien
	File		: Layer.h
	Description	: Base Class for all game layers 
*/

#include "GameObject.h"
#include "../dao/AssetsDao.h"

//Laayer is sub class of object
class Layer : public GameObject{
public:
	Layer(){ init(); };		//constructor calls inti
	~Layer(){ cleanup(); };	//deconstructor calls cleanup

	virtual void create(std::string name);	//create layer	
	virtual bool init();	//init layer
	virtual void cleanup();	//cleanup
	virtual void render(int alpha);	//render layer
	virtual void scrollingRender(int alpha, std::string name);	//render scrolling layr

	bool loadMedia(std::string path);	//load layer media

private:
	GameObject* layer;
	LTexture bg_Texture;

	int scrollingOffset;
};

#endif//_BACKGROUND_H_