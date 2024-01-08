#ifndef COLOR_H
#define COLOR_H

#include "include.h"

/**
 * @brief Class who manage colors to simplify SDL2 library
 * 
 */
class Color
{
  public:
  /**
   * @brief Construct a new Color object with default settings (color White)
   * 
   */
    Color();
    /**
     * @brief Construct a new Color object with colors defined in RGB value
     * 
     * @param r : natural number from 0 to 255
     * @param g : natural number from 0 to 255
     * @param b : natural number from 0 to 255
     * @param a : natural number from 0 to 255
     */
    Color(const Uint8 &r,const Uint8 &g,const Uint8 &b,const Uint8 &a);
    /**
     * @brief Convert a Color object to a color from the SDL library
     * 
     * @return SDL_Color :A Color constructor from the SDL2 library
     */
    SDL_Color convertToSDL();
    /**
     * @brief Darken a object color
     * 
     * @return Color object with RGB color change
     */
    Color shadowed();
    /**
     * @brief Operator overload "==" to know if two color objects are equal
     * 
     * @param OperandeDeDroite The right color object of the operation
     * @return true if Both colors are equal
     * @return false if Something other than color matching
     */
    bool operator==(const Color & OperandeDeDroite);
    /**
     * @brief Operator overload "!=" to know if two color objects are unequal
     * 
     * @param OperandeDeDroite The right color object of the operation
     * @return true if the two colors are unequall
     * @return false if both color are equal
     */
    bool operator!=(const Color & OperandeDeDroite);

    Uint8 r, g, b, a;
  private:
    
};


#endif
