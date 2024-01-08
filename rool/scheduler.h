#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "game.h"

enum scene {MENU = 0,GAME = 1,MAPEDITOR = 2};

class Scheduler
{
    public:

     /**
     * @brief Construct a new Scheduler object
     * 
     */
    Scheduler();

     /**
     * @brief Destroy the Scheduler object
     * 
     */
    ~Scheduler();

     /**
     * @brief Initializes the game states (menu, Game, Close)
     * 
     * @return booleean true The game is running
     * @return boolean false the game is not running
     */
    bool init();

     /**
     * @brief Loop of the game (run or not)
     * 
     * @return true 
     */
    bool loop();

    /**
     * @brief Get the Game object
     * 
     * @return Game& Reference's object
     */
    Game& getGame();

  private:
    Window window;
    Display display;

    bool onMenu;
    vector<Text> texts;
    
    Game game;
    bool gameNeedReset;

    Text dispFPS;

    bool isRunning;

    scene actScene;

    Controls controls;
    SDL_Event event;
};


#endif