/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Button.cpp
-

-		Button Class
-		Controls all button states, and input from user
*/
//Inludes
#include "Button.h"
#include "../dao/AssetsDao.h"
#include "../sceneManagement/SceneManager.h"
#include "../sceneManagement/MenuScene.h"
#include "LWindow.h"
#include "GameManager.h"
#include "SoundManager.h"


//Button init
bool Button::init(){
	//Super init
	if (!Sprite::init()){
		Sprite::init();
	}
	//Init Sound Manager
	SoundManager::getInstance()->init();
	return true;
}

//Create button
void Button::create(std::string name){
	//Check if Button init complete 
	if (!init()){
		init();
	}
	//Set state
	currentButtonState = NORMAL;
	setButtonState(currentButtonState);
	
	//Load button media
	loadmedia(name);
}

/*
	Load Button meida from Xml File
	@retutn bool
*/
bool Button::loadmedia(std::string name){
	bool success = true;

	//get button details from Xml file
	buttonDetails = AssetsDAO::getInstance()->readImageDetails(name);
	std::string imagepath = buttonDetails.pathToFile;

	//Load texture
	if (!buttonTexture.loadFromFile(imagepath)){
		std::cout << "B: Failed to load Button for : " << name << std::endl;
		success = false;
	}
	else{
		std::cout << "B: Button Loaded for : " << name << std::endl;

		int temp, offsetX, size;
		offsetX = 0;
		size = buttonDetails.frames;
		temp = buttonDetails.offsetX;
		//Fill ButtonDetails from details read in
		for (int i = 0; i < size; i++){
			gSpriteClips[i].x = offsetX;
			gSpriteClips[i].y = buttonDetails.offsetY;
			gSpriteClips[i].w = buttonDetails.spriteWidth;
			gSpriteClips[i].h = buttonDetails.spriteHeight;

			offsetX += temp;
		}
	}
	return success;
}



/*
	Redner Button to Screen
*/
void Button::render(std::string name){
	currentFrame = &gSpriteClips[(int)currentButtonState];
	buttonTexture.render(buttonDetails.posX, buttonDetails.posY, currentFrame);
}

/*
	Handle All Input for all Buttons
*/
void Button::handleMouseEvent(SDL_Event* e){

	//Get Current Scene
	Scene* scene = SceneManager::getInstance()->getCurrentScene();

	//Mouse Input
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP){

		//Mouse Position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//Check if mouse inside button area
		bool inside = true;

		//Check if mouse inside button
		if (x < buttonDetails.posX){
			inside = false;
		}
		else if (x > buttonDetails.posX + buttonDetails.spriteWidth){
			inside = false;
		}
		else if (y < buttonDetails.posY){
			inside = false;
		}
		else if (y > buttonDetails.posY + buttonDetails.spriteHeight){
			inside = false;
		}

		//If mouse outside buttton
		if (!inside){
			currentButtonState = NORMAL;
		}
		//if mouse is inside button
		else{
			switch (e->type){
			case SDL_MOUSEMOTION:	//If mouse is over button
				currentButtonState = HOVER;
				break;

			case SDL_MOUSEBUTTONDOWN:	//If mouse button porssed
				currentButtonState = PRESSED;
				
				//Select Player Button 1
				if (buttonDetails.name == "player1btn"){
					SoundManager::getInstance()->playSfx("buttonPress");
				
					//Save selected Player & Destroy scene
					AssetsDAO::getInstance()->update("player1", "path", "assets");
					scene->setSceneState(DESTROY);
				}
				//Select Player Button 2
				else if (buttonDetails.name == "player2btn"){
					SoundManager::getInstance()->playSfx("buttonPress");

					//Save selected Player & Destroy scene
					AssetsDAO::getInstance()->update("player2", "path", "assets");
					scene->setSceneState(DESTROY);
				}

				//Pause Button 
				else if (buttonDetails.name == "pausebutton"){
					SoundManager::getInstance()->playSfx("buttonPress");
					
					//If Game Paused Un-Pause
					if (GameManager::getInstance()->getTimer()->Paused()){
						GameManager::getInstance()->getTimer()->unpause();
						SoundManager::getInstance()->resumeMusic();

						scene->setSceneState(RUNNING);
					}
					//Pause
					else{
						SoundManager::getInstance()->pauseMusic();

						scene->setSceneState(PAUSED);
						GameManager::getInstance()->getTimer()->pause();
					}
				}
				//Close Button
				else if (buttonDetails.name == "closebutton"){
					SoundManager::getInstance()->playSfx("buttonPress");

					cleanup();
					SDL_Quit();
					LWindow::getInstance()->cleanup();
					GameManager::getInstance()->cleanup();
					
				}

				//Restart Button (Return to Player Select)
				else if (buttonDetails.name == "restart"){
					SoundManager::getInstance()->playSfx("buttonPress");

					MenuScene* nextScene = new MenuScene();
					SceneManager::getInstance()->runwithscene(nextScene);
				}
				break;

			case SDL_MOUSEBUTTONUP:	//If mouse button not pressed
				currentButtonState = NORMAL;
				break;
			}

		}
	}
}

//Button Cleanup
void Button::cleanup(){
	buttonTexture.cleanup();
	Sprite::cleanup();
}