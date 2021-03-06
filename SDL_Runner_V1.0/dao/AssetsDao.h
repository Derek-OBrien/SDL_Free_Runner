#ifndef _ASSETS_DAO_H_
#define _ASSETS_DAO_H_

/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: AssetsDao.h
-

-		DAO Interface and class contains virtual method signatures for DAO
*/

//Include Files Needed
#include "Path.h"
#include "../tinyxml/tinyxml2.h"
#include "../gameStructure/Sprite.h"

//Dao Interface
class IAssetsDAO{
public:

	//DeConstructor
	virtual ~IAssetsDAO(){};

	//read functions
	virtual Path read(std::string name, std::string elementType, std::string root) = 0;
	virtual ImageDetails readImageDetails(std::string name) = 0;
	virtual int readInt(std::string name, std::string elementType, std::string root) = 0;

	//update
	virtual void update(std::string choice, std::string type, std::string root) = 0;

	//delete
	virtual void del() = 0;
private:

};


//xml implementation
class AssetsDAO : public IAssetsDAO{
public:
	//Static instance
	static AssetsDAO* getInstance();

	//Deconstructor
	virtual ~AssetsDAO(){};

	//Read Functions

	//Read in string
	Path read(std::string name, std::string elementType, std::string root);
	//Read in ImageDetails Struct
	ImageDetails readImageDetails(std::string name);
	//Read in In Value
	int readInt(std::string name, std::string elementType, std::string root);

	//update
	void update(std::string choice, std::string type, std::string root);

	//delete
	void del();
private:

	//Xml Document
	tinyxml2::XMLDocument doc;

};

#endif//_ASSETS_DAO_H_