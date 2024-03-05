/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:01:56 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/21 17:45:49 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

void	move_forward(t_map *map, t_cub_entity *entity)
{
	t_dvec	new_pos;

	new_pos.x = entity->pos.x + entity->dir.x * SPEED_MOVE;
	new_pos.y = entity->pos.y + entity->dir.y * SPEED_MOVE;
	if (0 < new_pos.x && new_pos.x < map->w - 1
		&& get_tile(map, new_pos.x, entity->pos.y) == '0')
		entity->pos.x = new_pos.x;
	if (0 < new_pos.y && new_pos.y < map->h - 1
		&& get_tile(map, entity->pos.x, new_pos.y) == '0')
		entity->pos.y = new_pos.y;
}

void	move_backward(t_map *map, t_cub_entity *entity)
{
	t_dvec	new_pos;

	new_pos.x = entity->pos.x - entity->dir.x * SPEED_MOVE;
	new_pos.y = entity->pos.y - entity->dir.y * SPEED_MOVE;
	if (0 < new_pos.x && new_pos.x < map->w - 1
		&& get_tile(map, new_pos.x, entity->pos.y) == '0')
		entity->pos.x = new_pos.x;
	if (0 < new_pos.y && new_pos.y < map->h - 1
		&& get_tile(map, entity->pos.x, new_pos.y) == '0')
		entity->pos.y = new_pos.y;
}

void	move_right(t_map *map, t_cub_entity *entity)
{
	t_dvec	new_pos;

	new_pos.x = entity->pos.x - entity->plan.x * SPEED_MOVE;
	new_pos.y = entity->pos.y - entity->plan.y * SPEED_MOVE;
	if (0 < new_pos.x && new_pos.x < map->w - 1
		&& get_tile(map, new_pos.x, entity->pos.y) == '0')
		entity->pos.x = new_pos.x;
	if (0 < new_pos.y && new_pos.y < map->h - 1
		&& get_tile(map, entity->pos.x, new_pos.y) == '0')
		entity->pos.y = new_pos.y;
}

void	move_left(t_map *map, t_cub_entity *entity)
{
	t_dvec	new_pos;

	new_pos.x = entity->pos.x + entity->plan.x * SPEED_MOVE;
	new_pos.y = entity->pos.y + entity->plan.y * SPEED_MOVE;
	if (0 < new_pos.x && new_pos.x < map->w - 1
		&& get_tile(map, new_pos.x, entity->pos.y) == '0')
		entity->pos.x = new_pos.x;
	if (0 < new_pos.y && new_pos.y < map->h - 1
		&& get_tile(map, entity->pos.x, new_pos.y) == '0')
		entity->pos.y = new_pos.y;
}
