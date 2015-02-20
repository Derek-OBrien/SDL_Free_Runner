/*
-		Derek O Brien K00105572
-		Player cpp file
			
-       Sub class of Character
-       Has movement methods (jump, duck or what you see fit)
-       Has a boost function
-       Has a state getter/setter with the states being (ALIVE, DEAD, BOOSTING, JUMPING)
*/

#include "Player.h"	//Include player header

//Player Init
bool Player::init(){
	setPlayerState(ALIVE);			//Set state to ALIVE
	return true;
}

void Player::cleanup(){
	delete this;
}

//Jump function sets player state to JUMP
void Player::jump(){
	setPlayerState(JUMPING);					//Set player State to JUMP
}

//Boost function sets player state to BOOST
void Player::superSize(){
	setPlayerState(SUPERSIZE);					//set player state to SUPERSIZE
}

//Slide function sets player state to SLIDE
void Player::slide(){
	setPlayerState(SLIDING);					//set player state to SLIDE
}

//Player update: updates player after input
void Player::update(){

	superSize();			//Call boost methos
	jump();					//Call jump method
	slide();				//Call slide method
}


