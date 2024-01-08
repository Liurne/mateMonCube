#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "../core/shape.h"
#include "../map.h"

struct Node
{
    int x,y;
    double wEuc;
    int pas;
    int parent;
    bool looked;
};

struct Verif
{
    int index;
    bool isVisited;
};

class Pathfinding
{
    public:
    Pathfinding(Map &mMap,Point posStart,Point posEnd);
    vector<Node>& FindPath(int posSX,int posSY,int posEX, int posEY);

    private:

    Map &map;
    vector<vector<int>> passage;

    vector<Node> open;
    vector<Node> close;

    vector<Node> ways;
    int index;

    vector<Node> path;
    
    int startX,startY;
    int endX,endY;
    int pas;

    Node minNode();
    bool isThereStillPossibilities();
    bool lookForNeighbores(Node n);

};

#endif