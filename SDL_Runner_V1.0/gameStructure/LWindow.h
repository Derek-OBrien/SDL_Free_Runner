#ifndef _LOAD_WINDOW_H_
#define _LOAD_WINDOW_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: LWindow.h
-

-		
*/
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "GameDefines.h"

class LWindow {
public:
	static LWindow* getInstance();

	bool init(const char* title, int posX, int posY, int height, int width, int flag);	//Init method
	void cleanup();

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	LWindow(){ };
	~LWindow(){ cleanup(); };
};


#endif//_LOAD_WINDOW_H_