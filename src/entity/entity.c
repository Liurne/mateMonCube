/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:13:50 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/25 16:35:29 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "define.h"

void rotate_left(t_entity *entity)
{
	double old_dir_x;
	double old_plan_x;
	double rotation;

	rotation = 0.04;
	old_dir_x = entity->dir_x;
	entity->dir_x = entity->dir_x * cos(-rotation) - entity->dir_y * sin(-rotation);
	entity->dir_y = old_dir_x * sin(-rotation) + entity->dir_y * cos(-rotation);
	old_plan_x = entity->plan_x;
	entity->plan_x = entity->plan_x * cos(-rotation) - entity->plan_y * sin(-rotation);
	entity->plan_y = old_plan_x * sin(-rotation) + entity->plan_y * cos(-rotation);

}

void rotate_right(t_entity *entity)
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

	move = 0.1;
	if(get_tile(map, (int)(entity->x + entity->dir_x * move), entity->y) == '0')
		entity->x += entity->dir_x * move;
	if(get_tile(map, entity->x, (int)(entity->y + entity->dir_y * move) ) == '0')
		entity->y += entity->dir_y * move;
}

void moveBackward(t_map *map, t_entity *entity)
{
	double move;

	move = 0.1;
	if(get_tile(map, (int)(entity->x - entity->dir_x * move) , (int)(entity->y) ) == '0')
		entity->x -= entity->dir_x * move;
	if(get_tile(map, (int)entity->x , (int)(entity->y - entity->dir_y * move) ) == '0')
		entity->y -= entity->dir_y * move;
	
}

void move_right(t_map *map, t_entity *entity)
{
	double move;

	move = 0.1;
	if(get_tile(map, (int)(entity->x - entity->plan_x * move) , (int)entity->y ) == '0')
		entity->x -= entity->plan_x * move;
	if(get_tile(map, (int)entity->x , (int)(entity->y - entity->plan_y * move) ) == '0')
		entity->y -= entity->plan_y * move;
}

void move_left(t_map *map, t_entity *entity)
{
	double move;

	move = 0.1;
	if(get_tile(map, (int)(entity->x + entity->plan_x * move) , (int)entity->y ) == '0')
		entity->x += entity->plan_x * move;
	if(get_tile(map, (int)entity->x , (int)(entity->y + entity->plan_y * move) ) == '0')
		entity->y += entity->plan_y * move;
}
void	player_manager(t_data *cub)
{
	if (cub->keys.r_left)
		rotate_left(&cub->pl);
	if (cub->keys.r_right)
		rotate_right(&cub->pl);
	if (cub->keys.up)
		moveForward(&cub->map, &cub->pl);
	if (cub->keys.down)
		moveBackward(&cub->map, &cub->pl);
	if (cub->keys.left)
		move_left(&cub->map, &cub->pl);
	if (cub->keys.right)
		move_right(&cub->map, &cub->pl);
}
