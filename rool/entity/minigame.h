#ifndef MINIGAME_H
#define MINIGAME_H

#include "../core/include.h"
#include "../core/timer.h"
#include "../core/text.h"
#include "../core/texture.h"
#include "../core/shape.h"

struct lever {
    unsigned int leverValue; 
    bool AddEnigma;
}; 

// class mére des mini jeux
class MiniGame 
{
    public:
    
        /**
         * @brief 
         * 
         * @param isGameDisplayed 
         * @return true 
         * @return false 
         */
        bool isGameOn(bool isGameDisplayed);

        /**
         * @brief Inheritance from the gameUpdate function of the powerlight child class
         * 
         * @param i Lever index
         */
        virtual void gameUpdate(int i) = 0;

    protected:
        Timer timer;
        int score;
};

class PowerLightGame : public MiniGame
{
    public:
        /**
         * @brief Construct a new Power Light Game object with as
         * default value the 4 levers of the lever structure and 
         * the result of the number of lights displayed
         * 
         */
        PowerLightGame();

        /**
         * @brief Destroy the Power Light Game object
         * 
         */
        ~PowerLightGame();

        void powerLightReset();

        /**
         * @brief Update the mini game Add to result or subtract from result
         * 
         * @param i Lever index
         */
        void gameUpdate(int i);

        /**
         * @brief Manage the click on a lever
         * 
         * @param mouse x and y position of the mouse
         */
        void whichLeverIsClicked(Point mouse);

        Texture LeverTexture; 
        Texture BackgroundTexture; 
        Texture LightTextureGreen;
        Texture LightTextureYellow;
        Texture LightTextureRed;
        Texture LightTextureON;

        bool DisplayPL;
        int leverWidth,leverHeight;
        int LightDim;
        vector <lever> AllLever;
        vector <int> lever_Spritespace;
        int result;
        int GoalPL;

    private:


};

class SuperSimonGame : public MiniGame
{
    public:

    private:
        SuperSimonGame();
        ~SuperSimonGame();

};

#endif