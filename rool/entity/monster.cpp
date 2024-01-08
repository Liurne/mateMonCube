#include "monster.h"

Monster::Monster(Map &mMap) : mEntity(15.0,47.0,0.00075,0.0003), originalPosX(15.0) , originalPosY(47.0), find(mMap,Point(17,50),Point(mMap.getSpawnPlayerX(),mMap.getSpawnPlayerY()))
{
    time.start();
    animation.start();
}

void Monster::monsterReset()
{
    mEntity.setPosition(originalPosX,originalPosY);
    updatePath(Point(originalPosX,originalPosY));
}
void Monster::updatePath(const Point posP)
{
    path.clear();
    path = find.FindPath(mEntity.x,mEntity.y,posP.x,posP.y);
}

void Monster::move(Map &m,const Point posP, int fps)
{   
    if(time.getTicks()/1000>3  || (int)path.size()<=1)
    {
        updatePath(posP);
        time.start();
    }
    if(animation.getTicks()>75)
    {
        indexTexture++;
        if(indexTexture>2){indexTexture=0;}
        animation.start();
    }
    if(path.size()>1)
    {
        if((int)mEntity.x==(int)path[1].x && (int)mEntity.y==(int)path[1].y) path.erase(path.begin());
        if((int)mEntity.x<(int)path[1].x){ mEntity.moveBackward(m,fps);}
        if((int)mEntity.x>(int)path[1].x){ mEntity.moveForward(m,fps);}
        if((int)mEntity.y<(int)path[1].y) mEntity.moveRight(m,fps);
        if((int)mEntity.y>(int)path[1].y) mEntity.moveLeft(m,fps); 
    }
}

bool Monster::hasKilledPlayer(Player &p)
{
    if((int)mEntity.x-0.5<(int)p.getEntity().x && (int)mEntity.x+0.5>(int)p.getEntity().x 
            && (int)mEntity.y-0.5<(int)p.getEntity().y && (int)mEntity.y+0.5>(int)p.getEntity().y){
        
        return true;
    }
    return false;
}

void Monster::setMonsterTexture(Window &win,const char* texture)
{
    mTex.setTexture(win,texture);
}

Entity& Monster::getEntity()
{
    return mEntity;
}

Texture& Monster::getTexture()
{
    return mTex;    
}

Rectangle Monster::getPartTexture()
{
    return Rectangle(mTex.getTextureWidth()/3*indexTexture,0,mTex.getTextureWidth()/3,mTex.getTextureHeight());
}

int Monster::getPathSize()
{
    return (int)path.size();
}
Node Monster::getPathCase(int i)
{
    if(i<0 || i>= (int)path.size()) return {0,0,0,0,0};
    return path[i];
}