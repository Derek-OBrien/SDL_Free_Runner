
#include "NPC.h"
#include "../dao/AssetsDao.h"

/*
	Npc Init function
	return bool
*/
bool Npc::init(){
	if (!Character::init()){
		Character::init();
	}
	return true;
}

/*
	Npc create()
	Create Npc Game Object
*/
void Npc::create(std::string npcName, int posX, int posY){

	npc = new Npc();

	npcBoundingBox = new SDL_Rect();
	npc->setObjectType(OT_OBSTICAL);
	ImageDetails npcDetails = AssetsDAO::getInstance()->readImageDetails(npcName);
	npc->setName(npcDetails.name);

	npc->loadMedia(npc->getName());
	npcPosX = posX;//npc->getPosX();
	npcPosY = posY;// npc->getPosY();

	//Set Object bounding Box
	npc->setObjectBoundingBox(npcPosX, npcPosY, npcDetails.spriteHeight, npcDetails.spriteWidth);

	npcBoundingBox = npc->getObjectBoundingBox();

}


/*
	Npc Render()
	Renders npc to the game scene
*/
void Npc::render(){
	npc->render(npcPosX, npcPosY);
}


/*
	Npc Update()
	Updates the Npc's Position on the Screen
*/
void Npc::update(){
	
	if (npc->getName() == "bird"){
		npcPosX -= FORCE_X * 0.8;
		npc->setPositionX(npcPosX);
		npc->getObjectBoundingBox()->x = npcPosX;
		
		//if it goes off screen release object
		if (npcPosX < 0){
			resetPosition();
		}
	}
	else if (npc->getName() == "bug"){
		npcPosX -= FORCE_X * 1.5;
		npc->setPositionX(npcPosX);
		npc->getObjectBoundingBox()->x = npcPosX;

		//if it goes off screen release object
		if (npcPosX < 0){
			resetPosition();
		}
	}
}

void Npc::resetPosition(){
	npcPosX = GAME_WIDTH + 1000;
	npc->setPositionX(npcPosX);
	npc->getObjectBoundingBox()->x = npcPosX;
}


void Npc::cleanup(){
	npc->~Character();
	npc->setObjectBoundingBox(NULL, NULL, NULL, NULL);

}