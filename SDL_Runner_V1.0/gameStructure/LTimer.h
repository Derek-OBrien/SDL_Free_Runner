#ifndef _LTIMER_H_
#define _LTIMER_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>

class LTimer{
public:
	LTimer() { init(); };
	~LTimer();

	
	bool init();
	void create();
	void start();
	void stop();
	void pause();
	void unpause();

	Uint32 getTime();


	bool Started() { return isStarted; };
	bool Paused(){ return isPaused && isStarted; };

private:

	//clock time when started
	Uint32 startTime;

	//closk time when paused
	Uint32 pausedTime;

	//timer status
	bool isPaused;
	bool isStarted;
};


#endif//_LTIMER_H_