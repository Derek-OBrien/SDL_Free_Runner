#ifndef _SoundManager_H_
#define _SoundManager_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: SoundManager.h
-

-		Soundmanager Class Handles all sound in game
*/
#include <iostream>
#include <map>
#include <string>
#include "SDL_mixer.h"
#include "../gameStructure/GameDefines.h"

//Type of audio enum
//enum audio_type{BG_MUSIC, SFX_MUSIC};

class SoundManager{
public: 
	static SoundManager* getInstance();

	bool init();
	bool loadAudio(std::string audio, audio_type type);
	void playMusic();
	void pauseMusic(){Mix_PauseMusic();};
	void resumeMusic(){ Mix_ResumeMusic(); };
	void stopMusic(){Mix_HaltMusic();};

	void playSfx(std::string sfxTrack);

private:
    SoundManager();
	~SoundManager(){Mix_CloseAudio();};

	Mix_Music *bgMusic;
	Mix_Chunk *Sfx;
};



#endif//_SOUNDMANAGER_H_
