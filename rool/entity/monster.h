#ifndef MONSTER_H
#define MONSTER_H

#include "../core/texture.h"
#include "../core/timer.h"
#include "entity.h"
#include "player.h"
#include "pathfinding.h"

class Monster
{
  public:

  /**
   * @brief Construct a new Monster object
   * 
   * @param mMap The map object
   * @param t Monster texture object
   */
  Monster(Map &mMap);

  void monsterReset();

    /**
   * @brief Path update
   * 
   * @param posP Oject point the monster must reach (The position of the player)
   */
  void updatePath(const Point posP);

   /**
   * @brief Monster's movements
   * 
   * @param m Object of the map
   * @param posP Position of the player
   * @param fps Frame per seconds
   */
  void move(Map &m,const Point posP, int fps);
  bool hasKilledPlayer(Player &p);
  /**
   * @brief Set the Monster Texture object
   * 
   * @param win Object window
   * @param texture character string, the path to the new texture
   */
  void setMonsterTexture(Window &win,const char* texture);

  Entity& getEntity();

  /**
   * @brief Get the Texture object
   * 
   * @return Reference of Texture object
   */
  Texture& getTexture();

  /**
   * @brief Get the Part Texture (For 3 frame monster texture movement)
   * 
   * @return Rectangle part of the texture
   */
  Rectangle getPartTexture();

    /**
   * @brief Get the Path Size 
   * 
   * @return Integer the size of the path
   */

  int getPathSize();

  /**
   * @brief Get the Path Case object
   * 
   * @param i which corresponds to a case on the path
   * @return Node 
   */
  Node getPathCase(int i);

  private:

  vector<Node> path;

  Entity mEntity;
  double originalPosX,originalPosY;
  Pathfinding find;
  Texture mTex;
  int indexTexture;

  Timer time;
  Timer animation;
  int refresh;

};

#endif
