#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"	//Include Character header file


//player is subclass of character
class Player : public Character{
public:
	Player(){ this->init(); };		//Constructor
	~Player(){ this->cleanup(); };	//DeConstructor

	virtual bool init();
	virtual void cleanup();

	void jump();	//Player jump method
	void slide();	//Player slide Method
	void superSize();	//Player boost method

	void render();		//render player
	void update();		//update player

	int getPlayerState(){ return currentState; };	//Get current palyer state
	void setPlayerState(int state){ currentState = (EPlayerState)state; };	//Set player state
	void displayPlayerState();

	//Enum for player state
	typedef enum { ALIVE, DEAD, SUPERSIZE, JUMPING, SLIDING } EPlayerState;

private:
	EPlayerState currentState;	//Holds players current state
};

#endif//_PLAYER_H_