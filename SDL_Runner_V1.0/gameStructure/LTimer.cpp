
#include "LTimer.h"

//Init Timer 
bool LTimer::init(){

	isStarted = false;
	isPaused = false;

	startTime = 0;
	pausedTime = 0;

	return true;
}

//Create timer and start 
void LTimer::create(){

	if (!init()){
		init();
	}

	start();
}

//Start Timer
void LTimer::start(){

	isStarted = true;
	isPaused = false;

	startTime = SDL_GetTicks();
	pausedTime = 0;
}

//Stop Timer
void LTimer::stop(){

	isStarted = false;
	isPaused = false;

	startTime = 0;
	pausedTime = 0;
}

//Pause Timer
void LTimer::pause(){

	if (isStarted && !isPaused){
		isPaused = true;

		pausedTime = SDL_GetTicks() - startTime;
		startTime = 0;
	}
}

//UnPause Timer
void LTimer::unpause(){

	if (isStarted && isPaused){
		isPaused = false;

		startTime = SDL_GetTicks() - pausedTime;

		pausedTime = 0;
	}
}


//Get Time
Uint32 LTimer::getTime(){

	Uint32 time = 0;

	if (isStarted){
		if (isPaused){
			time = pausedTime;
		}
		else{
			time = SDL_GetTicks() - startTime;
		}
	}
	return time;
}
