
#include "ScrollingBackground.h"
#include "GameManager.h"

//Init menthod
bool ScrollingBackground::init(){
	ground = new GameObject();
	ground->setObjectType(OT_BACKGROUND);
	groundBoundingBox = ground->getObjectBoundingBox();

	loadmedia();
	frame = 0;

	return true;
}

//Load Background Image
bool ScrollingBackground::loadmedia(){
	bool success = true;

	//Load press texture
	if (!bg_Texture.loadFromFile("../SDL_Runner_V1.0/assets/backgrounds/bg_image.png")){
		printf("SBG: Failed to load Background texture!\n");
		success = false;
	}
	else if (!bg_Texture_ForeGround.loadFromFile("../SDL_Runner_V1.0/assets/backgrounds/bg_foreground.png")){
		printf("SBG: Failed to load Forground texture!\n");
		success = false;
	}
	else{
		printf("SBG: Background Loaded\n");
		printf("SBG: Foreground Loaded\n");

		ground->setObjectBoundingBox(0, 560, 50, GAME_WIDTH);
	}

	return success;
}

//Render Background
void ScrollingBackground::renderBg(){
	--scrollingOffset;
	if (scrollingOffset < -bg_Texture.getWidth()){
		scrollingOffset = 0;
	}
	//Render background
	bg_Texture.render(scrollingOffset, 0);
	bg_Texture.render(scrollingOffset + bg_Texture.getWidth(), 0);
}

//Render Background
void ScrollingBackground::renderFg(){
	--scrollingOffset;
	if (scrollingOffset < -bg_Texture_ForeGround.getWidth()){
		scrollingOffset = 0;
	}
	//Render background
	bg_Texture_ForeGround.render(scrollingOffset, 535);
	bg_Texture_ForeGround.render(scrollingOffset + bg_Texture_ForeGround.getWidth(), 535);
}

//Update
void ScrollingBackground::update(){

}

//Clean Up Method
void ScrollingBackground::cleanup(){
	bg_Texture.cleanup();
}