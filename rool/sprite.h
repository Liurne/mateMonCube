#ifndef SPRITE_H
#define SPRITE_H

#include "raycast.h"
#include "entity/item.h"
#include "entity/monster.h"
#include "entity/generator.h"

class Sprite
{
  public:

    /**
     * @brief Construct a new Sprite object
     * 
     */
    Sprite();

     /**
     * @brief Destroy the Sprite object
     * 
     */
    ~Sprite();

     /**
     * @brief For the item (key) Updates the rectangle that draws the monster sprite. 
     * This rectangle is updated each time the player approaches the sprite and 
     * it disappears if it is behind a wall relative to the player.
     * 
     * @param win Object Window
     * @param p Object player
     * @param i Oject Item
     * @return Rectangle 
     */
    Rectangle spriteItem(Window &win,Player &p,Item &i);
     /**
     * @brief For the mosnter. Updates the rectangle that draws the monster sprite. 
     * This rectangle is updated each time the player approaches the sprite and 
     * it disappears if it is behind a wall relative to the player.
     * 
     * @param win 
     * @param p 
     * @param m 
     * @return Rectangle screen size and position
     */
    Rectangle spriteMonster(Window &win,Player &p,Monster &m);
    /**
     * @brief For the item (key) Updates the rectangle that draws the monster sprite. 
     * This rectangle is updated each time the player approaches the sprite and 
     * it disappears if it is behind a wall relative to the player.
     * 
     * @param win Object Window
     * @param p Object player
     * @param i Oject Generator
     * @return Rectangle 
     */
    Rectangle spriteGenerator(Window &win,Player &p,Generator &g);
    
      /**
     * @brief Call generator, monster and item updates
     * 
     * @param win Object Window
     * @param p Object player
     * @param e Object Entity
     */
    Rectangle updateSprite(Window &win,Player &p,Entity &e);

    bool isLineValid(Window &win,Raycast &r,int x);

     /**
     * @brief Pick an item 
     * 
     * @param p Object player
     */
    void pickItem(Player &p);

  private:
    double spriteX,spriteY;
    double invDet;
    double transformX,transformY;
    int spriteScreenX;
    int spriteWidth,spriteHeight;
    int drawStartX,drawStartY;
    int drawEndX,drawEndY;

};

#endif
