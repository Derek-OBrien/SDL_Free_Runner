
#include "Button.h"
#include "../dao/AssetsDao.h"
#include "LWindow.h"
#include "../sceneManagement/SceneManager.h"
#include "../sceneManagement/MenuScene.h"
#include "GameManager.h"
#include "SoundManager.h"


//Button init
bool Button::init(){

	GameObject::init();
	SoundManager::getInstance()->init();
	return true;
}

//Create button
void Button::create(std::string name){

	if (!init()){
		init();
	}
	currentButtonState = NORMAL;
	setButtonState(currentButtonState);

	loadmedia(name);
}


bool Button::loadmedia(std::string name){
	bool success = true;

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



//Button Render
void Button::render(std::string name){
	currentFrame = &gSpriteClips[(int)currentButtonState];
	buttonTexture.render(buttonDetails.posX, buttonDetails.posY, currentFrame);
}


void Button::handleMouseEvent(SDL_Event* e){

	Scene* scene = SceneManager::getInstance()->getCurrentScene();

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
			case SDL_MOUSEMOTION:
				currentButtonState = HOVER;
				break;

			case SDL_MOUSEBUTTONDOWN:
				currentButtonState = PRESSED;

				if (buttonDetails.name == "player1btn"){
					SoundManager::getInstance()->playSfx("sfx");
					//Save selected Player & Destroy scene
					AssetsDAO::getInstance()->update("player1", "path", "assets");
					scene->setSceneState(DESTROY);
				}

				else if (buttonDetails.name == "player2btn"){
					SoundManager::getInstance()->playSfx("sfx");

					//Save selected Player & Destroy scene
					AssetsDAO::getInstance()->update("player2", "path", "assets");
					scene->setSceneState(DESTROY);
				}
				//Pause Button 
				else if (buttonDetails.name == "pausebutton"){
					SoundManager::getInstance()->playSfx("sfx");
					
					if (GameManager::getInstance()->getTimer()->Paused()){
						GameManager::getInstance()->getTimer()->unpause();
						SoundManager::getInstance()->resumeMusic();

						scene->setSceneState(RUNNING);
					}
					else{
						SoundManager::getInstance()->pauseMusic();

						scene->setSceneState(PAUSED);
						GameManager::getInstance()->getTimer()->pause();
					}
				}
				//Close Button
				else if (buttonDetails.name == "closebutton"){
					SoundManager::getInstance()->playSfx("sfx");

					cleanup();
					SDL_Quit();
					LWindow::getInstance()->cleanup();
				}

				else if (buttonDetails.name == "restart"){
					SoundManager::getInstance()->playSfx("sfx");

					MenuScene* nextScene = new MenuScene();
					SceneManager::getInstance()->runwithscene(nextScene);
				}
				break;

			case SDL_MOUSEBUTTONUP:
				currentButtonState = NORMAL;
				break;
			}

		}
	}
}

//Button Cleanup
void Button::cleanup(){
	buttonTexture.cleanup();
}