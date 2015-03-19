/*
-		Derek O Brien K00105572
-		Player cpp file
*/

#include "Player.h"	//Include player header
#include "GameManager.h"
#include "../dao/AssetsDao.h"

//Player Init
bool Player::init(){
	player = new GameObject();
	player->setObjectType(OT_PLAYER);
	player->setName("player");
	setPlayerState(ALIVE);			//Set state to ALIVE

	//Set Player Position
	player->setPos(100, 435);
	m_PlayerPosX = player->getPositionX();
	m_PlayerPosY = player->getPositionY();

	//Read Player media from xml document
	//spriteAnimation = new SpriteAnimation();
	spriteAnimation = AssetsDAO::getInstance()->readSpriteAnimation(player->getName());
	frame = 0;
	loadMedia();

	playerBoundingBox = player->getObjectBoundingBox();
	return true;
}

bool Player::loadMedia(){
	//Loading success flag
	bool success = true;
	
	std::string imagepath = spriteAnimation.pathToFile;
	std::cout << "Path to player" << imagepath << std::endl;
	//Load texture
	if (!gSpriteSheetTexture.loadFromFile(imagepath)){
		std::cout <<"P: Failed to load Player sprite sheet texture texture!" << std::endl;
		success = false;
	}
	else{
		std::cout << "P: Player Loaded" << std::endl;


		int temp, x;
		x = 0;
		for (int i = 0; i < spriteAnimation.frames; i++){
			temp = spriteAnimation.offsetX;
			gSpriteClips[i].x = x;
			gSpriteClips[i].y = spriteAnimation.offsetY;
			gSpriteClips[i].w = spriteAnimation.spriteWidth;
			gSpriteClips[i].h = spriteAnimation.spriteHeight;

			x += temp;
		}

		//Set bounding box
		player->setObjectBoundingBox(m_PlayerPosX, m_PlayerPosY, 125, 125);
	}

	return success;
}


//Render Player
void Player::render(){

	currentFrame = &gSpriteClips[frame / 3];
	gSpriteSheetTexture.render(player->getPositionX(), player->getPositionY(), currentFrame);

	SDL_RenderPresent(LWindow::getInstance()->getRenderer());
	++frame;

	//Cycle animation
	if (frame / 3 >= spriteAnimation.frames){
		frame = 0;
	}

	//Render Bounding Box
	SDL_SetRenderDrawColor(LWindow::getInstance()->getRenderer(), 0xff, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(LWindow::getInstance()->getRenderer(), playerBoundingBox);

}




//Jump function sets player state to JUMP
void Player::jump(){
	setPlayerState(JUMPING);					//Set player State to JUMP
	
	m_PlayerPosY -= FORCE_UP * 10;
	player->setPosY(m_PlayerPosY);

	playerBoundingBox->y = m_PlayerPosY;	//update bounding box pos
}

void Player::fallDown(){
	setPlayerState(FALLING);
	
	m_PlayerPosY += FORCE_UP * 10;
	player->setPosY(m_PlayerPosY);

	playerBoundingBox->y = m_PlayerPosY;	//update bounding box pos
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
			//std::cout << "UP Pressed, Jump Active" << std::endl;
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
	gSpriteSheetTexture.cleanup();
}