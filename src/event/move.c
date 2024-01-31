/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:01:56 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/31 19:06:13 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

void	move_forward(t_map *map, t_cub_entity *entity)
{
	(void)map;
	entity->pos.x += entity->dir.x * SPEED_MOVE;
	entity->pos.y += entity->dir.y * SPEED_MOVE;
}

void	move_backward(t_map *map, t_cub_entity *entity)
{
	(void)map;
	entity->pos.x -= entity->dir.x * SPEED_MOVE;
	entity->pos.y -= entity->dir.y * SPEED_MOVE;
}

void	move_right(t_map *map, t_cub_entity *entity)
{
	(void)map;
	entity->pos.x -= entity->plan.x * SPEED_MOVE;
	entity->pos.y -= entity->plan.y * SPEED_MOVE;
}

void	move_left(t_map *map, t_cub_entity *entity)
{
	(void)map;
	entity->pos.x += entity->plan.x * SPEED_MOVE;
	entity->pos.y += entity->plan.y * SPEED_MOVE;
}
