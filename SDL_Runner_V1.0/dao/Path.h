#ifndef _PATH_H_
#define _PATH_H
#include "TextItem.h"
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: Path.h
-

-		Create a Path to return from xml
*/

class Path : public TextItem{
public:
	Path(){}
	Path(std::string thisText){ setText(thisText.c_str()); }
	~Path(){}

private:



};
#endif//_PATH_H_