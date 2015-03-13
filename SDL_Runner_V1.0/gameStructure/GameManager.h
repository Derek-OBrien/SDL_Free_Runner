#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include <iostream>
#include "ScrollingBackground.h"
#include "CollisionManager.h"

class GameManager{
public:
	static GameManager* getInstance();

	virtual bool init(const char* title, int posX, int posY, int height, int width, int flag);	//Init method
	virtual void cleanup();	//Clean up everything
	virtual void render();	//Render

	SDL_Window* getWindow() const { return m_pWindow; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	
	void GameLoop();	//Gameloop
	bool running() { return mGameRunning; };

	int getGameWidth(){ return m_gameWidth; };
	int getGameHeight(){ return m_gameHeight; };

private:
	GameManager(){};	//Constructor
	~GameManager(){ this->cleanup(); };	//DeCOnstructor
	
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool mGameRunning;

	ScrollingBackground* bg;
	Player* player;

	
	int m_gameWidth = GAME_WIDTH;
	int m_gameHeight = GAME_HEIGHT;
};

#endif//_GAME_MANAGER_H_