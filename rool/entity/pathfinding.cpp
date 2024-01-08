#include "pathfinding.h"

Pathfinding::Pathfinding(Map &mMap,Point posStart,Point posEnd) : map(mMap), index(0), startX(posStart.x), startY(posStart.y), endX(posEnd.x), endY(posEnd.y), pas(0)
{
    for(int i=0;i<map.getMapWidth();i++)
    {
        passage.push_back(vector<int>());
        for(int j=0;j<map.getMapHeight();j++){
            passage[i].push_back(0);
        }
    }
}

vector<Node>& Pathfinding::FindPath(int posSX,int posSY,int posEX, int posEY)
{
    if(startX!=posSX || startY!=posSY || endX!=posEX || endY!=posEY)
    {
        startX =posSX;
        startY = posSY;
        endX = posEX;
        endY = posEY;
        pas = 0;
        index=0;
        path.clear();
        ways.clear();
        
        for(int i=0;i<passage.size();i++)
        {
            for(int j=0;j<passage[i].size();j++){
                passage[i][j]=0;
            }
        }
        ways.push_back({startX,startY,sqrt(pow(startX-endX,2)+pow(startY-endY,2)),0,0,true});   

        if(!lookForNeighbores(ways[0]))
        { 
            path.push_back(ways[0]);
            return path;
        }

        int i=ways.size()-1;
        int countK;
        do{
            path.insert(path.begin(), ways[i]);
            i=ways[i].parent;
        }while (path[0].x != startX || path[0].y != startY);
    }

    return path;
}

Node Pathfinding::minNode()
{
    int i=-1;
    do{
        i++;
    }while(ways[i].looked && i<(int)ways.size()-1);
    double minWeight = ways[i].wEuc;
    index=i;

    for(int j = i;j<(int)ways.size();j++)
    {
        if(!ways[j].looked && minWeight>=ways[j].wEuc)
        {
            index = j;
            minWeight = ways[j].wEuc;
        }
    }
    ways[index].looked=true;
    return ways[index];
}

bool Pathfinding::isThereStillPossibilities()
{
    int i=-1;
    do{
        i++;
        if(!ways[i].looked){return true; }
    }while(i<(int)ways.size()-1);
    return false;
}

bool Pathfinding::lookForNeighbores(Node  n)
{
    if(n.x<0 || n.x>=(int)map.getMapWidth() ||n.y<0 || n.y>=(int)map.getMapHeight() || passage[n.x][n.y]>1) {return false;}
    else
    {
        passage[n.x][n.y]++;
        pas++;
        if(map.getWorldCase(n.x,n.y)==0){
            for(int i=n.x-1;i<=n.x+1;i++)
            {
                for(int j=n.y-1;j<=n.y+1;j++)
                {
                    if(i>=0 && i<(int)map.getMapWidth() && j>=0 && j<(int)map.getMapHeight()){
                        if(passage[i][j]==0){
                            ways.push_back({i,j,sqrt(pow(i-endX,2)+pow(j-endY,2)),pas,index,false});
                            passage[i][j]++;
                        }
                    }

                    if(i==endX && j==endY){return true;}
                }
            }
            do
            {
                if(lookForNeighbores(minNode())){return true;}   
            }while(isThereStillPossibilities());
            
        }
        return false;
    }

}
