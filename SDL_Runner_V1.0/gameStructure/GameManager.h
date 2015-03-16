#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include <iostream>
#include "LWindow.h"
#include "ScrollingBackground.h"
#include "CollisionManager.h"
#include "../sceneManagement/GameOverScene.h"

class GameManager{
public:
	static GameManager* getInstance();

	virtual bool init();	//Init method
	virtual void cleanup();	//Clean up everything
	virtual void render();	//Render
	
	void GameLoop();	//Gameloop
	bool running() { return mGameRunning; };

	int getGameWidth(){ return m_gameWidth; };
	int getGameHeight(){ return m_gameHeight; };

private:
	GameManager(){};	//Constructor
	~GameManager(){ this->cleanup(); };	//DeCOnstructor
	
	GameOverScene* gameOver;
	bool mGameRunning;

	ScrollingBackground* bg;
	Player* player;

	GameObject* ground;
	GameObject* playerBody;

	int m_gameWidth = GAME_WIDTH;
	int m_gameHeight = GAME_HEIGHT;

	bool collided;
};

#endif//_GAME_MANAGER_H_