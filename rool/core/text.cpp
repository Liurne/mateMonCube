#include "text.h"
#include "window.h"

Text::Text()  : stateText(SOLID) , mColorBg(0,0,0,255) , mColText(255,255,255,255) , mFont(NULL) , mText(NULL), mT("0")
{
	
}

Text::~Text(){
	SDL_DestroyTexture(mText);
	TTF_CloseFont(mFont);
}

void Text::setTextFont(const char* font,unsigned int size){
	mFont = TTF_OpenFont(font, size);
}
void Text::setTextstate(stateT state){
	stateText=state;
}
void Text::setTextColorBackGround(Color c){
	mColorBg=c;
}
void Text::setTextColor(Color c){
	mColText=c;
}

void Text::createText(Window& win){
	SDL_Surface* text;
	switch(stateText){
	case BLENDED:
		text = TTF_RenderText_Blended(mFont,mT,mColText.convertToSDL());
		break;
	case SHADED:
		text = TTF_RenderText_Shaded(mFont,mT, mColText.convertToSDL(), mColorBg.convertToSDL());
		break;
	default:
		text = TTF_RenderText_Solid(mFont,mT, mColText.convertToSDL());
		break;
	}
	if(mText){SDL_DestroyTexture(mText);}
	mText=SDL_CreateTextureFromSurface(win.getRenderer(),text);
	if(!mText){cout<<"la convertion en texture a échoué"<<endl;}

	SDL_QueryTexture(mText, NULL, NULL, &w, &h);

	SDL_FreeSurface(text);
}

void Text::setText(Window& win,const char *text){
	mT=text;
	createText(win);
}

SDL_Texture* Text::getTexture()
{
	return mText;
}

int Text::getTextureWidth()
{
	return w;
}
int Text::getTextureHeight()
{
	return h;
}
