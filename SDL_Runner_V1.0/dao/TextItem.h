#ifndef _TEXT_ITEM_H_
#define _TEXT_ITEM_H_
#include <string>

/*Base Text Item*/
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