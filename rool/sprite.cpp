#include "sprite.h"

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

Rectangle Sprite::spriteItem(Window &win,Player &p,Item &i)
{
    return updateSprite(win,p,i.getEntity());
}
Rectangle Sprite::spriteMonster(Window &win,Player &p,Monster &m)
{
    return updateSprite(win,p,m.getEntity());
}
Rectangle Sprite::spriteGenerator(Window &win,Player &p,Generator &g)
{
    return updateSprite(win,p,g.getEntity());
}

Rectangle Sprite::updateSprite(Window &win,Player &p,Entity &e)
{
    spriteX = e.x - p.getEntity().x;
    spriteY = e.y - p.getEntity().y;

    invDet = 1.0 / (p.getEntity().planCameraX * p.getEntity().directionY - p.getEntity().directionX * p.getEntity().planCameraY);

    transformX = invDet * (p.getEntity().directionY * spriteX - p.getEntity().directionX * spriteY);
    transformY = invDet * (-p.getEntity().planCameraY * spriteX + p.getEntity().planCameraX * spriteY);

    spriteScreenX = int((win.getWindowWidth() / 2) * (1 + transformX / transformY));

    //calculate height of the sprite on screen
    spriteHeight = abs(int(win.getWindowHeight() / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
    //calculate lowest and highest pixel to fill in current stripe
    drawStartY = -spriteHeight / 2 + win.getWindowHeight() / 2;
    if(drawStartY < 0) drawStartY = 0;
    drawEndY = spriteHeight / 2 + win.getWindowHeight() / 2;
    if(drawEndY >= (int)win.getWindowHeight()) drawEndY = win.getWindowHeight() - 1;

    //calculate width of the sprite
    spriteWidth = abs( int (win.getWindowHeight() / (transformY)));
    drawStartX = -spriteWidth / 2 + spriteScreenX;
    if(drawStartX < 0) drawStartX = 0;
    drawEndX = spriteWidth / 2 + spriteScreenX;
    if(drawEndX >= (int)win.getWindowWidth() && drawStartX !=0) drawEndX = win.getWindowWidth() - 1;

    if(p.getEntity().isPlayerSneak())
    {
        drawStartY -= win.getWindowWidth() / 2;
        drawEndY *= 0.4;
    }
    
    //if(p.getEntity().isPlayerSneak()){return Rectangle(drawStartX, drawStartY-40, drawEndX-drawStartX, drawEndY-drawStartY);}
    return Rectangle(drawStartX, drawStartY, drawEndX-drawStartX, drawEndY-drawStartY);
}

bool Sprite::isLineValid(Window &win,Raycast &r,int x)
{
    if(transformY > 0 && x > 0 && x < (int)win.getWindowWidth() && transformY < r.getDist(x))
    {
            return true;
    }
    return false;
}



