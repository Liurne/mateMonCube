#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

typedef struct Item Item;

class Player
{
  public:
  /**
   * @brief Construct a new Player object
   * 
   * @param name_ player name string
   * @param x an integer: x-position of the player
   * @param y an integer: y-position of the player
   * @param moveSpeed  decimal number :player's movement speed
   * @param rotaSpeed  decimal number: player's camera speed
   */
    Player(const char * name_,const double x, const double y,const double moveSpeed,const double rotaSpeed);

    void playerReset();

      /**
     * @brief Get the Entity object
     * 
     * @return Entity& 
     */
    Entity& getEntity();


    /**
     * @brief Get the Player Name object
     * 
     * @return A character string corresponding to the name of the player object
     */
    const char * getPlayerName();

    int getNumberKey();

    /**
     * @brief We retrieve an item
     * 
     * @param idItem Name of the item in character string
     */
    void addItem(const char* idItem);

    friend ostream& operator<<(ostream& out, Player& p )
		{
			out <<"Player : "<< p.getPlayerName() <<" "<<endl<< "position : "<<p.getEntity().x<<","<<p.getEntity().y<<endl<<
      "direction : "<<p.getEntity().directionX<<","<<p.getEntity().directionY<<endl;

       return out<<"en plus"<<endl;
		}

    /**
     * @brief Output the position of the map on the terminal
     * 
     * @param map Object of the map
     */
    void coutPosMap(Map &map);

    /**
     * @brief Function that detects if the player is close to a room door
     * 
     * @param m Object map
     * @return true player is near a door
     * @return false player is not near a door
     */
    bool isNearDoor(Map &m);

    /**
     * @brief 
     * 
     * @param m 
     * @return true Player near room door
     * @return false Player near room door
     */
    bool isNearSneakDoor(Map &m);

    /**
     * @brief 
     * 
     * @param m Object map
     */
    void openDoor(Map &m);  

    /**
     * @brief 
     * 
     * @param m Object map
     * @return true Player near end gate
     * @return false Player does not near end gate
     */
    bool isNearFinalDoor(Map &m);

    /**
     * @brief Detects if the player can activate the end of the game
     * 
     * @param m Object map
     * @param isGeneratorOk boolean that checks if we have finished the mini game
     * @param isGameWin Boolean that says if the game is win
     */
    void openFinalDoor(Map &m,bool isGeneratorOk,bool &isGameWin);
    

  private:
    const char * name;

    int key;

    double originalPosX,originalPosY;
    Entity mEntity;



    
};

#endif
