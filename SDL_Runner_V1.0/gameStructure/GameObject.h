#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: GameObject.h
-

-		Base class for all game objects(Sprite, Character, Button etc)
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <iostream>


#include "LTexture.h"
#include "GameDefines.h"

////enum to hold object type
//typedef enum EObjectType{ OT_OBJECT, OT_PLAYER, OT_OBSTICAL, OT_COLLECTABLE, OT_LAYER, OT_BUTTON };

//Base class for all game objects
class GameObject{
public:

	GameObject(){ init(); };	//Constructor
	~GameObject(){ cleanup(); };	//DeConstructor

	virtual void cleanup();		//clena up function
	virtual bool init();		//init function

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

	void setObjectType(EObjectType type){ eTypeOfObject = type; };	//set object type
	void setObjectBoundingBox(int x, int y, int height, int width);	//set object bounding box
	
	void setName(std::string name) { objectName = name; };		//set object name

	//Getters
	int getPositionX(){ return mPosX; };				//Get objects X position
	int getPositionY(){ return mPosY; };				//Get objects Y position
	
	float getScaleX(){ return mScaleXBy; };		//get object scale X
	float getScaleY(){ return mScaleYBy; };		//get object scale Y

	float getRotationX(){ return mRotateXBy; };	//get object X rotation
	float getRotationY(){ return mRotateYBy; };	//get object Y rotation

	EObjectType getObjectType(){ return eTypeOfObject; };	//Get type of object

	SDL_Rect* getObjectBoundingBox() { return &objectBoundingBox; };	//get object bouning box
	
	std::string getName(){ return objectName; };	//get object name


private:	
	EObjectType eTypeOfObject;		//Set default object type
	SDL_Rect objectBoundingBox;		//Object Bounding box

	int mPosX;		//Hold X cooridnate
	int mPosY;		//Hold Y cooridnate
	
	float mScaleXBy;		//Value to scale object X by
	float mScaleYBy;		//Value to scale object Y by

	float mRotateXBy;		//Value to rotate object X by
	float mRotateYBy;		//Value to rotate object Y by

	std::string objectName;		//Object Name

	bool initCompleted;	//init bool

};

#endif//_GAME_OBJECT_H_