#ifndef _SCROLLING_BACKGROUND_H_
#define _SCROLLING_BACKGROUND_H_

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
	virtual void render(std::string name);	//Reneder
	virtual void update();	//update
	virtual void cleanup();	//cleanup
	
private:

	Layer* bg;
	Path path;

};

#endif//_SCROLLING_BACKGROUND_H_