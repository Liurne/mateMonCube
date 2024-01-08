#include "window.h"

//constructor
Window::Window(const unsigned int &width,const unsigned int &height,const stateW &sWin)
{
	//dimensions of window
	w=width,h=height;

	//state of window (FULLSCREEN/RESIZABLE/FIX)
	mState = sWin;
	if(sWin == FULLSCREEN)
		pState = RESIZABLE;
	else
		pState = sWin;

	//color of the background
	mColor = Color( 0, 0, 0, 255 ).convertToSDL();

	//FPS counter initialization
	frame = 0;
	mFPS=60;
	maxFPS=0;
	isFPSregulate=false;
	clock.start();
	fps.start();
}

//destructor
Window::~Window()
{	
	Mix_CloseAudio();
	//destruction of window and renderer
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	//Quit TTF
	TTF_Quit();
	//Quit SDL
	SDL_Quit();

	cout<<"Program quit correctly"<<endl;	
}

//SDL and TTF initialization and creation of window and renderer
bool Window::init()
{
	//SDL  initialization
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		cout<< "Error occurred during SDL initialization : " << SDL_GetError() <<endl;
		return false;
	}

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
           cout<<"error couldn't read song"<<endl;
    }

	//Creation of window and renderer according to the chosen state
	switch (mState)
	{
	case FULLSCREEN:
		if (SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_FULLSCREEN_DESKTOP, &mWindow, &mRenderer) < 0)
		{
        		SDL_Quit();
        		cout<<"Error occurred while attempting to create window : " << SDL_GetError()<<endl;
		}
		break;
	case RESIZABLE:
		if (SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_RESIZABLE, &mWindow, &mRenderer) < 0)
		{
        		SDL_Quit();
        		cout<<"Error occurred while attempting to create window : " << SDL_GetError()<<endl;
		}
		break;
	default:
		if (SDL_CreateWindowAndRenderer(w, h,  SDL_WINDOW_SHOWN, &mWindow, &mRenderer) < 0)
		{
        		SDL_Quit();
        		cout<<"Error occurred while attempting to create window : " << SDL_GetError()<<endl;
		}
		break;
	}

	//set transparency
	SDL_SetRenderDrawBlendMode(mRenderer, SDL_BLENDMODE_BLEND);

	//TTF initialization (used to write on the window)
	if (TTF_Init() < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
		cout<< "Error occurred during TTF initialization : " << SDL_GetError() <<endl;
		return false;
	}

	return true;
}

//set window  size
void Window::setWindowSize(const unsigned int &width,const unsigned int &height)
{
	w=width;
	h=height;
	SDL_SetWindowSize(mWindow,width,height);
}

//set window in FULLSCREEN state
void Window::setWindowFullscreen()
{
	SDL_SetWindowFullscreen(mWindow,SDL_WINDOW_FULLSCREEN_DESKTOP);
	mState = FULLSCREEN;
}
//set window in windowed state (FIX  or RESIZABLE)
void Window::setWindowWindowedMode()
{
	SDL_SetWindowFullscreen(mWindow,0);
	mState = pState;
}

//set a title for window
void Window::setWindowTitle(const char* title)
{
	SDL_SetWindowTitle(mWindow,title);
}

//set a color for the background
void Window::setWindowColor(Color &color)
{
	mColor = color.convertToSDL();
}

//set the max fps at wich the window updtate
void Window::setMaxFPS(const int &max)
{
	maxFPS=max;
	mFPS=max;
	isFPSregulate=true;
}

//set the color used to draw shape
void Window::setDrawColor(Color color)
{
	SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);
}

//clear the renderer,display the background and look if the window changed size
void Window::winClear()
{
	SDL_GetWindowSize(mWindow,&w,&h);
	SDL_SetRenderDrawColor(mRenderer,mColor.r, mColor.g, mColor.b, mColor.a);
	SDL_RenderClear(mRenderer);
}
//update the window and count the fps
void Window::winUpdate()
{
	SDL_RenderPresent(mRenderer);
	frame++;
	if( fps.getTicks() > 1000 )
	{
		mFPS=(int)((float)frame / ( clock.getTicks() / 1000.f ));
		fps.start();
 	}
	if(isFPSregulate)
		while( clock.getTicks() < (1000.f / maxFPS)*frame ){}
}

SDL_Renderer* Window::getRenderer()
{
	return mRenderer;
}

void Window::getWindowSize(int &w_,int &h_)
{
	SDL_GetWindowSize(mWindow,&w,&h);
	w_=w;
	h_=h;
}

stateW Window::getWindowState()
{
	return mState;
}
int Window::getMaxFPS()
{
	return maxFPS;
}
int Window::getFPS()
{
	return mFPS;
}

unsigned int Window::getWindowWidth()
{
	SDL_GetWindowSize(mWindow,&w,&h);
	return w;
}
unsigned int Window::getWindowHeight()
{
	SDL_GetWindowSize(mWindow,&w,&h);
 	return h;
}

