/*
-          Is the main controller
-          Gets a pointer to a vector of enemies from the worldmanager
-          Gets a pointer to the player from the worldmanager
-          Has the main update method which does the following

Calls the player update
Calls each enemy’s  update
Calls each enemy’s runAI
Calls the collision manager to check collisions
Print statement (“render”)
*/

#include "GameManager.h"	//Include game manager header

GameManager* GameManagerInstance = 0;//instance of the object to be used
GameManager* GameManager::getInstance(){
	if (GameManagerInstance == 0){						//if the instance is null
		GameManagerInstance = new GameManager();		//create the instance 
	}													//otherwise
	return GameManagerInstance;						//return the instance
}


//init game manager
bool GameManager::init(const char* title, int posX, int posY, int height, int width, int flag){
	//Init SDL, Create SDL Window, Create SDL Renderer
	if (SDL_Init(SDL_INIT_VIDEO) == 0){
		std::cout << "SDL init success" << std::endl;
		m_pWindow = SDL_CreateWindow(title, posX, posY, width, height, flag);

		if (m_pWindow != 0) {
			std::cout << "Window created success" << std::endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

			if (m_pRenderer != 0){
				std::cout << "Renderer creation success" << std::endl;
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			}
			else { std::cout << "Renderer create fail" << std::endl; return false; }
		}
		else { std::cout << "Window create fail" << std::endl; return false; }
	}
	else{ std::cout << "SDL init fail" << std::endl; return false; }

	mGameRunning = true;


	bg = new ScrollingBackground();
	player = new Player();	//Constructor Calls player->init();

	GameLoop();//call update loop
	return true;
}

//Game manager gameloop
void GameManager::GameLoop(){
	
	bool quit = false;
	SDL_Event e;	//Event handler
	while (!quit){ //Run Main Loop untill player quits
		//std::cout << "Game Manager Running!!! :)\n" << std::endl;

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0){
			//User requests quit
			if (e.type == SDL_QUIT){
				quit = true;
			}
			//Handle input for the Player
			player->handleInput(e);
		}

		//Clear Screen 
		SDL_SetRenderDrawColor(getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(getRenderer());
		
		
		//Render everything
		render();
		SDL_RenderPresent(getRenderer());

		//Call each obstical’s update
		bg->update();
		player->update();

		//Call the collision manager to check collisions



	}
	//Call deconstructor to clean up 
	cleanup();
}

void GameManager::render(){
	bg->render();
	player->render();
}


//Clean up Everything 
void GameManager::cleanup(){
	player->cleanup();
	bg->cleanup();

	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}
