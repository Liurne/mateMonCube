/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:13:50 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/11 18:51:51 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void rotateLeft(t_map *map, t_entity *entity)
{
	double old_dir_x;
	double old_plan_x;
	double rotation;

	rotation = 0.04;
	old_dir_x = entity->dir_x;
    entity->dir_x = entity->dir_x * cos(rotation) - entity->dir_y * sin(rotation);
    entity->dir_y = old_dir_x * sin(rotation) + entity->dir_y * cos(rotation);

	old_plan_x = entity->plan_x;
    entity->plan_x = entity->plan_x * cos(rotation) - entity->plan_y * sin(rotation);
    entity->plan_y = old_plan_x * sin(rotation) + entity->plan_y * cos(rotation);

}

void moveForward(t_map *map, t_entity *entity)
{
	double move;

	move = 0.01;
	if(map.map[entity->x + entity->dir_x * move][entity->y]) == '0')
		x += entity->dir_x * move;
	if(map.getWorldCase(int(x),int(y + entity->dir_y * move)) == '0')
		y += entity->dir_y * move;
}
/*
void rotateRight(t_map *map, t_entity *entity)
{
    double oldDirX = directionX;
    directionX = directionX * cos(-rotation) - directionY * sin(-rotation);
    directionY = oldDirX * sin(-rotation) + directionY * cos(-rotation);
    double oldPlanX = planCameraX;
    planCameraX = planCameraX * cos(-rotation) - planCameraY * sin(-rotation);
    planCameraY = oldPlanX * sin(-rotation) + planCameraY * cos(-rotation);

}

void moveRight(t_map *map, t_entity *entity)
{
    updateMoveAndRota(fps);
    if(map.getWorldCase(int(x + planCameraX * move),int(y)) == false) x += planCameraX * move;
    if(map.getWorldCase(int(x),int(y + planCameraY * move)) == false) y += planCameraY * move;
    if(map.getWorldCase(int(x + planCameraX * move),int(y)) == 11 && isSneak) x += planCameraX * move;
    if(map.getWorldCase(int(x),int(y + planCameraY * move)) == 11 && isSneak) y += planCameraY * move;
}

void moveLeft(t_map *map, t_entity *entity)
{
    updateMoveAndRota(fps);
    if(map.getWorldCase(int(x - planCameraX * move),int(y)) == false) x -= planCameraX * move;
    if(map.getWorldCase(int(x),int(y - planCameraY * move)) == false) y -= planCameraY * move;
    if(map.getWorldCase(int(x - planCameraX * move),int(y)) == 11 && isSneak) x -= planCameraX * move;
    if(map.getWorldCase(int(x),int(y - planCameraY * move)) == 11 && isSneak) y -= planCameraY * move;
}

void moveBackward(t_map *map, t_entity *entity)
{
    updateMoveAndRota(fps);
    if(map.getWorldCase(int(x - directionX * move),int(y)) == false) x -= directionX * move;
    if(map.getWorldCase(int(x),int(y - directionY * move)) == false) y -= directionY * move;
    if(map.getWorldCase(int(x - directionX * move),int(y)) == 11 && isSneak) x -= directionX * move;
    if(map.getWorldCase(int(x),int(y - directionY * move)) == 11 && isSneak) y -= directionY * move;
}*/