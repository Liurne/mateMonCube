#include "raycast.h"

Raycast::Raycast(Player &p,Map &map,unsigned int wW,unsigned int wH) : player(p), worldMap(map) , windowWidth(wW) , windowHeight(wH) , speWall(false) , isSpe(false)
{
	mapX = int(player.getEntity().x);
	mapY = int(player.getEntity().y);
}

void Raycast::updateRaycast(const unsigned int &x)
{  
	cameraX = 2 * x / double(windowWidth) - 1;
  	directionRayonX = player.getEntity().directionX + player.getEntity().planCameraX * cameraX;
  	directionRayonY = player.getEntity().directionY + player.getEntity().planCameraY * cameraX;

	mapX = int(player.getEntity().x);
	mapY = int(player.getEntity().y);

	distanceProchainX = sqrt(1 + (directionRayonY * directionRayonY) / (directionRayonX * directionRayonX));
	distanceProchainY = sqrt(1 + (directionRayonX * directionRayonX) / (directionRayonY * directionRayonY));

	collision = false;
}

void Raycast::updateStep()
{
	if (directionRayonX < 0)
	{
		pasX = -1;
		prochainX = (player.getEntity().x - mapX) * distanceProchainX;
  		}
  else
	{
		pasX = 1;
		prochainX = (mapX + 1.0 - player.getEntity().x) * distanceProchainX;
  	}
  if (directionRayonY < 0)
	{
		pasY = -1;
		prochainY = (player.getEntity().y - mapY) * distanceProchainY;
  	}
  else
	{
		pasY = 1;
		prochainY = (mapY + 1.0 - player.getEntity().y) * distanceProchainY;
  	}

}

Map& Raycast::getMap(){return worldMap;}

Player& Raycast::getPlayer(){return player;}

double Raycast::getPerpWallDist(int x){return perpWallDist[x];}

double Raycast::getDist(int x){return dist[x];}

int Raycast::getSide(){return side;}

void Raycast::getCollisions()
{
	while (collision == false && mapX > 0 && mapX < (int)worldMap.getMapWidth() && mapY > 0 && mapY < (int)worldMap.getMapHeight())
	{
		if (prochainX < prochainY)
		{
			prochainX += distanceProchainX;
			mapX += pasX;
			side= 0;
		}
		else
		{
			prochainY += distanceProchainY;
			mapY += pasY;
			side= 1;
		}
    	if (worldMap.getWorldCase(mapX,mapY) != 0 && worldMap.getWorldCase(mapX,mapY) < 10)
		{
			collision = true;
		}
		if(worldMap.getWorldCase(mapX,mapY) >= 10){speWall=true;}
	}
	//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
	if(side == 0) perpWallDist.push_back(prochainX - distanceProchainX);
	else          perpWallDist.push_back(prochainY - distanceProchainY);

}

void Raycast::getCollisionsSpe()
{
	while (collision == false && mapX > 0 && mapX < (int)worldMap.getMapWidth() && mapY > 0 && mapY < (int)worldMap.getMapHeight())
	{
		if (prochainX < prochainY)
		{
			prochainX += distanceProchainX;
			mapX += pasX;
			side= 0;
		}
		else
		{
			prochainY += distanceProchainY;
			mapY += pasY;
			side= 1;
		}
    	if (worldMap.getWorldCase(mapX,mapY) != 0)
		{
			collision = true;
		}
	}
	//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
	if(side == 0) perpWallDist.push_back(prochainX - distanceProchainX);
	else          perpWallDist.push_back(prochainY - distanceProchainY);

}

int Raycast::getCase(){return worldMap.getWorldCase(mapX,mapY);}

Line Raycast::getLineForColor(const unsigned int &x,const unsigned int wW,const unsigned int wH)
{
	if(x==0) perpWallDist.clear();
	if(x==0) dist.clear();
	windowWidth=wW;
	windowHeight=wH;
    updateRaycast(x);
    updateStep();
	if(speWall)
	{
		getCollisionsSpe(); 
		isSpe=true;
		speWall=false;
	}
	else{getCollisions();}
	if(collision)
	{
		//correction de l'effet fish-eye
		if(side== 0)
			distance = fabs((mapX - player.getEntity().x + (1 - pasX) / 2) / directionRayonX);
		else
			distance = fabs((mapY - player.getEntity().y + (1 - pasY) / 2) / directionRayonY);

		if(!speWall){dist.push_back(distance);}

		lineHeight = (int)(windowHeight / distance);

		drawStart = -lineHeight / 2 + windowHeight / 2;
		drawEnd = lineHeight / 2 + windowHeight / 2;

		if(isSpe)
		{
			if(worldMap.getWorldCase(mapX,mapY)==10)
			{
				drawStart = -(lineHeight*0.3) /2 + windowHeight / 2;
				isSpe = false;
			}
			if(worldMap.getWorldCase(mapX,mapY)==11)
			{
				drawEnd = (lineHeight*0.3) / 2 + windowHeight / 2;
				isSpe = false;
			}
		}

		if(player.getEntity().isPlayerSneak())
		{
			drawStart -= windowHeight / 2;
			if(worldMap.getWorldCase(mapX,mapY)==11)
			{
				drawEnd *=0.2; 
			}
			else drawEnd *= 0.4;
		}

		if(drawStart < 0)
			drawStart = 0;

		if(drawEnd >= (int)windowWidth)
			drawEnd = windowHeight - 1;

		if(player.getEntity().isPlayerSneak()){return Line(x,drawStart-40,x,drawEnd-40);}
		else{return Line(x,drawStart,x,drawEnd);}

		
	}

	return Line(0,0,0,0);
}

Rectangle Raycast::getRectForTexture(const unsigned int &x,const unsigned int wW,const unsigned int wH,int tW)
{
	if(x==0) perpWallDist.clear();
	if(x==0) dist.clear();
	windowWidth=wW;
	windowHeight=wH;
    updateRaycast(x);
    updateStep();
	if(speWall)
	{
		getCollisionsSpe(); 
		isSpe=true;
		speWall=false;
	}
	else{getCollisions();}

	if(collision)
	{
		//calculate value of wallX
		if (side == 1)
			wallX = player.getEntity().x + ((mapY - player.getEntity().y + (1 - pasY) / 2) / directionRayonY) * directionRayonX;
		else
			wallX = player.getEntity().y + ((mapX - player.getEntity().x + (1 - pasX) / 2) / directionRayonX) * directionRayonY;


		wallX -= floor((wallX));

		//x coordinate on the texture
		texX = int(wallX * double(tW));

		if(side == 0 && directionRayonX > 0) texX = tW - texX - 1;
		if(side == 1 && directionRayonY < 0) texX = tW - texX - 1;

		//correction de l'effet fish-eye
		if(side== 0)
			distance = fabs((mapX - player.getEntity().x + (1 - pasX) / 2) / directionRayonX);
		else
			distance = fabs((mapY - player.getEntity().y + (1 - pasY) / 2) / directionRayonY);
		if(!speWall){dist.push_back(distance);}

		lineHeight = (int)(windowHeight / distance);
		drawStart = -lineHeight / 2 + windowHeight / 2;
		drawEnd = lineHeight / 2 + windowHeight / 2;

		if(isSpe)
		{
			if(worldMap.getWorldCase(mapX,mapY)==10)
			{
				drawStart = -(lineHeight*0.3) /2 + windowHeight / 2;
				isSpe = false;
			}
			if(worldMap.getWorldCase(mapX,mapY)==11)
			{
				drawEnd = (lineHeight*0.3) / 2 + windowHeight / 2;
				isSpe = false;
			}
		}

		
		//if(drawStart < 0)
		//	drawStart = 0;

		if(drawEnd >= (int)windowWidth)
			drawEnd = windowHeight - 1;

		
		if(player.getEntity().isPlayerSneak())
		{
			drawStart -= windowHeight / 2;
			if(worldMap.getWorldCase(mapX,mapY)==11)
			{
				drawEnd *=0.2; 
			}
			else drawEnd *= 0.4;
		}
		
		if(player.getEntity().isPlayerSneak()){return Rectangle(x,drawStart-40,1,drawEnd-drawStart);}
		return Rectangle(x,drawStart,1,drawEnd-drawStart);
	}

	return Rectangle(0,0,0,0);
}

int Raycast::getTexX(){return texX;}

bool Raycast::isSpeWall(){return speWall;}