/*
-		Derek O Brien K00105572
-		Player cpp file
*/

#include "Player.h"	//Include player header
#include "GameManager.h"

//Player Init
bool Player::init(){
	setObjectType(OT_PLAYER);
	setPlayerState(ALIVE);			//Set state to ALIVE
	player = new GameObject();

	player->setPos(100.0, 240.0);
	m_PosX = player->getPositionX();
	m_PosY = player->getPositionY();

	frame = 0;
	loadMedia();

	return true;
}

bool Player::loadMedia(){
	//Loading success flag
	bool success = true;

	//Load press texture
	if (!gSpriteSheetTexture.loadFromFile("../SDL_Runner_V1.0/assets/player_sprites/spriteSheet.png")){
		printf("P: Failed to load Player sprite sheet texture texture!\n");
		success = false;
	}
	else{
		cout << "P: Player Loaded" << endl;

		int temp, x;
		x = 0;
		for (int i = 0; i < PLAYER_ANIMATION_FRAMES; i++){
			temp = 200;
			gSpriteClips[i].x = x;
			gSpriteClips[i].y = 0;
			gSpriteClips[i].w = 200;
			gSpriteClips[i].h = 200;

			x += temp;
		}
	}

	return success;
}


//Render Player
void Player::render(){
	//cout << "P: Player Sprite is been Rendered" << endl;

	currentFrame = &gSpriteClips[frame / 4];
	gSpriteSheetTexture.render(player->getPositionX(), player->getPositionY(), currentFrame);

	SDL_RenderPresent(GameManager::getInstance()->getRenderer());
	++frame;

	//Cycle animation
	if (frame / 4 >= PLAYER_ANIMATION_FRAMES){
		frame = 0;
	}
}




//Jump function sets player state to JUMP
void Player::jump(){
	setPlayerState(JUMPING);					//Set player State to JUMP
	
	m_PosY -= FORCE_UP;
	player->setPosY(m_PosY);
}

void Player::fallDown(){
	setPlayerState(FALLING);
	
	m_PosY += FORCE_UP;
	player->setPosY(m_PosY);
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

	if (e.type == SDL_KEYDOWN ){

		switch (e.key.keysym.sym){
		case SDLK_UP:
			cout << "UP Pressed, Jump Active" << endl;
			jump();
			break;
		case SDLK_DOWN:
			cout << "Down Pressed, Down Active" << endl;
			fallDown();
			break;
		case SDLK_LEFT:
			break;
		case SDLK_RIGHT:
			break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: 
			setPosY(240);
			break;
		case SDLK_DOWN:
			break;
		case SDLK_LEFT:
			break;
		case SDLK_RIGHT:
			break;
		}
	}
}


//Clean Up Function
void Player::cleanup(){
	gSpriteSheetTexture.cleanup();
}