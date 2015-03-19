#ifndef _PATH_H_
#define _PATH_H
#include "TextItem.h"

class Path : public TextItem{
public:
	Path(){}
	Path(std::string thisText){ setText(thisText.c_str()); }
	~Path(){}

private:



};
#endif//_PATH_H_