#ifndef _GAMEDEFINES_H_
#define _GAMEDEFINES_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: GameDefines.h
-

-		All in game global defines
*/
//Window
#define GAME_WIDTH 1900
#define GAME_HEIGHT 640


//Velocity
#define FORCE_UP 10
#define FORCE_X 10
#define FORCE_WORLD 5

//Player Jump Defines
#define MAX_LIMIT 100
#define MIN_LIMIT 0

//Xml Document
#define XMLDOC "../SDL_Runner_V1.0/assets/assets.xml"


//Text Colours
#define RED SDL_Color{255,0,0}
#define GREEN SDL_Color{0,255,0}
#define BLUE SDL_Color{0,0, 255}
#define BLACK SDL_Color{0,0,0}
#define WHITE SDL_Color{255,255,255}
#define ORANGE SDL_Color{235,140,16}


//Games Enum's
typedef enum{ OT_OBJECT, OT_PLAYER, OT_OBSTICAL, OT_COLLECTABLE, OT_LAYER, OT_BUTTON }EObjectType;
typedef enum{ ALIVE, DEAD, POWERUP, JUMPING, FALLING, SLIDING }EPlayerState;
typedef enum{ BG_MUSIC, SFX_MUSIC }audio_type;
typedef enum{ RUNNING, PAUSED, DESTROY }SceneState;


#endif//_GAMEDEFINES_H_