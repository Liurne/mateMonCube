#ifndef MAP_H
#define MAP_H

#include "core/include.h"
#include "json.hpp"

/**
 * @brief class who manage a map which is written as an array of integers.
 * 
 */

class Map
{
  public:

    /**
     * @brief Construct a new Map object
     * 
     * @param fileName A character string 
     * (to retrieve the json file of the map)
     */
    Map(string fileName);

    void mapReset();

    int getWorldCase(int x,int y);

     /**
     * @brief Get the Map Width object
     * 
     * @return natural number width of the map
     */
    unsigned int getMapWidth();

    /**
     * @brief Get the Map Height object
     * 
     * @return natural number height of the map
     */
    unsigned int getMapHeight();

    /**
     * @brief Get the Spawn Player X object
     * 
     * @return double 
     */
    double getSpawnPlayerX();

     /**
     * @brief Get the Spawn Player Y object
     * 
     * @return double 
     */
    double getSpawnPlayerY();

    /**
     * @brief Make the door disappear
     * 
     * @param x integer Position X
     * @param y integer Position Y
     */
    void clearDoor(int x, int y);

    void coutMap();

    friend ostream& operator<<(ostream& out, Map& m )
		{
      for(int i=0;i<(int)m.getMapHeight();i++){out<<"--";}
			out<<endl<<"Map :"<<endl<<endl;
      for(int i=0;i<(int)m.getMapWidth();i++)
      {
          for(int j=0;j<(int)m.getMapHeight();j++)
          {
              out<<m.getWorldCase(i,j)<<",";
          }
          out<<endl;
      }
      for(int i=0;i<(int)m.getMapHeight();i++){out<<"--";}

       return out;
		}

  private:
  
    unsigned int w,h;
    float pSpawnX,pSpawnY;
    float mSpawnX,mSpawnY;
    vector< vector<int> > worldMap;
    vector< vector<int> > originalMap;

     /**
     * @brief Set the Map Case object for modify a row on map
     * 
     * @param x position in x on the map
     * @param y position in y on the map
     * @param v new number to enter in the row map
     */
    void setMapCase(int x,int y,int v);
};

#endif
