/*
-		Derek O Brien K00105572
-		obstical cpp file

-       Sub class of Sprite
-       Has a runAI method to update logic (print statement “running AI for obstical”)
-       Has an update method (print statement “updating obstical”)
*/

#include "Obstical.h"
#include "LWindow.h"
#include "../dao/AssetsDao.h"

//Obstical init
bool Obstical::init(){
	obstical = new GameObject();
	obstical->setObjectType(OT_OBSTICAL);
	obstical->setName("obstical");
	obstical->setPos(GAME_WIDTH , 458);
	obstical->setName("crate");

	m_obsticalPosX = obstical->getPositionX();
	m_obsticalPosY = obstical->getPositionY();

	loadMedia();
	obsticalBoundingBox = obstical->getObjectBoundingBox();

	return true;
}


bool Obstical::loadMedia(){
	//Loading success flag
	bool success = true;
	Path imagepath = AssetsDAO::getInstance()->read(obstical->getName());
	std::string path = imagepath.getText();


	//Load press texture
	if (!gObsticalTexture.loadFromFile(path)){
		std::cout << "P: Failed to load Player sprite sheet texture texture!" <<std::endl;
		success = false;
	}
	else{
		std::cout << "O: Obstical Loaded\n" << std::endl;
	}

	//Set bounding box
	obstical->setObjectBoundingBox(m_obsticalPosX, m_obsticalPosY, 102, 102);
	return success;

}



//Render Obstical
void Obstical::render(){
	//Render background
	gObsticalTexture.render(obstical->getPositionX(), obstical->getPositionY(), 0);

	//Render Bounding Box
	SDL_SetRenderDrawColor(LWindow::getInstance()->getRenderer(), 0xff, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(LWindow::getInstance()->getRenderer(), obsticalBoundingBox);
}


//Obstical update: updates obstical postion
void Obstical::update(){

	m_obsticalPosX -= FORCE_X;
	obstical->setPosX(m_obsticalPosX);
	obsticalBoundingBox->x = m_obsticalPosX;

	//if it goes off screen reset to orignal position
	if (m_obsticalPosX < -GAME_WIDTH){
		m_obsticalPosX = GAME_WIDTH;
		obstical->setPosX(m_obsticalPosX);
		obsticalBoundingBox->x = m_obsticalPosX;
	}
}


//Obstical cleanup
void Obstical::cleanup(){
	gObsticalTexture.cleanup();
	obstical->cleanup();
}