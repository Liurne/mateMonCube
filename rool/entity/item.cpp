 #include "item.h"

Item::Item()
{

}

Item::Item(const char* name) : id(name) , mEntity(0,0,0,0)
{

}

void Item::itemReset()
{
    inWorld=true;
    mEntity.setPosition(originalPosX,originalPosY);
}

const char * Item::getId()
{
    return id;
}
Entity& Item::getEntity()
{
    return mEntity;
}

Texture& Item::getTexture()
{
    return mTex;    
}

void Item::setItemTexture(Window &win,const char* texture)
{
    mTex.setTexture(win,texture);
}

void Item::setPostion(double x,double y)
{
    inWorld = true;
    mEntity.setPosition(x,y);
    originalPosX = x;
    originalPosY = y;
}

void Item::setItemId(const char* nameId)
{
    id = nameId;
}

bool Item::isInWorld()
{
    return inWorld;
}
bool Item::isItemPicked(Player &p)
{
    if(p.getEntity().x>=mEntity.x-1 && p.getEntity().x<=mEntity.x+1 && p.getEntity().y>=mEntity.y-1 && p.getEntity().y<=mEntity.y+1 && inWorld)
    {
        inWorld = false;
        return true;
    }
    return false;
}