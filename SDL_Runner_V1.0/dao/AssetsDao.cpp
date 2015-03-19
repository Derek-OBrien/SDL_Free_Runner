#include "AssetsDao.h"
#include <iostream>


//Set up Singleton
AssetsDAO* AssetsDAOInstance = 0;				//instance of the object to be used
AssetsDAO* AssetsDAO::getInstance(){
	if (AssetsDAOInstance == 0){				//if the instance is null
		AssetsDAOInstance = new AssetsDAO();	//create the instance 
	}											//otherwise
	return AssetsDAOInstance;					//return the instance
}


//create
void AssetsDAO::create(){
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLNode* node = doc.NewElement("Assets");
	doc.InsertEndChild(node);
	doc.SaveFile(XMLDOC);
}

Path AssetsDAO::read( std::string name){

	Path temp;			//temp variable
	Path elementName;	//temp name 

	//Load Document
	tinyxml2::XMLDocument doc;
	doc.LoadFile(XMLDOC);

	if (doc.LoadFile(XMLDOC) == tinyxml2::XML_SUCCESS){

		//get first element <Assets>
		tinyxml2::XMLElement* rootElement = doc.FirstChildElement();

		if (rootElement == nullptr)//If root null print error
			std::cout << tinyxml2::XML_ERROR_FILE_READ_ERROR << std::endl;

		//Loop Through 2nd Elememt <ImagePaths>
		for (tinyxml2::XMLElement* child = rootElement->FirstChildElement(); child != NULL; child = child->NextSiblingElement()){

			//Loop through Child Element of <ImagePaths> looking for <path> element
			for (tinyxml2::XMLElement* pathElement = child->FirstChildElement("path"); pathElement != NULL; pathElement = pathElement->NextSiblingElement()){

				//Get Element Name Attribute 
				elementName.setText(pathElement->Attribute("name"));

				//If Element name == Name passed in get text of Element
				if (elementName.getText() == name){
					temp.setText(pathElement->GetText());
				}		
			}
		}
		return temp;
	}
	else
		std::cout << "Could Not Load XML Document : %s" << XMLDOC << std::endl;

	return NULL;
}


//read sprite animation 
SpriteAnimation AssetsDAO::readSpriteAnimation(std::string name){

	SpriteAnimation temp;			//temp variable
	Path elementName;	//temp name 

	//Load Document
	tinyxml2::XMLDocument doc;
	doc.LoadFile(XMLDOC);

	if (doc.LoadFile(XMLDOC) == tinyxml2::XML_SUCCESS){

		//get first element <Assets>
		tinyxml2::XMLElement* rootElement = doc.FirstChildElement();

		if (rootElement == nullptr)//If root null print error
			std::cout << tinyxml2::XML_ERROR_FILE_READ_ERROR << std::endl;

		//Loop Through 2nd Elememt <ImagePaths>
		for (tinyxml2::XMLElement* child = rootElement->FirstChildElement(); child != NULL; child = child->NextSiblingElement()){

			//Loop through Child Element of <ImagePaths> looking for <path> element
			for (tinyxml2::XMLElement* pathElement = child->FirstChildElement("path"); pathElement != NULL; pathElement = pathElement->NextSiblingElement()){

				//Get Element Name Attribute 
				elementName.setText(pathElement->Attribute("name"));

				//If Element name == Name passed in get text of Element
				if (elementName.getText() == name){
					temp.name = elementName.getText();
					temp.pathToFile = pathElement->GetText();
					temp.spriteHeight = pathElement->IntAttribute("height");
					temp.spriteWidth = pathElement->IntAttribute("width");
					temp.offsetX = pathElement->IntAttribute("offsetX"); 
					temp.offsetY = pathElement->IntAttribute("offsetY");
					temp.frames = pathElement->IntAttribute("frames");
				}
			}
		}
		return temp;
	}
	else
		std::cout << "Could Not Load XML Document : %s" << XMLDOC << std::endl;
}

//Delete
void AssetsDAO::del(){

}
