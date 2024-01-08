#ifndef GAME_H
#define GAME_H

#include "display.h"
#include "core/controls.h"
#include "entity/item.h"
#include "entity/minigame.h"

class Game
{
  public:
    Game(Window &win_,Controls &ctrls_,bool &run_);
    ~Game();

    /**
     * @brief All game initialization (mainly texture and text)
     * 
     * @param win Object Window
     * @return true 
     * @return false 
     */
    bool gameInit(Window &win);
    void gameReset();

    /**
     * @brief Game update 
     * 
     */
    void gameUpdate();
  /**
     * @brief Graphic display:
     * Draw the walls, the monster and the items and short game
     * 
     * @param disp Object Display
     */

    void gameDisplay(Display &disp);


   /**
     * @brief Mode Text display of game (terminal)
     * 
     */
    void gameCout();


    /**
     * @brief Restart game
     * 
     */
    void gameRestart();

  private:
    Window &win;
    Controls &ctrls;
    bool& run;

    vector<KeyAction> mKeyboard;

    Map map;
    Raycast raycast;

    Player player;
    Monster monster;
    Generator generator;

    bool isGameLost;
    bool isGameWin;

    Mix_Music* musiqueBackground;
    Mix_Chunk* keySong;
    bool whenMusic;

    PowerLightGame powerlight;
    vector<Texture> textureMonster;
    vector<Texture> texturesWall;
    vector<Text> message;
    vector<Item> item;

    //Text message;
    bool isMiniMapDisplayed;
};

#endif
