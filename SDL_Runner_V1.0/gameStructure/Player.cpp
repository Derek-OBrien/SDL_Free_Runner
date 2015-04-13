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

	playerBoundingBox = new SDL_Rect();

	return true;
}

void Player::create(){
	//Check player init
	if (!init()){
		init();
	}

	//read in selected player sprite from xml file
	selectedPlayer = AssetsDAO::getInstance()->read("selected_player", "path", "assets");

	//load player sprite
	player->setName(selectedPlayer.getText());
	player->loadMedia(player->getName());

	//set Player Position
	playerPosX = player->getPosX();
	playerPosY = player->getPosY();

	//create player bounding bpx
	playerBoundingBox = player->getObjectBoundingBox();
}

//player Update
void Player::update(){}

//Render Player
void Player::render(){
	player->render(playerPosX, playerPosY);
}




/*
	Player Mechanics
*/
//Jump Mechanic
void Player::jump(){
	player->setName(selectedPlayer.getText() + "jump");
	player->loadMedia(player->getName());
	playerPosY-= FORCE_UP * 10;
	player->setPositionY(playerPosY);
	player->getObjectBoundingBox()->y = playerPosY;
}

void Player::fallDown(){
	playerPosY+= FORCE_UP * 10;
	player->setPositionY(playerPosY);
	player->getObjectBoundingBox()->y = playerPosY;	
}


//Slide Mechanic
void Player::slide(){
	player->setName(selectedPlayer.getText() + "slide");
	player->loadMedia(player->getName());
	playerPosY = player->getPosY();
}

//Player power up Mechanic
void Player::powerUp(){

	setPlayerState(POWERUP);	//set player state to POWERUP
	//Load Power Up Sprite
	player->setName(selectedPlayer.getText() + "powerup");
	player->loadMedia(player->getName());
	playerPosY = player->getPosY();

		
}



//Handle Player movement
void Player::handleInput(SDL_Event& e){
	//UP KEY
	//If a key was pressed
	//Check if in Power up as no jump/slide when in power up mode
	if (currentState != (int)POWERUP){
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
}


//Clean Up Function
void Player::cleanup(){
	player->~Sprite();
	player->setObjectBoundingBox(NULL, NULL, NULL, NULL);
}