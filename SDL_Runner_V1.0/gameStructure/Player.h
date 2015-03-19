#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"	//Include Character header file
#include "SpriteAnimation.h"

//player is subclass of character
class Player : public Character{
public:
	Player(){ this->init(); };		//Constructor
	~Player(){ this->cleanup(); };	//DeConstructor


	virtual bool init();
	virtual void cleanup();

	//Load, Render, Update
	bool loadMedia();
	virtual void render();		//render player
	virtual void update();	//update player



	//Player Movements
	void jump();	//Jump up
	void fallDown();//Fall back down
	void superSize();	//Player boost method


	
	// handle any input from the keyboard, mouse, or joystick
	void handleInput(SDL_Event& e);
	
	int getPlayerState(){ return currentState; };	//Get current palyer state
	void setPlayerState(int state){ currentState = (EPlayerState)state; };	//Set player state


	GameObject* getPlayer(){ return player; };

	//Enum for player state
	typedef enum { ALIVE, DEAD, SUPERSIZE, JUMPING, FALLING, SLIDING } EPlayerState;


	//Scene sprites
	SDL_Rect gSpriteClips[PLAYER_ANIMATION_FRAMES];
	SDL_Rect* currentFrame;
	LTexture gSpriteSheetTexture;


private:	
	GameObject* player;
	SDL_Rect* playerBoundingBox;
	
	SpriteAnimation spriteAnimation;
	//The X & Y offset of the dot
	int m_PlayerPosX, m_PlayerPosY;
	int frame;


	// player can be SuperSize for a time
	int m_SuperSize;
	int m_SuperSizeTime;

	EPlayerState currentState;	//Holds players current state
};

#endif//_PLAYER_H_