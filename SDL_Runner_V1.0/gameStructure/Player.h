#ifndef _PLAYER_H_
#define _PLAYER_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Player.cpp
-

*/
#include "Character.h"	//Include Character header file
#include "../dao/AssetsDao.h"

//Enum for player state
//typedef enum EPlayerState{ ALIVE, DEAD, POWERUP, JUMPING, FALLING, SLIDING };

//player is subclass of character
class Player : public Character{
public:
	Player(){ init(); };		//Constructor
	~Player(){ cleanup(); };	//DeConstructor


	virtual bool init();		//init player
	virtual void create();		//create player
	virtual void render();		//render player
	virtual void update();		//update player
	virtual void cleanup();		//cleanup player


	//Player Movements
	void jump();	//Jump up
	void fallDown();//Fall back down
	void slide();
	void powerUp();	//Player power up method

	
	// handle any input from the keyboard, mouse, or joystick
	void handleInput(SDL_Event& e);
	
	int getPlayerState(){ return currentState; };	//Get current palyer state
	void setPlayerState(EPlayerState state){ currentState = (EPlayerState)state; };	//Set player state

	//Get player bounding box
	SDL_Rect* getPlayerCollisionBox(){ return playerBoundingBox; };

private:	
	Character* player;
	SDL_Rect* playerBoundingBox;


	Path selectedPlayer;
	int playerPosX, playerPosY;
	
	EPlayerState currentState;	//Holds players current state
};
#endif//_PLAYER_H_