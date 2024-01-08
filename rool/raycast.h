#ifndef RAYCAST_H
#define RAYCAST_H

#include "core/window.h"
#include "entity/player.h"
#include "map.h"

const Color BLUE = Color(0,0,255,255);
const Color GREEN = Color(0,255,0,255);
const Color RED = Color(255,0,0,255);
const Color YELLOW = Color(255,255,0,255);
const Color CYAN = Color(0,255,255,255);
const Color MAGENTA = Color(255,0,255,255);

/**
 * @brief Class who manage raycast wall on a map and movement player
 * 
 */
class Raycast
{
  public:

     /**
     * @brief Construct a new Raycast object
     * 
     * @param p Object player
     * @param map Object map
     * @param wW Natural Number: Width of the window
     * @param wH Natural Number: Height of the window
     */
    Raycast(Player &p,Map &map,unsigned int wW,unsigned int wH);

     /**
     * @brief Updating the raycasting ray (a line)
     * 
     * @param x A natural number corresponding to the line to update
     */
    void updateRaycast(const unsigned int &x);


    /**
     * @brief Updates the player's camera field of view
     * depending on the move
     */
    void updateStep();

    /**
     * @brief Get the Collisions Wall 
     * 
     */
    void getCollisions();

    /**
     * @brief Get the collision door 
     * 
     */
    void getCollisionsSpe();

      /**
     * @brief Get the Map object
     * 
     * @return Reference to the map object
     */
    Map& getMap();

     /**
     * @brief Get the player object
     * 
     * @return Reference to the player object
     */
    Player& getPlayer();

    /**
     * @brief Get the Perp Wall Dist which is used to calculate the length of the ray
     * 
     * @param x Integer : index of a ray (line)
     * @return double 
     */
    double getPerpWallDist(int x);

    /**
     * @brief Get the distance between the player and the wall
     * 
     * @param x integer: index of a ray
     * @return integer: ray distance-player
     */
    double getDist(int x);

     /**
     * @brief Get the Side of a ray
     * 
     * @return integer side
     */
    int getSide();


    /**
     * @brief Get the row of a ray
     * 
     * @return integer row in x and y
     */
    int getCase();

    /**
     * @brief Get the ray (line) for color a Wall
     * 
     * @param x naturel integer index of the ray that will be colored
     * @param wW natural integer the width of the wall
     * @param wH natural integer the height of the wall
     * @return Ray to color
     */
    Line getLineForColor(const unsigned int &x,const unsigned int wW,const unsigned int wH);
    
    /**
     * @brief Get the Rectangle for Texture a Wall
     * 
     * @param x 
     * @param wW Width Window
     * @param wH Height Window
     * @param tW Texture width
     * @return Rectangle 
     */
    Rectangle getRectForTexture(const unsigned int &x,const unsigned int wW,const unsigned int wH, int tW);
    
    /**
     * @brief Get the Texture X 
     * 
     * @return integer
     */
    int getTexX();
    /**
     * @brief Is the wall a door
     * 
     * @return true it is a door 
     * @return false it is not a door
     */
    bool isSpeWall();

  private:
    Player& player;
    Map& worldMap;
    unsigned int windowWidth,windowHeight;
    vector<double> perpWallDist;
    vector<double> dist;

    double cameraX; // Point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
    double directionRayonX; // Calcul de direction x du rayon
    double directionRayonY; // Calcul de direction Y du rayon

    // Coordonée x et y du carré dans lequel est positionX/Y
    int mapX;
    int mapY;

    // Distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x) ou horizontal (=un coté y)
    double prochainX;
    double prochainY;

    // Distance que rayon parcours entre chaque point d'intersection vertical/horizontal
    double distanceProchainX;
    double distanceProchainY;
    double distance; // Distance du joueur au mur

    int pasX; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
    int pasY; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive

    bool collision; // True si le mur à été touché, false sinon
    int side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
    int lineHeight; // Hauteur de la ligne a dessiner
    int drawStart; // Position de debut ou il faut dessiner
    int drawEnd; // Position de fin ou il faut dessiner

    double wallX;
    int texX;

    bool speWall;
    bool isSpe;
    int nbSpe;


};



#endif
