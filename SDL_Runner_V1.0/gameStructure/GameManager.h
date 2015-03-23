#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include <iostream>
#include "LWindow.h"
#include "ScrollingBackground.h"
#include "CollisionManager.h"


class GameManager{
public:
	static GameManager* getInstance();

	 bool init();			//Init 
	 void render();			//Render
	 void update();			//Update 
	 void handleInput();	//Handle input
	 void checkCollision();	//Check collision
	 void cleanup();		//Clean up everything


private:
	GameManager(){};	//Constructor
	~GameManager(){ this->cleanup(); };	//DeCOnstructor
	

	ScrollingBackground* bg;
	Player* player;
	Obstical* obstical;

//	GameObject* ground;
//	GameObject* playerBody;
//	GameObject* obsticalBody;


	bool collided;
};

#endif//_GAME_MANAGER_H_