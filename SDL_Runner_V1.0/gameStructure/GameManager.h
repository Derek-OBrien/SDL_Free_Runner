#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "CollisionManager.h"
#include "LoadWindowManager.h"

class GameManager{
public:
	GameManager(){ this->init(); };	//Constructor
	~GameManager(){ this->cleanup(); };	//DeCOnstructor

	virtual bool init();	//Init method
	virtual void cleanup();

	void GameLoop();	//Gameloop
	bool running() { return mGameRunning; };
private:
	
	LoadWindowManager* loadWindow;
	bool mGameRunning;
};

#endif//_GAME_MANAGER_H_