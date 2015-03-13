
#include "ScrollingBackground.h"
#include "GameManager.h"

//Init menthod
bool ScrollingBackground::init(){
	setObjectType(OT_BACKGROUND);
	loadmedia();

	frame = 0;
	return true;
}

//Load Background Image
bool ScrollingBackground::loadmedia(){
	bool success = true;

	//Load press texture
	if (!bg_Texture.loadFromFile("../SDL_Runner_V1.0/assets/bg_image.png")){
		printf("BG: Failed to load Background sprite sheet texture texture!\n");
		success = false;
	}
	else{
		printf("BG: Background Loaded\n");
	}

	return success;
}

//Render Background
void ScrollingBackground::render(){
	--scrollingOffset;
	if (scrollingOffset < -bg_Texture.getWidth()){
		scrollingOffset = 0;
	}
	//Render background
	bg_Texture.render(scrollingOffset, 0);
	bg_Texture.render(scrollingOffset + bg_Texture.getWidth(), 0);
}

//Update
void ScrollingBackground::update(){
}

//Clean Up Method
void ScrollingBackground::cleanup(){
	bg_Texture.cleanup();
}