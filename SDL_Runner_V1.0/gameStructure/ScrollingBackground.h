#ifndef _SCROLLING_BACKGROUND_H_
#define _SCROLLING_BACKGROUND_H_

#include "Layer.h"

class ScrollingBackground : public Layer{
public:

	ScrollingBackground(){ init();};
	~ScrollingBackground(){ cleanup(); };

	virtual bool init();
	virtual void create(std::string name);
	virtual void render(std::string name);
	virtual void update();
	virtual void cleanup();
	
private:

	Layer* bg;
	Path path;

};

#endif//_SCROLLING_BACKGROUND_H_