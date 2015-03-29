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
	tinyxml2::XMLNode* node = doc.NewElement("assets");
	doc.InsertEndChild(node);
	doc.SaveFile(XMLDOC);
}


//Read in Single Text Value
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
ImageDetails AssetsDAO::readImageDetails(std::string name){

	ImageDetails temp;			//temp variable
	Path elementName;	//temp name 

	//Load Document
	tinyxml2::XMLDocument doc;
	doc.LoadFile(XMLDOC);

	if (doc.LoadFile(XMLDOC) == tinyxml2::XML_SUCCESS){

		//get first element <Assets>
		tinyxml2::XMLElement* rootElement = doc.FirstChildElement();
		
		//If root null print error
		if (rootElement == NULL)
			std::cout << tinyxml2::XML_ERROR_FILE_READ_ERROR << std::endl;

		//Loop Through 2nd Elememt <ImagePaths>
		for (tinyxml2::XMLElement* child = rootElement->FirstChildElement(); child != NULL; child = child->NextSiblingElement()){

			//Loop through Child Element of <ImagePaths> looking for <path> element
			for (tinyxml2::XMLElement* pathElement = child->FirstChildElement("path"); pathElement != NULL; pathElement = pathElement->NextSiblingElement()){

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
		}
		return temp;
	}
	else
		std::cout << "Could Not Load XML Document : %s" << XMLDOC << std::endl;
	return temp;
}

ButtonDetails AssetsDAO::readButtonDetails(std::string name){
	
	ButtonDetails temp;			//temp variable
	Path elementName;	//temp name 

	//Load Document
	tinyxml2::XMLDocument doc;
	doc.LoadFile(XMLDOC);

	if (doc.LoadFile(XMLDOC) == tinyxml2::XML_SUCCESS){

		//get first element <Assets>
		tinyxml2::XMLElement* rootElement = doc.FirstChildElement();

		//If root null print error
		if (rootElement == NULL)
			std::cout << tinyxml2::XML_ERROR_FILE_READ_ERROR << std::endl;

		//Loop Through 2nd Elememt <ImagePaths>
		for (tinyxml2::XMLElement* child = rootElement->FirstChildElement(); child != NULL; child = child->NextSiblingElement()){

			//Loop through Child Element of <ImagePaths> looking for <path> element
			for (tinyxml2::XMLElement* pathElement = child->FirstChildElement("path"); pathElement != NULL; pathElement = pathElement->NextSiblingElement()){

				//Get Element Name Attribute 
				elementName.setText(pathElement->Attribute("name"));

				//Get Sprite Sheet Details
				if (elementName.getText() == name){
					temp.name = elementName.getText();						//Name
					temp.pathToFile = pathElement->GetText();				//Path to files
					temp.height = pathElement->IntAttribute("height");//Height
					temp.width = pathElement->IntAttribute("width");	//Width
					temp.offsetX = pathElement->IntAttribute("offsetX");
					temp.offsetY = pathElement->IntAttribute("offsetY");
					temp.frames = pathElement->IntAttribute("frames");
					temp.posX = pathElement->IntAttribute("posX");
					temp.posY = pathElement->IntAttribute("posY");
					temp.state = pathElement->IntAttribute("state");
				}
			}
		}
		return temp;
	}
	else
		std::cout << "Could Not Load XML Document : %s" << XMLDOC << std::endl;
	return temp;
}


//update
void AssetsDAO::update(std::string choice){

	tinyxml2::XMLDocument doc;
	doc.LoadFile(XMLDOC);

	if (doc.LoadFile(XMLDOC) == tinyxml2::XML_SUCCESS){
		//Get Root Node
		tinyxml2::XMLElement* rootNode = doc.FirstChildElement();//Assets
		//Get Next Node
		tinyxml2::XMLElement* childNode = rootNode->FirstChildElement();//imagePaths
		//Temp Element 
		tinyxml2::XMLElement* temp = nullptr;
		tinyxml2::XMLElement* temp2 = childNode->FirstChildElement();//path

		while (temp2 != nullptr){
			temp = temp2;
			temp2 = temp2->NextSiblingElement("path");
		}
		if (temp != nullptr){
			//write the text
			tinyxml2::XMLComment* newComment = doc.NewComment("Selected Player");
			tinyxml2::XMLElement* newElement = doc.NewElement("path");
			newElement->SetText(choice.c_str());
			newElement->SetAttribute("name", "selected_player");
			childNode->InsertAfterChild(temp, newComment);
			childNode->InsertAfterChild(newComment, newElement);
		}
		//doc.Print();
		doc.SaveFile(XMLDOC);
	}
	else{
		std::cout << "Could Not Load XML Document : %s" << XMLDOC << std::endl;
	}
}

//Delete
void AssetsDAO::del(){
	
	tinyxml2::XMLDocument doc;
	doc.LoadFile(XMLDOC);

	if (doc.LoadFile(XMLDOC) == tinyxml2::XML_SUCCESS){
		
		tinyxml2::XMLElement* rootElement = doc.FirstChildElement();

		//If root null print error
		if (rootElement == NULL)
			std::cout << tinyxml2::XML_ERROR_FILE_READ_ERROR << std::endl;

		//Loop Through 2nd Elememt <ImagePaths>
		for (tinyxml2::XMLElement* child = rootElement->FirstChildElement(); child != NULL; child = child->NextSiblingElement()){

			//Loop through Child Element of <ImagePaths> looking for <path> element
			for (tinyxml2::XMLElement* pathElement = child->FirstChildElement("path"); pathElement != NULL; pathElement = pathElement->NextSiblingElement()){

				tinyxml2::XMLElement* element = doc.NewElement("selected_player");

				child->DeleteChild(element);
			}
		}
	}
}
