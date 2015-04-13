
# include "LWindow.h"
#include <SDL_ttf.h>
#include <SDL_mixer.h>

static LWindow *instance = 0;
LWindow* LWindow::getInstance(){
	if (instance == 0){
		instance = new LWindow();
	}
	return instance;
}

/*
		Create window and inti sdl Elemnts
*/
bool LWindow::init(const char* title, int posX, int posY, int height, int width, int flag){
	//Init SDL Video
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == 0){
		std::cout << "SDL init success" << std::endl;
		//create window
		m_pWindow = SDL_CreateWindow(title, posX, posY, width, height, flag);
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")){
			printf("Warning: Linear texture filtering not enabled!");
		}
		//Initialize SDL_ttf
		if (TTF_Init() == 0){
			std::cout << "TTF init complete" << std::endl;
			if (m_pWindow != 0) {
				std::cout << "Window created success" << std::endl;
				//Create SDL Renderer
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
				if (m_pRenderer != 0){
					std::cout << "Renderer creation success" << std::endl;
					SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
					int imgFlags = IMG_INIT_PNG;
					if (!(IMG_Init(imgFlags) & imgFlags))
					{
						printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					}
					if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
					{
						printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					}
				}
				else { std::cout << "Renderer create fail" << std::endl; return false; }
			}
			else { std::cout << "Window create fail" << std::endl; return false; }
		}
		else { std::cout << "TTF Init failed: " << TTF_GetError() << std::endl; }
	}
	else{ std::cout << "SDL init fail" << std::endl; return false; }

	return true;
}

//Clean up Window
void LWindow::cleanup(){
	SDL_DestroyRenderer(m_pRenderer);	//Move to Game over Scene
	SDL_DestroyWindow(m_pWindow);		//Move to Game over Scene
	TTF_Quit();
	SDL_Quit();
}