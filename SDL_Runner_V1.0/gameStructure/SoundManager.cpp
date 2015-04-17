/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: SoundManager.cpp
-

-
*/
#include "SoundManager.h"
#include "../dao/AssetsDao.h"

//Create as Singleton
static SoundManager *instance = 0;
SoundManager* SoundManager::getInstance(){
	if (instance == 0){
		instance = new SoundManager();
	}
	return instance;
}

//Constructor
SoundManager::SoundManager(){
	Mix_OpenAudio(22050, AUDIO_S16, 2, (4096 / 2));
}

//init
bool SoundManager::init(){
	bgMusic = NULL;
	Sfx = NULL;
	return true;
}


//Load Audio 
bool SoundManager::loadAudio(std::string audio, audio_type type){

	bool success = true;
	Path audioPath = AssetsDAO::getInstance()->read(audio, "path", "assets");
	//Load bg Audio
	if (type == BG_MUSIC){
		bgMusic = Mix_LoadMUS(audioPath.getText().c_str());
		if (bgMusic == NULL){
			std::cout << "Failed to Load bg audio  \n" << Mix_GetError() << std::endl;
			success = false;
		}
	}
	//Load Sfx Audio
	else if (type == SFX_MUSIC){
		Sfx = Mix_LoadWAV(audioPath.getText().c_str());
		if (bgMusic == NULL){
			std::cout << "Failed to Load sfx audio \n" << Mix_GetError() << std::endl;
			success = false;
		}
	}


	return success;
}

//Play Bg Music
void SoundManager::playMusic(){

	//If music not playing
	if (Mix_PlayingMusic() == 0){
		//play music
		Mix_PlayMusic(bgMusic, -1);
	}
	else{
		//if music is paused
		if (Mix_PausedMusic() == 1){
			resumeMusic();//resume
		}
		else{
			//pause Music
			pauseMusic();
		}
	}
}


//Play Sfx Music
void SoundManager::playSfx(std::string sfxTrack){
	loadAudio(sfxTrack, SFX_MUSIC);
	Mix_PlayChannel(-1, Sfx, 0);
}