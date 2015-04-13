#ifndef _BUTTON_H_
#define _BUTTON_H_

/*
	Author		:	Derek O' Brien
	File		:	Button.h
	Description	:	Button Class for creating button elements
					Inherits From Sprite
*/
//Includes
#include "LTexture.h"
#include "Sprite.h"

//Button State Enum
typedef enum ButtonState{ NORMAL, HOVER, PRESSED };	

class Button : public Sprite{
public:
	Button(){ init(); };		//Constructor calls init
	~Button(){ cleanup(); };	//DeConstructor calls cleanup
	
	virtual bool init();	// Button Init
	virtual void create(std::string name);	//Create button
	virtual void render(std::string name);
	bool loadmedia(std::string name);
	virtual void cleanup();

	void handleMouseEvent(SDL_Event* e);


	//Set and Get Button State
	void setButtonState(ButtonState state) { currentButtonState = state; };
	ButtonState getButtonState(){ return currentButtonState; };

	std::string playerSelected(){ return selectedPlayer; };

private:
	ButtonState currentButtonState;
	ImageDetails buttonDetails;
	LTexture buttonTexture;

	SDL_Rect gSpriteClips[30];
	SDL_Rect* currentFrame;

	std::string selectedPlayer;
};
#endif//_BUTTON_H_