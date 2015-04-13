/*
-		Derek O Brien K00105572
-		Player cpp file
*/

#include "Player.h"	//Include player header
#include "GameManager.h"

//Player Init
bool Player::init(){

	if (!Character::init()){
		Character::init();
	}

	//Create Player Character
	player = new Character();
	player->setObjectType(OT_PLAYER);
	setPlayerState(ALIVE);			//Set state to ALIVE
	
	selectedPlayer = AssetsDAO::getInstance()->read("selected_player", "path", "assets");

	player->setName(selectedPlayer.getText());

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
	//setPlayerState(JUMPING);					//Set player State to JUMP
	player->setName("player2jump");
	player->loadMedia(player->getName());
	playerPosY-= FORCE_UP * 10;
	player->setPositionY(playerPosY);
	player->getObjectBoundingBox()->y = playerPosY;
}

void Player::fallDown(){
	//setPlayerState(FALLING);
	playerPosY+= FORCE_UP * 10;
	player->setPositionY(playerPosY);
	player->getObjectBoundingBox()->y = playerPosY;	
}

void Player::slide(){
	player->setName("player2slide");
	player->loadMedia(player->getName());
	playerPosY = player->getPosY();
}


//Boost function sets player state to BOOST
void Player::powerUp(){
	powerUpTime = 5000;
	setPlayerState(POWERUP);	//set player state to SUPERSIZE

	while (powerUpTime > 0){
		FORCE_X * 2;
		powerUpTime--;
	}
	setPlayerState(ALIVE);
}





//Player update: updates player after input
void Player::update(){

}


//Handle Player movement
void Player::handleInput(SDL_Event& e){
	//UP KEY
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0){
		switch (e.key.keysym.sym){
		case SDLK_UP:	//Up key pressed
			jump();
			break;

		case SDLK_DOWN:	//Down Key Pressed
			slide();
			break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0){
		switch (e.key.keysym.sym){
		case SDLK_UP:		//Up key Released
			fallDown();
			player->setName(selectedPlayer.getText());
			player->loadMedia(player->getName());
			break;

		case SDLK_DOWN:		//Down key Released
			player->setName(selectedPlayer.getText());
			player->loadMedia(player->getName());
			playerPosY = player->getPosY();

			break;
		}
	}
}


//Clean Up Function
void Player::cleanup(){
	player->cleanup();
}