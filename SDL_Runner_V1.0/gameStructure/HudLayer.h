#ifndef _HUDLAYER_H_
#define _HUDLAYER_H_

#include "Layer.h"
class HudLayer : public Layer{
public:
	HudLayer(){};
	~HudLayer(){};

	bool init();
	void create();
	void update(){};
	void render();
	void cleanup(){};


private:
	Layer* hud;
};

#endif//_HUDLAYER_H_