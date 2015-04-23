#ifndef _LTIMER_H_
#define _LTIMER_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: LTimer.h
-

-		
*/
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <sstream>

class LTimer{
public:
	LTimer() { init(); };	//timer constructor
	~LTimer();

	
	bool init();	//init timere
	void create();	//create timer
	void start();	//start timer
	void stop();	//stop timer
	void pause();	//pause timer
	void unpause(); //unpause timer

	Uint32 getTime();	//get timer


	bool Started() { return isStarted; };
	bool Paused(){ return isPaused && isStarted; };

private:

	//clock time when started
	Uint32 startTime;

	//clock time when paused
	Uint32 pausedTime;

	//timer status
	bool isPaused;
	bool isStarted;
};


#endif//_LTIMER_H_