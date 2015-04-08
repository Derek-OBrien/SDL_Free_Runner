//
//  SoundManager.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 26/03/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__SoundManager__
#define __SDL_Game_Programming_Book__SoundManager__

#include <iostream>
#include <map>
#include <string>
#include "SDL_mixer.h"

enum audio_type{BG_MUSIC, SFX_MUSIC};

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



#endif /* defined(__SDL_Game_Programming_Book__SoundManager__) */
