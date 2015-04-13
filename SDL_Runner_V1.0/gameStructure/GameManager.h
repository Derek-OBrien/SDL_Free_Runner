#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include <iostream>
#include "LWindow.h"
#include "ScrollingBackground.h"
#include "CollisionManager.h"
#include "LTimer.h"
#include "HudLayer.h"
#include "PopulateEnemies.h"
#include "Collectable.h"

class GameManager{
public:
	static GameManager* getInstance();

	 bool init();			//Init 
	 void create();			//Create
	 void render();			//Render
	 void update();			//Update 
	 void handleInput();	//Handle input
	 void checkCollision();	//Check collision
	 void cleanup();		//Clean up everything

	 //Get timer
	 LTimer* getTimer() { return timer; };

private:
	GameManager(){};	//Constructor
	~GameManager(){ this->cleanup(); };	//DeCOnstructor

	bool collided;
	
	LTimer* timer;
	ScrollingBackground* bg_city;
	ScrollingBackground* bg;
	ScrollingBackground* fg;
	Player* player;
	HudLayer* hud;

	Collectable* shield;
	PopulateEnemies* popEnemies;
	std::vector<Npc*> birdVector;
	std::vector<Collectable*> coinVector;

};

#endif//_GAME_MANAGER_H_