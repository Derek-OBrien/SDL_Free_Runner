#ifndef _LAYER_H_
#define _LAYER_H_

/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Layer.h
-

-		
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
	virtual void scrollingRender(int alpha, std::string name, int scrollSpeed);	//render scrolling layr

	bool loadMedia(std::string path);	//load layer media

private:
	GameObject* layer;
	LTexture bg_Texture;

	int scrollingOffset;
};

#endif//_BACKGROUND_H_