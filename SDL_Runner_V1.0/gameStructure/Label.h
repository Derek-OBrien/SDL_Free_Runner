#ifndef _LABEL_H_
#define _LABEL_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Label.h
-

-		
*/
#include "GameObject.h"
#include <sstream>

class Label : public GameObject{
public:
	Label(){ init(); };		//constructor calls init
	~Label(){ cleanup(); };	//decconstructor calls cleanup

	virtual bool init();	//init
	virtual void create(std::string displayText, int size, SDL_Color color);	//create 
	virtual void render(int x, int y);	//render
	virtual void cleanup();	//cleanup

	//load TTF label media
	virtual LTexture* loadTTFMedia(std::string displayText, int size, SDL_Color color);

private:
	//Text texture
	LTexture* textTexture;

	LTexture* temp;

};

#endif//_LABEL_H_