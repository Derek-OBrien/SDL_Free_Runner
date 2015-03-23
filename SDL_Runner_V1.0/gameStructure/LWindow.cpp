
# include "LWindow.h"

static LWindow *instance = 0;

LWindow* LWindow::getInstance(){
	if (instance == 0){
		instance = new LWindow();
	}
	return instance;
}


bool LWindow::init(const char* title, int posX, int posY, int height, int width, int flag){
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

	return true;
}

void LWindow::cleanup(){

	SDL_DestroyRenderer(m_pRenderer);	//Move to Game over Scene
	SDL_DestroyWindow(m_pWindow);		//Move to Game over Scene

	SDL_Quit();
}