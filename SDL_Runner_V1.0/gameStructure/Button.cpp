
#include "Button.h"
#include "../dao/AssetsDao.h"
#include "LWindow.h"
#include "../sceneManagement/SceneManager.h"
#include "GameManager.h"


//Button init
bool Button::init(){

	GameObject::init();

	return true;
}

//Create button
void Button::create(std::string name){

	if (!init()){
		init();
	}

	currentButtonState = (ButtonState)buttonDetails.state;
	setButtonState(currentButtonState);

	loadmedia(name);
}


bool Button::loadmedia(std::string name){
	bool success = true;

	buttonDetails = AssetsDAO::getInstance()->readButtonDetails(name);
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
			gSpriteClips[i].w = buttonDetails.width;
			gSpriteClips[i].h = buttonDetails.height;

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
		else if (x > buttonDetails.posX + buttonDetails.width){
			inside = false;
		}
		else if (y < buttonDetails.posY){
			inside = false;
		}
		else if (y > buttonDetails.posY + buttonDetails.height){
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

					//Save selected Player & Destroy scene
					AssetsDAO::getInstance()->update("player1");
					scene->setSceneState(DESTROY);
				}

				else if (buttonDetails.name == "player2btn"){

					//Save selected Player & Destroy scene
					AssetsDAO::getInstance()->update("player2");
					scene->setSceneState(DESTROY);
				}
				//Pause Button 
				else if (buttonDetails.name == "pausebutton"){
					std::cout << "Pause Button Pressed" << std::endl;					
					if (GameManager::getInstance()->getTimer()->Paused()){
						GameManager::getInstance()->getTimer()->unpause();
						scene->setSceneState(RUNNING);
					}
					else{
						scene->setSceneState(PAUSED);
						GameManager::getInstance()->getTimer()->pause();
						Path path = AssetsDAO::getInstance()->read("pause");
						//bg->create(path.getText());
						//bg->render();
						//SDL_RenderPresent(LWindow::getInstance()->getRenderer());
					}
				}
				//Close Button
				else if (buttonDetails.name == "closebutton"){
					cleanup();
					SDL_Quit();
					LWindow::getInstance()->cleanup();
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