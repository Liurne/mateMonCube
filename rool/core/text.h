#ifndef TEXT_H
#define TEXT_H

#include "color.h"

typedef struct Window Window;

enum stateT {UNDEFINED = 0, SOLID = 1,BLENDED = 2,SHADED = 3};
/**
 * @brief Class who manage Text to simplify SDL2 library
 * 
 */
class Text{
	public:
		/**
		 * @brief Construct a new Text object with default value
		 * 
		 */
		Text();

		/**
		 * @brief Destroy the Text object
		 * 
		 */
		~Text();

		/**
		 * @brief Set the Text Font object
		 * 
		 * @param font character string of font text
		 * @param size size of text
		 */
		void setTextFont(const char* font,unsigned int size);

		/**
		 * @brief Set the Textstate object (SOLID,BLENDED,SHADED,UNDIFINED)
		 * 
		 * @param state enum of state
		 */
		void setTextstate(stateT state);

		/**
		 * @brief Set the Text Color BackGround object
		 * 
		 * @param c Object color
		 */
		void setTextColorBackGround(Color c);

		/**
		 * @brief Set the Text Color 
		 * 
		 * @param c Object color
		 */
		void setTextColor(Color c);

		/**
		 * @brief Set the Text object 
		 * 
		 * @param win Object color
		 * @param text character string to write on the screen
		 */
		void setText(Window& win,const char *text);

		SDL_Texture* getTexture();

		/**
		 * @brief Get the Texture Width object
		 * 
		 * @return integer width text
		 */
		int getTextureWidth();

		/**
		 * @brief Get the Texture Height object
		 * 
		 * @return integer height text
		 */
		int getTextureHeight();

	private:

		void createText(Window& win);

		stateT stateText;
		Color mColorBg;
		Color mColText;

		int w,h;

		TTF_Font* mFont;
		SDL_Texture* mText;
		const char* mT = NULL;

		friend class Window;



};

#endif
