/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:02:03 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/31 19:07:31 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

void	rotate_left(t_cub_entity *entity)
{
	t_dvec	old_dir;
	t_dvec	old_plan;

	old_dir.x = entity->dir.x;
	entity->dir.x = entity->dir.x * cos(-SPEED_ROTATE) - entity->dir.y \
	* sin(-SPEED_ROTATE);
	entity->dir.y = old_dir.x * sin(-SPEED_ROTATE) + entity->dir.y \
	* cos(-SPEED_ROTATE);
	old_plan.x = entity->plan.x;
	entity->plan.x = entity->plan.x * cos(-SPEED_ROTATE) - entity->plan.y \
	* sin(-SPEED_ROTATE);
	entity->plan.y = old_plan.x * sin(-SPEED_ROTATE) + entity->plan.y \
	* cos(-SPEED_ROTATE);
}

void	rotate_right(t_cub_entity *entity)
{
	t_dvec	old_dir;
	t_dvec	old_plan;

	old_dir.x = entity->dir.x;
	entity->dir.x = entity->dir.x * cos(SPEED_ROTATE) - entity->dir.y \
	* sin(SPEED_ROTATE);
	entity->dir.y = old_dir.x * sin(SPEED_ROTATE) + entity->dir.y \
	* cos(SPEED_ROTATE);
	old_plan.x = entity->plan.x;
	entity->plan.x = entity->plan.x * cos(SPEED_ROTATE) - entity->plan.y \
	* sin(SPEED_ROTATE);
	entity->plan.y = old_plan.x * sin(SPEED_ROTATE) + entity->plan.y \
	* cos(SPEED_ROTATE);
}
