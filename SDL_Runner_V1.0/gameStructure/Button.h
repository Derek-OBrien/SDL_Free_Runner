#ifndef _BUTTON_H_
#define _BUTTON_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Button.h
-

-		
*/

//Includes
#include "Sprite.h"

//Button State Enum
typedef enum ButtonState{ NORMAL, HOVER, PRESSED };	

class Button : public Sprite{
public:
	Button(){ init(); };		//Constructor calls init
	~Button(){ cleanup(); };	//DeConstructor calls cleanup
	
	virtual bool init();	// Button Init
	virtual void create(std::string name);	//Create button
	virtual void render(std::string name);	//render button
	bool loadmedia(std::string name);		//load button
	virtual void cleanup();					//cleanup

	void handleMouseEvent(SDL_Event* e);	//handle events on button


	//Set and Get Button State
	void setButtonState(ButtonState state) { currentButtonState = state; };
	ButtonState getButtonState(){ return currentButtonState; };

	std::string playerSelected(){ return selectedPlayer; };

private:
	ButtonState currentButtonState;	//Button state
	ImageDetails buttonDetails;		//Button details
	LTexture buttonTexture;			//Button texture

	SDL_Rect gSpriteClips[30];		//button animation 
	SDL_Rect* currentFrame;			//current animation frame

	std::string selectedPlayer;		//string for selected player
};
#endif//_BUTTON_H_