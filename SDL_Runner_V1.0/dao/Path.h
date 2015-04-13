#ifndef _PATH_H_
#define _PATH_H
#include "TextItem.h"

/*
	Author		: Derek O' Brien
	File		: Path.h
	Description	: Base Path for image paths read in from Xml file
*/

class Path : public TextItem{
public:
	Path(){}
	Path(std::string thisText){ setText(thisText.c_str()); }
	~Path(){}

private:



};
#endif//_PATH_H_