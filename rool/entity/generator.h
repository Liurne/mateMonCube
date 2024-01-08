#ifndef GENERATOR_H
#define GENERATOR_H

#include "player.h"
#include "../core/texture.h"

class Generator
{
    public:
    /**
     * @brief Generator constructor class which initializes the position of the generator
     * 
     * @param x Position X
     * @param y Position Y
     */
    Generator(const double x, const double y);

    void generatorReset();

    /**
     * @brief Get the entity object
     */
    Entity& getEntity();

    /**
     * @brief Get the texture object of generator
     */
    Texture& getTexture();
    
    /**
     * @brief Set the texture object of generator
     * 
     * @param Window Object window
     * @param texture Object Texture
     */
    void setGeneratorTexture(Window &win,const char* texture);

    /**
     * @brief Is the player close to a generator
     * 
     * @return true : player nears
     * @return false : players is not nears
     */
    bool isNearGenerator(Player &p);

    /**
     * @brief Activate the generator (mini game)
     */
    void activateGenerator();

    /**
     * @brief Function that decides if we win the mini game or not
     */
    bool isGeneratorActivate();

    private:

    Entity mEntity;
    Texture mTex;
    bool isActivate;
};

#endif