#ifndef _IMAGE_PATH_H_
#define _IMAGE_PATH_H_

//#include "StoryChoice.h"
#include "Path.h"
#include <vector>
#include <memory>

class ImagePath{
public:
	ImagePath(){text = std::shared_ptr<Path>(new Path());};
	~ImagePath(){};

	void setPath(const char* path) {text->setText(path);};
	std::shared_ptr<Path> getPath() { return text; };

	//void addStoryChoice(const char* storyChoice);
	//std::shared_ptr<std::vector<StoryChoice>> getStoryChoices();

private:
	std::shared_ptr<Path> text;
	//std::shared_ptr<std::vector<StoryChoice>> choices;

};

#endif//_IMAGE_PATH_H_