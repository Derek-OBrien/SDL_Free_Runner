#ifndef _TEXT_ITEM_H_
#define _TEXT_ITEM_H_
#include <string>

/*
		Author		: Derek O' Brien
		File		: TextItem.h
		Description	: Base Text element for dao
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