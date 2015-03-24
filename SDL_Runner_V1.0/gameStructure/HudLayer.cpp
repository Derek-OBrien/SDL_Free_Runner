
#include "HudLayer.h"

bool HudLayer::init(){

	if (!Layer::init()){
		Layer::init();
	}
	
	hud = new Layer();
	return true;
}

void HudLayer::create(){

	init();
	hud->loadMedia("hud");

}

void HudLayer::render(){
	hud->render();
}