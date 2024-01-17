/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:13 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/17 17:53:08 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

  private:
    Player& player;
    Map& worldMap;
    unsigned int windowWidth,windowHeight;
    vector<double> perpWallDist;
    vector<double> dist;

    double cameraX; // Point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
    double directionRayonX; // Calcul de direction x du rayon
    double directionRayonY; // Calcul de direction Y du rayon

    // Coordonée x et y du carré dans lequel est positionX/Y
    int mapX;
    int mapY;

    // Distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x) ou horizontal (=un coté y)
    double prochainX;
    double prochainY;

    // Distance que rayon parcours entre chaque point d'intersection vertical/horizontal
    double distanceProchainX;
    double distanceProchainY;
    double distance; // Distance du joueur au mur

    int pasX; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
    int pasY; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive

    bool collision; // True si le mur à été touché, false sinon
    int side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
    int lineHeight; // Hauteur de la ligne a dessiner
    int drawStart; // Position de debut ou il faut dessiner
    int drawEnd; // Position de fin ou il faut dessiner

    double wallX;
    int texX;

    bool speWall;
    bool isSpe;
    int nbSpe;

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

int Raycast::getCase(){return worldMap.getWorldCase(mapX,mapY);}

Line Raycast::getLineForColor(const unsigned int &x,const unsigned int wW,const unsigned int wH)
{
	if(x==0) perpWallDist.clear();
	if(x==0) dist.clear();
	windowWidth=wW;
	windowHeight=wH;
    updateRaycast(x);
    updateStep();
	getCollisions();
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

void	raycast(t_data *cub)
{
	int i;

	i = 0;
	while (i < cub->win.w)
	{
		
		i++;
	}
}
