#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"	//Include Character header file
#include "../dao/AssetsDao.h"

//Enum for player state
typedef enum EPlayerState{ ALIVE, DEAD, POWERUP, JUMPING, FALLING, SLIDING };

//player is subclass of character
class Player : public Character{
public:
	Player(){ init(); };		//Constructor
	~Player(){ cleanup(); };	//DeConstructor


	virtual bool init();
	virtual void cleanup();
	virtual void render();		//render player
	virtual void update();	//update player


	//Player Movements
	void jump();	//Jump up
	void fallDown();//Fall back down
	void slide();
	void powerUp();	//Player boost method

	
	// handle any input from the keyboard, mouse, or joystick
	void handleInput(SDL_Event& e);
	
	int getPlayerState(){ return currentState; };	//Get current palyer state
	void setPlayerState(EPlayerState state){ currentState = (EPlayerState)state; };	//Set player state


	GameObject* getPlayer(){ return player; };

	SDL_Rect* getPlayerCollisionBox(){ return playerBoundingBox; };

private:	
	Character* player;
	SDL_Rect* playerBoundingBox;

	Path selectedPlayer;

	int playerPosX, playerPosY;
	int powerUpTime;

	EPlayerState currentState;	//Holds players current state
};
#endif//_PLAYER_H_