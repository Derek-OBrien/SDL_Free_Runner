/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Npc.cpp
-

-		
*/
#include "NPC.h"

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

	//Create npc and npc bounding box
	npc = new Character();
	npcBoundingBox = new SDL_Rect();
	npc->setObjectType(OT_OBSTICAL);
	
	//get Npc Details
	npc->setName(npcName);
	npc->loadMedia(npc->getName());

	//Set position
	npcPosX = posX;//npc->getPosX();
	npcPosY = posY;// npc->getPosY();

	//Set Object bounding Box
	npc->setObjectBoundingBox(npcPosX, npcPosY, npc->getObjectBoundingBox()->h, npc->getObjectBoundingBox()->w);
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
	//Update bird npc position
	if (npc->getName() == "bird"){
		npcPosX -= FORCE_X * 0.8;
		npc->setPositionX(npcPosX);
		npc->getObjectBoundingBox()->x = npcPosX;
		
		//if it goes off screen reset object
		if (npcPosX < 0){
			resetPosition();
		}
	}
}

//Reset npc position
void Npc::resetPosition(){
	npcPosX = GAME_WIDTH + 100;
	npc->setPositionX(npcPosX);
	npc->getObjectBoundingBox()->x = npcPosX;
}

//Clean up Npc
void Npc::cleanup(){
	npc->~Character();
	npc->setObjectBoundingBox(NULL, NULL, NULL, NULL);
}


