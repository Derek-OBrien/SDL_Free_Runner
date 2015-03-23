#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "GameObject.h"
#include "LTexture.h"

//Struct for button deatils from xml file
struct ButtonDetails{
	std::string name;
	std::string pathToFile;
	int height;
	int width;
	int offsetX;
	int offsetY;
	int frames;
	int posX;
	int posY;
	int state;
};

typedef enum ButtonState{ NORMAL, PRESSED, HOVER };	//enum to hold button state

class Button : public GameObject{
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


private:
	
	ButtonState currentButtonState;
	ButtonDetails buttonDetails;
	LTexture buttonTexture;

	SDL_Rect gSpriteClips[30];
	SDL_Rect* currentFrame;

};



#endif//_BUTTON_H_