/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:13:50 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/26 18:02:10 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "define.h"

void rotate_left(t_entity *entity)
{
	double old_dir_x;
	double old_plan_x;

	old_dir_x = entity->dir.x;
	entity->dir.x = entity->dir.x * cos(-SPEED_ROTATE) - entity->dir.y * sin(-SPEED_ROTATE);
	entity->dir.y = old_dir_x * sin(-SPEED_ROTATE) + entity->dir.y * cos(-SPEED_ROTATE);
	old_plan_x = entity->plan.x;
	entity->plan.x = entity->plan.x * cos(-SPEED_ROTATE) - entity->plan.y * sin(-SPEED_ROTATE);
	entity->plan.y = old_plan_x * sin(-SPEED_ROTATE) + entity->plan.y * cos(-SPEED_ROTATE);

}

void rotate_right(t_entity *entity)
{
	double old_dir_x;
	double old_plan_x;

	old_dir_x = entity->dir.x;
	entity->dir.x = entity->dir.x * cos(SPEED_ROTATE) - entity->dir.y * sin(SPEED_ROTATE);
	entity->dir.y = old_dir_x * sin(SPEED_ROTATE) + entity->dir.y * cos(SPEED_ROTATE);
	old_plan_x = entity->plan.x;
	entity->plan.x = entity->plan.x * cos(SPEED_ROTATE) - entity->plan.y * sin(SPEED_ROTATE);
	entity->plan.y = old_plan_x * sin(SPEED_ROTATE) + entity->plan.y * cos(SPEED_ROTATE);
}

void moveForward(t_map *map, t_entity *entity)
{
	if(get_tile(map, (int)(entity->pos.x + entity->dir.x * SPEED_MOVE), entity->pos.y) == '0')
		entity->pos.x += entity->dir.x * SPEED_MOVE;
	if(get_tile(map, entity->pos.x, (int)(entity->pos.y + entity->dir.y * SPEED_MOVE) ) == '0')
		entity->pos.y += entity->dir.y * SPEED_MOVE;
}

void moveBackward(t_map *map, t_entity *entity)
{
	if(get_tile(map, (int)(entity->pos.x - entity->dir.x * SPEED_MOVE) , (int)(entity->pos.y) ) == '0')
		entity->pos.x -= entity->dir.x * SPEED_MOVE;
	if(get_tile(map, (int)entity->pos.x , (int)(entity->pos.y - entity->dir.y * SPEED_MOVE) ) == '0')
		entity->pos.y -= entity->dir.y * SPEED_MOVE;
	
}

void move_right(t_map *map, t_entity *entity)
{
	if(get_tile(map, (int)(entity->pos.x - entity->plan.x * SPEED_MOVE) , (int)entity->pos.y ) == '0')
		entity->pos.x -= entity->plan.x * SPEED_MOVE;
	if(get_tile(map, (int)entity->pos.x , (int)(entity->pos.y - entity->plan.y * SPEED_MOVE) ) == '0')
		entity->pos.y -= entity->plan.y * SPEED_MOVE;
}

void move_left(t_map *map, t_entity *entity)
{
	if(get_tile(map, (int)(entity->pos.x + entity->plan.x * SPEED_MOVE) , (int)entity->pos.y ) == '0')
		entity->pos.x += entity->plan.x * SPEED_MOVE;
	if(get_tile(map, (int)entity->pos.x , (int)(entity->pos.y + entity->plan.y * SPEED_MOVE) ) == '0')
		entity->pos.y += entity->plan.y * SPEED_MOVE;
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
