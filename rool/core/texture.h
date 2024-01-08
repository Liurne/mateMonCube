#ifndef TEXTURE_H
#define TEXTURE_H

#include "include.h"

typedef struct Window Window;

/**
 * @brief Class who manage texture to simplify SDL2 library
 * 
 */
class Texture
{
	public:
		/**
		 * @brief Construct a new Texture object
		 * 
		 */
		Texture();
		/**
		 * @brief Construct a new Texture object
		 * 
		 * @param win Object window
		 * @param texture charactere string: texture path 
		 */
		Texture(Window& win,const char* texture);

		/**
		 * @brief Destroy the Texture object
		 * 
		 */
		virtual ~Texture();

		/**
		 * @brief Set the Texture object
		 * 
		 * @param win Object window
		 * @param texture charactere string: texture path
		 */
		void setTexture(Window& win,const char* texture);

		/**
		 * @brief Get the Texture Dimension object
		 * 
		 * @param w texture width
		 * @param h texture height
		 */
		void getTextureDim(int &w,int &h);

		/**
		 * @brief Get the Texture Width object
		 * 
		 * @return integer width of texture
		 */
		int getTextureWidth();

		/**
		 * @brief Get the Texture Height object
		 * 
		 * @return integer height texture
		 */
		int getTextureHeight();

		/**
		 * @brief Get the Texture object
		 * 
		 * @return sdl object of texture
		 */
		SDL_Texture* getTexture();

  	private:
		SDL_Texture* mTexture;
		int w,h;
};

#endif
