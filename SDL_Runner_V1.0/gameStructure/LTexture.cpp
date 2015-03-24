

#include "LTexture.h"
#include "GameManager.h"

TTF_Font* myFont = NULL;


bool LTexture::init(){
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;

	return true;
}

LTexture LTexture::loadmedia(std::string path){

	//Loading success flag
	bool success = true;
	LTexture texture;
	//Load press texture
	if (!texture.loadFromFile(path)){
		std::cout << "P: Failed to load texture!" << std::endl;
		success = false;
	}

	return texture;
}

LTexture LTexture::loadTTFMedia(std::string displayText, int size, SDL_Color color){

	bool success = true;
	LTexture textTexture;
	myFont = TTF_OpenFont("../SDL_Runner_V1.0/assets/fonts/lazy.ttf", size);
	if ( myFont == NULL){
		std::cout << "Failed to load font : baveuse3 " << "\nTTF_Error :" << TTF_GetError() << std::endl;
	}
	else{
		//SDL_Color textColor = color;

		if (!textTexture.loadFromRenderedText(displayText, color)){
			std::cout << "Unable to render Text " << std::endl;
			success = false;
		}
	}

	return textTexture;
}




bool LTexture::loadFromFile(std::string path){
	//Get rid of preexisting texture
	cleanup();

	//The final texture
	SDL_Texture* newTexture = NULL;
	

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL){
		std::cout << "LT: Unable to load image " <<  path.c_str() << "\nSDL_image Error : " << IMG_GetError() << std::endl;
	}
	else{
		std::cout << "LT: image file loaded" << std::endl;

		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(LWindow::getInstance()->getRenderer(), loadedSurface);
		if (newTexture == NULL){
			std::cout << "LT: Unable to create texture from %s!\n SDL Error: %s" << path.c_str() << SDL_GetError() << std::endl;
		}
		else{
			std::cout << "LT: texture created" << std::endl;
		
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


//Load Rendered text for TTF fonts
#ifdef _SDL_TTF_H
bool LTexture::loadFromRenderedText(std::string text, SDL_Color color){

	cleanup();
	SDL_Surface* textSurface = TTF_RenderText_Solid(myFont, text.c_str(), color);

	if (textSurface != NULL){

		mTexture = SDL_CreateTextureFromSurface(LWindow::getInstance()->getRenderer(), textSurface);
		if (mTexture == NULL){
			std::cout << "Unable create text texture \n SDL Error :" << SDL_GetError() << std::endl;
		}
		else{
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
	else{
		std::cout << "Unable Render Text surface \n TTF_Error :" << TTF_GetError() << std::endl;
	}


	return mTexture != NULL;
}
#endif

//Basic render
void LTexture::render(int x, int y, SDL_Rect* clip){
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy(LWindow::getInstance()->getRenderer(), mTexture, clip, &renderQuad);
}

void LTexture::setBlendMode(SDL_BlendMode blend){
	SDL_SetTextureBlendMode(mTexture, blend);
}

void LTexture::setAlpha(Uint8 alpha){
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
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

