#ifndef DISPLAY_H
#define DISPLAY_H

#include "core/window.h"
#include "raycast.h"
#include "sprite.h"
#include "entity/minigame.h"
#include "entity/pathfinding.h"

class Display
{
  public:

    /**
     * @brief Construct a new Display object
     * 
     * @param win Object window
     */
    Display(Window &win);

    /**
     * @brief Destroy the Display object
     * 
     */
    ~Display();

    /**
     * @brief SDL2 simplification library to draw a pixel
     * 
     * @param p Object point 
     */
    void drawPixel(Point p);

    /**
     * @brief SDL2 simplification library to POint a pixel with color set
     * 
     * @param p Object point
     * @param c Object color
     */
		void drawPixel(Point p,Color c);

    /**
     * @brief SDL2 simplification library to draw a Line
     * 
     * @param l Object line
     */
		void drawLine(const Line &l);

    /**
     * @brief SDL2 simplification library to draw a pixel with color set
     * 
     * @param l Object line
     * @param c Object color
     */
		void drawLine(const Line &l,const Color &c);

    /**
     * @brief SDL2 simplification library to draw a Rectangle
     * 
     * @param r Object rectangle
     */
		void drawRect(Rectangle r);

    /**
     * @brief SDL2 simplification library to draw a Rectangle with color set
     * 
     * @param r Object Rectangle
     * @param c Object color
     */
		void drawRect(Rectangle r,Color c);

    /**
     * @brief SDL2 simplification library to draw a textured rectangle
     * 
     * @param t Object texture
     * @param srcRect Object Rectangle which corresponds to the piece of the selected image
     * @param dstRectObject Rectangle textured display at the screen
     */
    void drawTexture(Texture &t,Rectangle srcRect, Rectangle dstRect);
    
    /**
     * @brief SDL2 simplification library to draw a textured rectangle 
     * with default all image draw in rectangle
     * 
     * @param t Object texture
     * @param dstRect Object Rectangle textured display at the screen
     */
    void drawTexture(Texture &t, Rectangle dstRect);

    /**
     * @brief Draw the text
     * 
     * @param t Object text
     * @param dstRect Object texture size and position on the screen
     */
    void drawText(Text &t,Rectangle dstRect);

    /**
     * @brief Draws the raycast textured, all the ray which gives 3D scene
     * 
     * 
     * @param r Object Raycast
     * @param t Object Texture
     */
    void drawRaycast(Raycast &r,vector<Texture> &t);

     /**
     * @brief Draw the mini map
     * 
     * @param ray Object Raycast
     * @param m Object Map
     */
    void drawMiniMap(Raycast &ray,Monster& m);
    void drawInventory(Player& p);

    /**
     * @brief Draw sprites key textured with SDL2 (graphical mode)
     * 
     * @param r Object Raycast 
     * @param i Object Item
     */
    void drawSprite(Raycast &r,Item &i);
    
    /**
     * @brief draw monster textured with SDL2 (graphical mode)
     * 
     * @param r Object Raycast
     * @param m Object Map
     */
    void drawSprite(Raycast &r,Monster &m);

     /**
     * @brief draw generator textured with SDL2 (graphical mode)
     * 
     * @param r Object Raycast
     * @param m Object Map
     */
    void drawSprite(Raycast &r,Generator &g);

    /**
     * @brief Draw picked items in the right top corner of the screen
     * 
     * @param i Object Item
     */
    void drawPickedItem(vector<Item> &it);

    /**
     * @brief draw Power LIght game (5 levers + background + light on/off)
     */ 
    void drawPowerlight(PowerLightGame &p);
    /**
     * @brief draw the background of the Powerlight mini game with SDL2 (graphical mode)
     */
    void drawBackgroundPL(PowerLightGame &p);
    /**
     * @brief Draw the lights of the mini game Powerlight with SDL2 (graphical mode)
     */
    void drawLight(PowerLightGame &p);
    /**
     * @brief Draw all lever of the mini game PowerLight with SDL2 (graphical mode)
     */
    void drawAllLever(PowerLightGame &p);
    /**
     * @brief Draw which light should be on the screen in the Power Light game
     */
    void drawResult(PowerLightGame &p);

  private:

    Window& window;
    //Text fps;

    Sprite sprite;

      /**
     * @brief Draws the color of a square in the radius of a wall
     * 
     * @param r Object Raycast
     * @param x integer: the index of the map to draw the radius relative to the map
     */
    void drawColorWall(Raycast &r,int &x);
    
     /**
     * @brief Draws the texture of a square of the radius of a wall
     * 
     * @param r Object Raycast
     * @param x the index of the map to draw the radius relative to the map
     * @param t Object texture
     */
    void drawTextureWall(Raycast &r,int &x,vector<Texture> &t);

};

#endif
