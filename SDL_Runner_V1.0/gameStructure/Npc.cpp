
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
void Npc::create(std::string npcName){

	npc = new Npc();

	npcBoundingBox = new SDL_Rect();
	npc->setObjectType(OT_OBSTICAL);
	ImageDetails npcDetails = AssetsDAO::getInstance()->readImageDetails(npcName);
	npc->setName(npcDetails.name);

	npc->loadMedia(npc->getName());
	npcPosX = npc->getPosX();
	npcPosY = npc->getPosY();
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
		
		//if it goes off screen reset to orignal position
		if (npcPosX < 0){
			npcPosX = GAME_WIDTH;
			npc->setPositionX(npcPosX);
			npc->getObjectBoundingBox()->x = npcPosX;
		}
	}
	else if (npc->getName() == "bug"){
		npcPosX -= FORCE_X * 0.4;
		npc->setPositionX(npcPosX);
		npc->getObjectBoundingBox()->x = npcPosX;

		//if it goes off screen reset to orignal position
		if (npcPosX < 0){
			npcPosX = GAME_WIDTH;
			npc->setPositionX(npcPosX);
			npc->getObjectBoundingBox()->x = npcPosX;
		}
	}
}