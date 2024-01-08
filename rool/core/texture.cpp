#include "texture.h"
#include "window.h"

Texture::Texture(){
	mTexture=NULL;
}

Texture::Texture(Window& win,const char* texture){

	SDL_Surface* img = IMG_Load(texture);
	if(!img){cout<<"could not find/read the image"<<endl; return;}
	if(mTexture!= NULL) SDL_DestroyTexture(mTexture);
	mTexture = SDL_CreateTextureFromSurface(win.getRenderer(),img);
	if(!mTexture){cout<<"could not load the image"<<endl;}
	else{cout<<"image load"<<endl;}

	SDL_FreeSurface(img);

	SDL_QueryTexture(mTexture, NULL, NULL, &w, &h);
}

Texture::~Texture(){
	SDL_DestroyTexture(mTexture);
}

void Texture::setTexture(Window& win,const char* texture){

	SDL_Surface* img = IMG_Load(texture);
	if(!img){cout<<"Could not find/read the image."<<endl;return;}
	if(mTexture!= NULL) SDL_DestroyTexture(mTexture);
	mTexture = SDL_CreateTextureFromSurface(win.getRenderer(),img);
	if(!mTexture){cout<<"Texture creation failed."<<endl;}

	SDL_FreeSurface(img);

	SDL_QueryTexture(mTexture, NULL, NULL, &w, &h);
}

void Texture::getTextureDim(int &w,int &h)
{
	SDL_QueryTexture(mTexture, NULL, NULL, &w, &h);
}

int Texture::getTextureWidth()
{
	int w;
	SDL_QueryTexture(mTexture, NULL, NULL, &w, NULL);
	return w;
}

int Texture::getTextureHeight()
{
	int h;
	SDL_QueryTexture(mTexture, NULL, NULL, NULL, &h);
	return h;
}

SDL_Texture* Texture::getTexture()
{
	return mTexture;
}
