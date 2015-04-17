#ifndef _SCROLLING_BACKGROUND_H_
#define _SCROLLING_BACKGROUND_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: ScrollingBackground.h
-

-		Inherits from layer. 
*/
#include "Layer.h"

/*
	SUb Class Of Layer
*/
class ScrollingBackground : public Layer{
public:

	ScrollingBackground(){ init();};
	~ScrollingBackground(){ cleanup(); };

	virtual bool init();	//Init
	virtual void create(std::string name);	//Create
	virtual void render(std::string name, int scrollSpeed);	//Reneder
	virtual void update();	//update
	virtual void cleanup();	//cleanup
	
private:

	Layer* bg;
	Path path;

};

#endif//_SCROLLING_BACKGROUND_H_