#ifndef ITEM_H
#define ITEM_H

#include "player.h"
#include "../core/texture.h"

class Item
{
    public:
     /**
     * @brief Construct a new Item object
     * 
     * @param name A character string of the name of the object
     */
    Item(const char* name);
     /**
     * @brief Construct a new Item object
     */
    Item();

    void itemReset();

     /**
     * @brief Get the Id object name
     * 
     * @return string of characters of name
     */
    const char * getId();

    /**
     * @brief Get entity object
     */
    Entity& getEntity();

    /**
     * @brief Get texture item Object
     */
    Texture& getTexture();

    /**
     * @brief Set texture of item
     * 
     * @param Window Window objet 
     * @param texture Texture path string of item
     */
    void setItemTexture(Window &win,const char* texture);

    /**
     * @brief set Position item
     */
    void setPostion(double x,double y);

    /**
     * @brief Set the id of the item
     * 
     * @param nameId: A character string of the name of the object
     */
    void setItemId(const char* nameId);
    
    /**
     * @brief Function that returns true if the key is on the game
     * @param true: key is in game
     * @param false : key is not on game
     */
    bool isInWorld();

    /**
     * @brief Function that returns true if the item has been retrieved
     * 
     * @param p Object player
     */
    bool isItemPicked(Player &p);


    private:

    const char* id;

    double originalPosX,originalPosY;

    bool inWorld;
    Entity mEntity;
    Texture mTex;
};

#endif