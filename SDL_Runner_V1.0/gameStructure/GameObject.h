#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>


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
	void setPositionX(int x){ mPosX = x; };				//Set game object position
	void setPositionY(int y){ mPosY = y; };				//Set game object position
	void setPosition(int x, int y){ mPosX = x; mPosY = y; };	//Set game object position


	void setScaleObjectX(float x){ mScaleXBy = x; };		//Scale object by x amount
	void setScaleObjectY(float y){ mScaleYBy = y; };		//Scale object by x amount
	void setScaleObject(float x, float y){ mScaleXBy = x; mScaleYBy = y; };		//Scale object by x amount
	
	void setRotateObjectX(float x){ mRotateXBy = x; };		//Rotate object by x amount
	void setRotateObjectY(float y){ mRotateYBy = y; };		//Rotate object by x amount
	void setRotateObject(float x, float y){ mRotateXBy = x; mRotateYBy = y; };		//Rotate object by x amount

	void setObjectType(EObjectType type){ eTypeOfObject = type; };
	void setObjectBoundingBox(int x, int y, int height, int width);
	
	void setName(const char* name) { objectName = name; };

	//Getters
	int getPositionX(){ return mPosX; };				//Get objects X position
	int getPositionY(){ return mPosY; };				//Get objects Y position
	
	float getScaleX(){ return mScaleXBy; };
	float getScaleY(){ return mScaleYBy; };

	float getRotationX(){ return mRotateXBy; };
	float getRotationY(){ return mRotateYBy; };

	EObjectType getObjectType(){ return eTypeOfObject; };

	SDL_Rect* getObjectBoundingBox() { return &objectBoundingBox; };
	
	const char* getName(){ return objectName; };


private:	

	EObjectType eTypeOfObject;		//Set default object type
	SDL_Rect objectBoundingBox;		//Object Bounding box

	int mPosX;		//Hold X cooridnate
	int mPosY;		//Hold Y cooridnate
	
	float mScaleXBy;		//Value to scale object X by
	float mScaleYBy;		//Value to scale object Y by

	float mRotateXBy;		//Value to rotate object X by
	float mRotateYBy;		//Value to rotate object Y by

	const char* objectName;		//Object Name

	bool initCompleted;

};

#endif//_GAME_OBJECT_H_