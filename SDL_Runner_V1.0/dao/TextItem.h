#ifndef _TEXT_ITEM_H_
#define _TEXT_ITEM_H_
#include <string>
/*
-		@author		: Derek O Brien K00105572
-		@lecutrer	: James Daly
-		@file		: TextItem.h
-

-		
*/

class TextItem{
public:
	TextItem(){}
	TextItem(std::string thisText){ text = thisText; }
	~TextItem(){}

	std::string getText(){ return text; }
	void setText(const char* newText){ text.assign(newText); }


private:
	std::string text;


};


#endif//_TEXT_ITEM_H_