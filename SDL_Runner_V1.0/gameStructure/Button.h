#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "LTexture.h"
#include "Sprite.h"

typedef enum ButtonState{ NORMAL, HOVER, PRESSED };	//enum to hold button state

class Button : public Sprite{
public:
	Button(){ init(); };
	~Button(){ cleanup(); };
	
	virtual bool init();
	void create(std::string name);

	virtual void render(std::string name);
	virtual void cleanup();
	bool loadmedia(std::string name);

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