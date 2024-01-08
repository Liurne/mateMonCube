#include "map.h"

Map::Map(string fileName)
{    
    ifstream i(fileName);
    nlohmann::json j;
    i >> j;
    i.close();
    w = j["width"];
    h = j["height"];
    worldMap = j["map"].get<vector<vector<int>>>();
    originalMap = j["map"].get<vector<vector<int>>>();

    pSpawnX = j["pSpawnX"];
    pSpawnY = j["pSpawnY"];

}

void Map::mapReset()
{
    for(int i=0;i<(int)worldMap.size();i++)
        for(int j=0;j<(int)worldMap[0].size();j++)
            worldMap[i][j] = originalMap[i][j];
}
int Map::getWorldCase(int x,int y)
{
    if(x < 0 || x > (int)w-1 || y < 0 || y  > (int)h-1){return -1;}
    return worldMap[x][y];
}

unsigned int Map::getMapWidth()
{
    return w;
}
unsigned int Map::getMapHeight()
{
    return h;
}

void Map::setMapCase(int x,int y,int v)
{
    if(x>0 && x<worldMap.size() && y>0 && y<worldMap[0].size())
        worldMap[x][y]=v;
}

void Map::clearDoor(int x,int y)
{
   if(getWorldCase(x,y)==10)
   {
        setMapCase(x,y,0);
        for(int i = (int)x-1;i<=(int)x+1;i++)
            for(int j = (int)y-1;j<=(int)y+1;j++)
                clearDoor(i,j);
  }
}

double Map::getSpawnPlayerX(){return pSpawnX;}
double Map::getSpawnPlayerY(){return pSpawnY;}
