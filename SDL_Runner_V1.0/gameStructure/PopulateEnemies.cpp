
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
		npcY = 250;
		birdVector.at(i)->create("bird", npcX, npcY);
		break;
	case 1:
		npcX = GAME_WIDTH + (GAME_WIDTH *0.4);
		npcY = 300;
		birdVector.at(i)->create("bird", npcX, npcY);
		break;
	case 2:
		npcX = GAME_WIDTH + (GAME_WIDTH*0.6);
		npcY = 370;
		birdVector.at(i)->create("bird", npcX, npcY);
		break;
	case 3:
		npcX = GAME_WIDTH + (GAME_WIDTH*0.1);///slideunder
		npcY = 450;
		birdVector.at(i)->create("bird", npcX, npcY);
		break;
	case 4:
		npcX = GAME_WIDTH + (GAME_WIDTH*0.7);///slide under
		npcY = 450;
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

	int offsetX = 50;
	int offsetY = 50;
	for (int i = 0; i < (int)coinVector.size(); i++){

		switch (i){
		case 0:
			npcX = GAME_WIDTH + (GAME_WIDTH *0.2);
			npcY = 50;
			coinVector.at(i)->create("coin", npcX, npcY);
			break;
		case 1:
			npcX = GAME_WIDTH + (GAME_WIDTH *0.4);
			npcY = 50;
			coinVector.at(i)->create("coin", npcX, npcY);
			break;
		case 2:
			npcX = GAME_WIDTH + (GAME_WIDTH*0.6);
			npcY = 50;
			coinVector.at(i)->create("coin", npcX, npcY);
			break;
		case 3:
			npcX = GAME_WIDTH + (GAME_WIDTH*0.1);///slideunder
			npcY = 50;
			coinVector.at(i)->create("coin", npcX, npcY);
			break;
		case 4:
			npcX = GAME_WIDTH + (GAME_WIDTH*0.7);///slide under
			npcY = 50;
			coinVector.at(i)->create("coin", npcX, npcY);
			break;
		default:
			break;
		}
	}
	return coinVector;
}

void PopulateEnemies::update(){
	for (int i = 0; i < (int)birdVector.size(); i++){
		birdVector.at(i)->update();
	}
	for (int i = 0; i < (int)coinVector.size(); i++){
		coinVector.at(i)->update();
	}

	if ((int)coinVector.size() == 0){
		coinVector = populateCollectVector();
	}
}

void PopulateEnemies::cleanup(){

	for (int i = 0; i <(int) birdVector.size(); i++){
		birdVector.at(i)->cleanup();
	}
}