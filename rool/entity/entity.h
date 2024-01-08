#ifndef ENTITY_H
#define ENTITY_H

#include "../core/include.h"
#include "../map.h"

class Entity
{
    public:
        /**
         * @brief Construct a new Entity object
         * 
         * @param x_ Position x of the Entity object
         * @param y_ Position y of the Entity object
         * @param moveSpeed_ Speed of the entity's movements
         * @param rotaSpeed_ Rotation of the entity object
         */

        Entity(const double &x_,const double &y_,const double &moveSpeed_,const double &rotaSpeed_);

        Entity();
        
        /**
         * @brief Destroy the Entity object
         * 
         */

        ~Entity();

        /**
         * @brief Set the Position object
         * 
         * @param x_ Position x of the Entity object
         * @param y_ Position y of the Entity object
         */
        void setPosition(double x_,double y_);

          /**
         * @brief Update rotation and movement of the entity object
         * 
         * @param fps Frame per second
         */
        void updateMoveAndRota(const int &fps);

         /**
         * @brief Movement to the left
         * 
         * @param map 
         * @param fps Frame per second
         */
        void moveLeft(Map &map,const int &fps);

        /**
         * @brief Movement to the right
         * 
         * @param map 
         * @param fps Frame per second
         */
        void moveRight(Map &map,const int &fps);

        /**
         * @brief Move the camera to the left
         * 
         * @param fps Frame per second
         */
        void rotateLeft(const int &fps);

        /**
         * @brief Move the camera to the right
         * 
         * @param fps 
         */
        void rotateRight(const int &fps);

        /**
         * @brief Move the camera to the left
         * 
         * @param map Move forward
         * @param fps Frame per second
         */
        void moveForward(Map &map,const int &fps);

         /**
         * @brief Movement coordinates on the map
         * 
         * @param map The game map
         */
        void moveBackward(Map &map,const int &fps);

        /**
         * @brief Set the crawl to a boolean true (player crawls)
         * 
         */
        void setSneakTrue();

        /**
         * @brief Set the crawl to a boolean false (player does not crawls)
         * 
         */
        void setSneakFalse();

        /**
         * @brief Movement coordinates on the map
         * 
         * @param map The game map object
         */

        void verifyCoord(Map &map);
        /**
         * @brief Function that determines if the player is crawling
         * 
         * @return boolean true player crawls
         * @return boolean false player does not crawls 
         */
        bool isPlayerSneak();

        friend ostream& operator<<(ostream& out, Entity& e )
		{
			out <<"Entity : "<<endl<< "position : "<<e.x<<","<<e.y<<endl<<
                "direction : "<<e.directionX<<","<<e.directionY<<endl;

            return out;
		}

        double x,y;
        double directionX,directionY;
        double planCameraX,planCameraY;

    private:
        double oldDirX,oldDirY;
        double oldPlanX,oldPlanY;

        int maxFPS;

        bool isSneak;

        double moveSpeed,rotaSpeed;
        double move,rotation;

};

#endif