#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

#include "LTexture.h"
#include "GameDefines.h"

typedef enum EObjectType{ OT_OBJECT, OT_PLAYER, OT_OBSTICAL, OT_COLLECTABLE, OT_BACKGROUND, OT_BUTTON };	//enum to hold object type

//Base class for all game objects
class GameObject{
public:

	GameObject(){ this->init(); };	//Constructor
	~GameObject(){ this->cleanup(); };	//DeConstructor

	virtual void cleanup();
	virtual bool init();

	//Setters
	void setPosX(float x){ mPosX = x; };				//Set game object position
	void setPosY(float y){ mPosY = y; };				//Set game object position
	void setPos(float x, float y){ mPosX = x; mPosY = y; };	//Set game object position


	void setScaleObjectX(float x){ mScaleXBy = x; };		//Scale object by x amount
	void setScaleObjectY(float y){ mScaleYBy = y; };		//Scale object by x amount
	void setScaleObject(float x, float y){ mScaleXBy = x; mScaleYBy = y; };		//Scale object by x amount
	
	void setRotateObjectX(float x){ mRotateXBy = x; };		//Rotate object by x amount
	void setRotateObjectY(float y){ mRotateYBy = y; };		//Rotate object by x amount
	void setRotateObject(float x, float y){ mRotateXBy = x; mRotateYBy = y; };		//Rotate object by x amount

	void setObjectType(EObjectType type){ eTypeOfObject = type; };
	void setObjectBoundingBox(int x, int y, int height, int width);
	
	//Getters
	float getPositionX(){ return mPosX; };				//Get objects X position
	float getPositionY(){ return mPosY; };				//Get objects Y position
	
	float getScaleX(){ return mScaleXBy; };
	float getScaleY(){ return mScaleYBy; };

	float getRotationX(){ return mRotateXBy; };
	float getRotationY(){ return mRotateYBy; };

	EObjectType getObjectType(){ return eTypeOfObject; };

	SDL_Rect* getObjectBoundingBox(){ return &objectBoundingBox; };
	
private:	

	EObjectType eTypeOfObject;		//Set default object type
	SDL_Rect objectBoundingBox;		//Object Bounding box

	float mPosX;		//Hold X cooridnate
	float mPosY;		//Hold Y cooridnate
	
	float mScaleXBy;			//Value to scale object X by
	float mScaleYBy;			//Value to scale object Y by

	float mRotateXBy;		//Value to rotate object X by
	float mRotateYBy;		//Value to rotate object Y by
};

#endif//_GAME_OBJECT_H_