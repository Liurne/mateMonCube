#ifndef WINDOW_H
#define WINDOW_H

#include "shape.h"
#include "timer.h"
#include "texture.h"
#include "text.h"

enum stateW {FIX = 0,FULLSCREEN = 1,RESIZABLE = 2};

/**
 * @brief class for create a window thanks to SDL2
 * 
 */
class Window
{
	public:
		/**
		 * @brief Construct a new Window object
		 * 
		 * @param width witdh window
		 * @param height height window
		 * @param sWin full screen status resize or fix
		 */

		Window(const unsigned int &width,const unsigned int &height,const stateW &sWin);
		/**
		 * @brief Destroy the Window object
		 * 
		 */
		virtual ~Window();
		/**
		 * @brief SDL and TTF initialization and creation of window and renderer
		 * 
		 * @return true 
		 * @return false 
		 */
		bool init();
		/**
		 * @brief Set the Window Size object 
		 * 
		 * @param width witdh window
		 * @param height height window
		 */

		void setWindowSize(const unsigned int &width,const unsigned int &height);
		/**
		 * @brief Set window in FULLSCREEN state
		 * 
		 */

		void setWindowFullscreen();
		/**
		 * @brief Set window in windowed state (FIX  or RESIZABLE)
		 * 
		 */

		void setWindowWindowedMode();
		/**
		 * @brief Set the Window Title object
		 * 
		 * @param title character string of the title to write on the screen
		 */
		void setWindowTitle(const char* title);
		/**
		 * @brief Set the Window Color object background
		 * 
		 * @param color object Color
		 */
		void setWindowColor(Color &color);
		/**
		 * @brief Set the Max Frame Per Seconds 
		 * 
		 * @param max integer of max fps
		 */
		void setMaxFPS(const int &max);

		/**
		 * @brief Set the color used to draw shape
		 * 
		 * @param color 
		 */
    	void setDrawColor(Color color);
		/**
		 * @brief Clear the renderer,display the background and look if the window changed size
		 * 
		 */
		void winClear();
		/**
		 * @brief Update the window and count the fps
		 * 
		 */
    	void winUpdate();

		SDL_Renderer* getRenderer();
		/**
		 * @brief Get the Window Size object
		 * 
		 * @param w_ width window
		 * @param h_ height window
		 */
    	void getWindowSize(int &w_,int &h_);
		/**
		 * @brief Get the Window Width object
		 * 
		 * @return unsigned int 
		 */
		unsigned int getWindowWidth();
		/**
		 * @brief Get the Window Height object
		 * 
		 * @return unsigned int 
		 */
		unsigned int getWindowHeight();
		/**
		 * @brief Get the Window State object
		 * 
		 * @return state window (fullscreen, fix,resize) 
		 */
    	stateW getWindowState();
		/**
		 * @brief Get the Max Frame Per Seconds object
		 * 
		 * @return integer of max frame per seconds
		 */
		int getMaxFPS();
		/**
		 * @brief get Frame per seconds
		 * 
		 * @return int integer of max frame per seconds
		 */
		int getFPS();

  private:
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;

		int w,h;

		stateW mState;
		stateW pState;

		SDL_Color mColor;

		int frame,mFPS,maxFPS;
		bool isFPSregulate;
		Timer fps;
		Timer clock;
		Timer fpsRegulate;
};


#endif
