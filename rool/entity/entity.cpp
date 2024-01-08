#include "entity.h"

Entity::Entity(const double &x_,const double &y_,const double &moveSpeed_,const double &rotaSpeed_)
{
    x= x_,y=y_;
    directionX = -1, directionY = 0;
    planCameraX = 0, planCameraY = 0.66;

    maxFPS = 60;

    moveSpeed = moveSpeed_;
    rotaSpeed = rotaSpeed_;
}

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::setPosition(double x_,double y_)
{
    x=x_;
    y=y_;
}

void Entity::updateMoveAndRota(const int &fps){
    move =fps*(((float)maxFPS*moveSpeed)/fps);
    rotation = fps*(((float)maxFPS*rotaSpeed)/fps);
}

void Entity::rotateLeft(const int &fps)
{
    updateMoveAndRota(fps);
    double oldDirX = directionX;
    directionX = directionX * cos(rotation) - directionY * sin(rotation);
    directionY = oldDirX * sin(rotation) + directionY * cos(rotation);

    double oldPlaneX = planCameraX;
    planCameraX = planCameraX * cos(rotation) - planCameraY * sin(rotation);
    planCameraY = oldPlaneX * sin(rotation) + planCameraY * cos(rotation);

}

void Entity::rotateRight(const int &fps)
{
    updateMoveAndRota(fps);
    double oldDirX = directionX;
    directionX = directionX * cos(-rotation) - directionY * sin(-rotation);
    directionY = oldDirX * sin(-rotation) + directionY * cos(-rotation);
    double oldPlanX = planCameraX;
    planCameraX = planCameraX * cos(-rotation) - planCameraY * sin(-rotation);
    planCameraY = oldPlanX * sin(-rotation) + planCameraY * cos(-rotation);

}

void Entity::moveRight(Map &map,const int &fps)
{
    updateMoveAndRota(fps);
    if(map.getWorldCase(int(x + planCameraX * move),int(y)) == false) x += planCameraX * move;
    if(map.getWorldCase(int(x),int(y + planCameraY * move)) == false) y += planCameraY * move;
    if(map.getWorldCase(int(x + planCameraX * move),int(y)) == 11 && isSneak) x += planCameraX * move;
    if(map.getWorldCase(int(x),int(y + planCameraY * move)) == 11 && isSneak) y += planCameraY * move;

    verifyCoord(map);
}

void Entity::moveLeft(Map &map,const int &fps)
{
    updateMoveAndRota(fps);
    if(map.getWorldCase(int(x - planCameraX * move),int(y)) == false) x -= planCameraX * move;
    if(map.getWorldCase(int(x),int(y - planCameraY * move)) == false) y -= planCameraY * move;
    if(map.getWorldCase(int(x - planCameraX * move),int(y)) == 11 && isSneak) x -= planCameraX * move;
    if(map.getWorldCase(int(x),int(y - planCameraY * move)) == 11 && isSneak) y -= planCameraY * move;

    verifyCoord(map);
}

void Entity::moveForward(Map &map,const int &fps)
{
    updateMoveAndRota(fps);
    if(map.getWorldCase(int(x + directionX * move),int(y)) == false) x += directionX * move;
    if(map.getWorldCase(int(x),int(y + directionY * move)) == false) y += directionY * move;
    if(map.getWorldCase(int(x + directionX * move),int(y)) == 11 && isSneak) x += directionX * move;
    if(map.getWorldCase(int(x),int(y + directionY * move)) == 11 && isSneak) y += directionY * move;


    verifyCoord(map);
}
void Entity::moveBackward(Map &map,const int &fps)
{
    updateMoveAndRota(fps);
    if(map.getWorldCase(int(x - directionX * move),int(y)) == false) x -= directionX * move;
    if(map.getWorldCase(int(x),int(y - directionY * move)) == false) y -= directionY * move;
    if(map.getWorldCase(int(x - directionX * move),int(y)) == 11 && isSneak) x -= directionX * move;
    if(map.getWorldCase(int(x),int(y - directionY * move)) == 11 && isSneak) y -= directionY * move;

    verifyCoord(map);
}
void Entity::setSneakTrue()
{
    isSneak =true;
}
void Entity::setSneakFalse()
{
    isSneak =false;
}
bool Entity::isPlayerSneak()
{
    return isSneak;
}

void Entity::verifyCoord(Map &map)
{
    if(x <= 0){x = 0.1;}
    if(x > map.getMapWidth()-1){x = map.getMapWidth()-1;}
    if(y <= 0){y = 0.1;}
    if(y > map.getMapHeight()-1){y = map.getMapHeight()-1;}
}