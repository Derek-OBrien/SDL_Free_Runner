/*
-		Derek O Brien K00105572
-		Player cpp file
*/

#include "Player.h"	//Include player header
#include "GameManager.h"

//Player Init
bool Player::init(){
	player = new GameObject();
	player->setObjectType(OT_PLAYER);

	setPlayerState(ALIVE);			//Set state to ALIVE

	player->setPos(100.0, 435);
	m_PlayerPosX = player->getPositionX();
	m_PlayerPosY = player->getPositionY();

	frame = 0;
	loadMedia();

	playerBoundingBox = player->getObjectBoundingBox();
	return true;
}

bool Player::loadMedia(){
	//Loading success flag
	bool success = true;

	//Load press texture
	if (!gSpriteSheetTexture.loadFromFile("../SDL_Runner_V1.0/assets/player_sprites/playerSprites.png")){
		printf("P: Failed to load Player sprite sheet texture texture!\n");
		success = false;
	}
	else{
		cout << "P: Player Loaded" << endl;


		int temp, x;
		x = 0;
		for (int i = 0; i < PLAYER_ANIMATION_FRAMES; i++){
			temp = 125;
			gSpriteClips[i].x = x;
			gSpriteClips[i].y = 0;
			gSpriteClips[i].w = 125;
			gSpriteClips[i].h = 125;

			x += temp;
		}

		//Set bounding box
		player->setObjectBoundingBox(100, 435, 125, 125);
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
	if (frame / 3 >= PLAYER_ANIMATION_FRAMES){
		frame = 0;
	}

	//Render Bounding Box
	SDL_SetRenderDrawColor(LWindow::getInstance()->getRenderer(), 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(LWindow::getInstance()->getRenderer(), playerBoundingBox);

}




//Jump function sets player state to JUMP
void Player::jump(){
	setPlayerState(JUMPING);					//Set player State to JUMP
	
	m_PlayerPosY -= FORCE_UP * 10;
	player->setPosY(m_PlayerPosY);

	playerBoundingBox->y = m_PlayerPosY;
}

void Player::fallDown(){
	setPlayerState(FALLING);
	
	m_PlayerPosY += FORCE_UP * 10;
	player->setPosY(m_PlayerPosY);

	playerBoundingBox->y = m_PlayerPosY;
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

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0){

		switch (e.key.keysym.sym){
		case SDLK_UP:
			//cout << "UP Pressed, Jump Active" << endl;
			jump();
			break;
		case SDLK_DOWN:
			break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym){
		case SDLK_UP: 
			fallDown();
			break;

		case SDLK_DOWN:
			break;
		}
	}
}


//Clean Up Function
void Player::cleanup(){
	gSpriteSheetTexture.cleanup();
}