

#include "LTexture.h"
#include "GameManager.h"


bool LTexture::init(){
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;

	return true;
}


bool LTexture::loadFromFile(std::string path){
	//Get rid of preexisting texture
	cleanup();

	//The final texture
	SDL_Texture* newTexture = NULL;
	

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL){
		printf("LT: Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else{
		cout << "LT: image file loaded" << endl;

		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(GameManager::getInstance()->getRenderer(), loadedSurface);
		if (newTexture == NULL){
			printf("LT: Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else{
			cout << "LT: texture created" << endl;
		
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}


void LTexture::render(int x, int y, SDL_Rect* clip){
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy(GameManager::getInstance()->getRenderer(), mTexture, clip, &renderQuad);
}


//Clean Up Everything
void LTexture::cleanup(){
	
	//Free Texture if it exits
	if (mTexture != NULL){
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

