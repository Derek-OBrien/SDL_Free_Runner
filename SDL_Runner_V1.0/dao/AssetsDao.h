#ifndef _ASSETS_DAO_H_
#define _ASSETS_DAO_H_

#include "ImagePath.h"
#include "../tinyxml/tinyxml2.h"
#include "../gameStructure/GameDefines.h"
#include "../gameStructure/SpriteAnimation.h"

class IAssetsDAO{
public:
	virtual ~IAssetsDAO(){};

	//create
	virtual void create() = 0;

	//read
	virtual Path read(std::string name) = 0;
	virtual SpriteAnimation readSpriteAnimation(std::string name) = 0;
	//update
	//virtual void update(std::shared_ptr<std::vector<StoryPoint>> storyPoints) = 0;

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
	void create();

	//read
	Path read(std::string name);
	SpriteAnimation readSpriteAnimation(std::string name);

	//update
	//void update(std::shared_ptr<std::vector<StoryPoint>> storyPoints);

	//delete
	void del();
private:

};

#endif//_ASSETS_DAO_H_