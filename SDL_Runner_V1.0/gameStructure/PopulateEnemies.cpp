/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: PopulateEnemies.cpp
-

-		Popoulate vector of enemies and vector or collectables &
		Set their poistions
*/
#include "PopulateEnemies.h"

std::vector<Npc*> PopulateEnemies::populateBirdVector(){

	factory = new Factory();

birdVector.push_back(factory->createBirdNpc());
birdVector.push_back(factory->createBirdNpc());
birdVector.push_back(factory->createBirdNpc());
birdVector.push_back(factory->createBirdNpc());
birdVector.push_back(factory->createBirdNpc());

int size = birdVector.size();

for (int i = 0; i < size; i++){
	switch (i){
	case 0:
		npcX = GAME_WIDTH + (GAME_WIDTH *0.2);
		npcY = GAME_HEIGHT - 550;
		birdVector.at(i)->create("bird", npcX, npcY);
		break;
	case 1:
		npcX = GAME_WIDTH + (GAME_WIDTH *0.4);
		npcY = GAME_HEIGHT - 300;
		birdVector.at(i)->create("bird", npcX, npcY);
		break;
	case 2:
		npcX = GAME_WIDTH + (GAME_WIDTH*0.6);
		npcY = GAME_HEIGHT - 180;
		birdVector.at(i)->create("bird", npcX, npcY);
		break;
	case 3:
		npcX = GAME_WIDTH + (GAME_WIDTH*0.8);
		npcY = GAME_HEIGHT - 450;
		birdVector.at(i)->create("bird", npcX, npcY);
		break;
	case 4:
		npcX = GAME_WIDTH + (GAME_WIDTH);
		npcY = GAME_HEIGHT - 250;
		birdVector.at(i)->create("bird", npcX, npcY);
		break;
	case 5:
		npcX = GAME_WIDTH + (GAME_WIDTH);
		npcY = GAME_HEIGHT - 350;
		birdVector.at(i)->create("bird", npcX, npcY);
		break;
	default:
		break;
	}
}
return birdVector;
}



std::vector<Collectable*> PopulateEnemies::populateCollectVector(){
	factory = new Factory();

	coinVector.push_back(factory->createCollectable());
	coinVector.push_back(factory->createCollectable());
	coinVector.push_back(factory->createCollectable());
	coinVector.push_back(factory->createCollectable());
	coinVector.push_back(factory->createCollectable());

	for (int i = 0; i < (int)coinVector.size(); i++){

		switch (i){
		case 0:
			npcX = GAME_WIDTH + (GAME_WIDTH *0.2);
			npcY = GAME_HEIGHT - 450;
			coinVector.at(i)->create("coin", npcX, npcY);
			break;
		case 1:
			npcX = GAME_WIDTH + (GAME_WIDTH *0.2);
			npcY = GAME_HEIGHT - 500;;
			coinVector.at(i)->create("coin", npcX, npcY);
			break;
		case 2:
			npcX = GAME_WIDTH + (GAME_WIDTH*0.4);
			npcY = GAME_HEIGHT - 350;;
			coinVector.at(i)->create("coin", npcX, npcY);
			break;
		case 3:
			npcX = GAME_WIDTH + (GAME_WIDTH*0.4);///slideunder
			npcY = GAME_HEIGHT - 300;;
			coinVector.at(i)->create("coin", npcX, npcY);
			break;
		case 4:
			npcX = GAME_WIDTH + (GAME_WIDTH*0.6);///slide under
			npcY = GAME_HEIGHT - 250;;
			coinVector.at(i)->create("coin", npcX, npcY);
			break;
		case 5:
			npcX = GAME_WIDTH + (GAME_WIDTH*0.6);///slide under
			npcY = GAME_HEIGHT - 200;;
			coinVector.at(i)->create("coin", npcX, npcY);
			break;
		default:
			break;
		}
	}
	return coinVector;
}

void PopulateEnemies::update(int vel){
	for (int i = 0; i < (int)birdVector.size(); i++){
		birdVector.at(i)->update(vel);
	}
	for (int i = 0; i < (int)coinVector.size(); i++){
		coinVector.at(i)->update(vel);
	}
}

void PopulateEnemies::cleanup(){

	for (int i = 0; i <(int) birdVector.size(); i++){
		birdVector.at(i)->cleanup();
	}

	for (int i = 0; i < (int)coinVector.size(); i++){
		coinVector.at(i)->cleanup();
	}
	birdVector.clear();
	coinVector.clear();
}