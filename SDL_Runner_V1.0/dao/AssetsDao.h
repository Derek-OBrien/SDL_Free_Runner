#ifndef _ASSETS_DAO_H_
#define _ASSETS_DAO_H_

/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: AssetsDao.h
-

-		
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

	//read
	Path read(std::string name, std::string elementType, std::string root);
	ImageDetails readImageDetails(std::string name);

	//update
	void update(std::string choice, std::string type, std::string root);

	//delete
	void del();
private:

	//Xml Document
	tinyxml2::XMLDocument doc;

};

#endif//_ASSETS_DAO_H_