#include "generator.h"

Generator::Generator(const double x, const double y) : mEntity(x,y,0,0) , isActivate(false)
{

}

void Generator::generatorReset()
{
    isActivate=false;
}

Entity& Generator::getEntity()
{
    return mEntity;
}

Texture& Generator::getTexture()
{
    return mTex;
}

void Generator::setGeneratorTexture(Window &win,const char* texture)
{
    mTex.setTexture(win,texture);
}

bool Generator::isNearGenerator(Player &p)
{
    if(p.getEntity().x>=mEntity.x-1 && p.getEntity().x<=mEntity.x+1 && p.getEntity().y>=mEntity.y-1 && p.getEntity().y<=mEntity.y+1)
    {
        return true;
    }
    return false;
}

void Generator::activateGenerator()
{
    isActivate=true;
}
bool Generator::isGeneratorActivate()
{
    return isActivate;
}