#include "player.h"
#include "item.h"

Player::Player(const char * name_,const double x, const double y,const double moveSpeed,const double rotaSpeed) : mEntity(x,y,moveSpeed,rotaSpeed),
        originalPosX(x),originalPosY(y)
{
  name = name_;
  key = 0;
}

void Player::playerReset()
{
  mEntity.setPosition(originalPosX,originalPosY);
  key=0;
}

Entity& Player::getEntity()
{
  return mEntity;
}

const char * Player::getPlayerName()
{
  return name;
}

int Player::getNumberKey()
{
  return key;
}

void Player::addItem(const char * idItem)
{
  if(strcmp(idItem,"key") == 0) 
  {
    key++;
    cout<<"+key"<<endl;
  }
  if(strcmp(idItem,"battery") == 0) {cout<<"+battery"<<endl;}
}


void Player::coutPosMap(Map &map)
{
    for(int i=0;i<(int)map.getMapWidth();i++)
        cout<<"==";
    cout<<endl;
    for(int i=0;i<(int)map.getMapWidth();i++)
    {
        for(int j=0;j<(int)map.getMapHeight();j++)
        {
            if(i==(int)mEntity.x && j==(int)mEntity.y){cout<<"*,";}
            else{cout<<map.getWorldCase(i,j)<<",";}
        }
        cout<<endl;
    }
    for(int i=0;i<(int)map.getMapWidth();i++)
        cout<<"==";
    cout<<endl;
}

bool Player::isNearDoor(Map &m)
{
  for(int i = (int)mEntity.x-1;i<=(int)mEntity.x+1;i++)
    for(int j = (int)mEntity.y-1;j<=(int)mEntity.y+1;j++)
      if(m.getWorldCase(i,j)==10){return true;}
  return false;
}

bool Player::isNearSneakDoor(Map &m)
{
  for(int i = (int)mEntity.x-1;i<=(int)mEntity.x+1;i++)
    for(int j = (int)mEntity.y-1;j<=(int)mEntity.y+1;j++)
      if(m.getWorldCase(i,j)==11){return true;}
  return false;
}

void Player::openDoor(Map &m)
{
    if(isNearDoor(m))
    {
      for(int i = (int)mEntity.x-1;i<=(int)mEntity.x+1;i++)
        for(int j = (int)mEntity.y-1;j<=(int)mEntity.y+1;j++)
          if(m.getWorldCase(i,j)==10 && key>0)
          {
            key--;
            m.clearDoor(i,j);
          }
    }
}

bool Player::isNearFinalDoor(Map &m)
{
  for(int i = (int)mEntity.x-1;i<=(int)mEntity.x+1;i++)
    for(int j = (int)mEntity.y-1;j<=(int)mEntity.y+1;j++)
      if(m.getWorldCase(i,j)==12){return true;}
  return false;
}
void Player::openFinalDoor(Map &m,bool isGeneratorOk,bool &isGameWin)
{
  if(isNearFinalDoor(m) && isGeneratorOk)
  {
    isGameWin=true;
  }
}



