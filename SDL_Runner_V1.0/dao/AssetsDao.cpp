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



//Read in Single Text Value
Path AssetsDAO::read(std::string name, std::string elementType, std::string root){

	Path temp;			//temp variable
	Path elementName;	//temp name 

	//Load Document
	if (doc.LoadFile(XMLDOC) == tinyxml2::XML_SUCCESS){

		//get first element <Assets>
		tinyxml2::XMLElement* rootElement = doc.FirstChildElement(root.c_str());

		//Loop through Child Element looking for <path> element
		for (tinyxml2::XMLElement* pathElement = rootElement->FirstChildElement(elementType.c_str()); pathElement != NULL; pathElement = pathElement->NextSiblingElement()){

			//Get Element Name Attribute 
			elementName.setText(pathElement->Attribute("name"));

			//If Element name == Name passed in get text of Element
			if (elementName.getText() == name){
				temp.setText(pathElement->GetText());
			}
			//	}
		}
		return temp;
	}
	else
		std::cout << "Could Not Load XML Document : %s" << XMLDOC << std::endl;

	return NULL;
}


//read sprite animation 
ImageDetails AssetsDAO::readImageDetails(std::string name){

	ImageDetails temp;			//temp variable
	Path elementName;	//temp name 

	//Load Doc
	if (doc.LoadFile(XMLDOC) == tinyxml2::XML_SUCCESS){

		//get first element <Assets>
		tinyxml2::XMLElement* rootElement = doc.FirstChildElement();

		//If root null print error
		if (rootElement == NULL)
			std::cout << tinyxml2::XML_ERROR_FILE_READ_ERROR << std::endl;


		//Loop through Child Element looking for <path> element
		for (tinyxml2::XMLElement* pathElement = rootElement->FirstChildElement("path"); pathElement != NULL; pathElement = pathElement->NextSiblingElement()){

			//Get Element Name Attribute 
			elementName.setText(pathElement->Attribute("name"));

			//Get Sprite Sheet Details
			if (elementName.getText() == name){
				temp.name = elementName.getText();						//Name
				temp.pathToFile = pathElement->GetText();				//Path to files
				temp.spriteHeight = pathElement->IntAttribute("height");//Height
				temp.spriteWidth = pathElement->IntAttribute("width");	//Width
				temp.offsetX = pathElement->IntAttribute("offsetX");	//OffsetX
				temp.offsetY = pathElement->IntAttribute("offsetY");	//OffsetY
				temp.frames = pathElement->IntAttribute("frames");		//Number of Frames
				temp.posX = pathElement->IntAttribute("posX");
				temp.posY = pathElement->IntAttribute("posY");
			}
		}
		return temp;
	}
	else
		std::cout << "Could Not Load XML Document : %s" << XMLDOC << std::endl;
	return temp;
}



//update
void AssetsDAO::update(std::string choice, std::string type, std::string root){

	//Load File
	if (doc.LoadFile(XMLDOC) == tinyxml2::XML_SUCCESS){
		//Get Root Node
		tinyxml2::XMLElement* rootNode = doc.FirstChildElement(root.c_str());//Assets
		//Child Node
		tinyxml2::XMLElement* pathNode = rootNode->FirstChildElement(type.c_str());//path
		//Write text to element
		pathNode->SetText(choice.c_str());
		//Same Xml document
		doc.SaveFile(XMLDOC);
	}
	else{
		std::cout << "Could Not Load XML Document : %s" << XMLDOC << std::endl;
	}
}


void AssetsDAO::del(){
	delete AssetsDAOInstance;
}