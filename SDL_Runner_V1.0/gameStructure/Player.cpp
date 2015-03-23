/*
-		Derek O Brien K00105572
-		Player cpp file
*/

#include "Player.h"	//Include player header
#include "GameManager.h"
#include "../dao/AssetsDao.h"

//Player Init
bool Player::init(){

	if (!Character::init()){
		Character::init();
	}

	//Create Player Character
	player = new Character();
	player->setObjectType(OT_PLAYER);
	player->setName("player");
	setPlayerState(ALIVE);			//Set state to ALIVE

	//Read Player media from xml document
	player->loadMedia(player->getName());

	//set Player Position
	playerPosX = player->getPosX();
	playerPosY = player->getPosY();

	playerBoundingBox = new SDL_Rect();
	playerBoundingBox = player->getObjectBoundingBox();
	return true;
}


//Render Player
void Player::render(){

	player->render(playerPosX, playerPosY);

}




//Jump function sets player state to JUMP
void Player::jump(){
	setPlayerState(JUMPING);					//Set player State to JUMP

	playerPosY-= FORCE_UP * 10;

	player->setPositionY(playerPosY);

	player->getObjectBoundingBox()->y = playerPosY;
}

void Player::fallDown(){
	setPlayerState(FALLING);
	
	playerPosY+= FORCE_UP * 10;
	player->setPositionY(playerPosY);

	player->getObjectBoundingBox()->y = playerPosY;
}


//Boost function sets player state to BOOST
void Player::superSize(){
	setPlayerState(SUPERSIZE);					//set player state to SUPERSIZE
}





//Player update: updates player after input
void Player::update(){

}


//Handle Player movement
void Player::handleInput(SDL_Event& e){
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0){
		switch (e.key.keysym.sym){
		case SDLK_UP:
			jump();
			break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0){
		switch (e.key.keysym.sym){
		case SDLK_UP: 
			fallDown();
			break;
		}
	}
}


//Clean Up Function
void Player::cleanup(){
	player->cleanup();
}