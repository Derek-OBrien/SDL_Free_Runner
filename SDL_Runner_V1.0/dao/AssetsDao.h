#ifndef _ASSETS_DAO_H_
#define _ASSETS_DAO_H_

#include "ImagePath.h"
#include "../tinyxml/tinyxml2.h"
#include "../gameStructure/GameDefines.h"
#include "../gameStructure/Sprite.h"
#include "../gameStructure/Button.h"

class IAssetsDAO{
public:
	virtual ~IAssetsDAO(){};

	//create
	virtual void create() = 0;

	//read
	virtual Path read(std::string name, std::string elementType, std::string root) = 0;
	virtual ImageDetails readImageDetails(std::string name) = 0;
//	virtual ButtonDetails readButtonDetails(std::string name) = 0;
	
	//update
	virtual void update(std::string choice, std::string type, std::string root) = 0;

	//delete
	virtual void del() = 0;
private:

};


//xml implementation
class AssetsDAO : public IAssetsDAO{
public:
	static AssetsDAO* getInstance();

	virtual ~AssetsDAO(){};

	//create
	void create(){}

	//read
	Path read(std::string name, std::string elementType, std::string root);
	ImageDetails readImageDetails(std::string name);

	//update
	void update(std::string choice, std::string type, std::string root);

	//delete
	void del();
private:

	tinyxml2::XMLDocument doc;

};

#endif//_ASSETS_DAO_H_