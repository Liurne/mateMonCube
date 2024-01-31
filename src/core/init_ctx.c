/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:10:09 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 20:10:09 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

static void	init_entity_plan(t_cub_entity *entity)
{
	if (entity->char_dir == 'N')
	{
		init_dvec(&entity->dir, 0, -1);
		init_dvec(&entity->plan, -0.66, 0);
	}
	else if (entity->char_dir == 'S')
	{
		init_dvec(&entity->dir, 0, 1);
		init_dvec(&entity->plan, 0.66, 0);
	}
	else if (entity->char_dir == 'O')
	{
		init_dvec(&entity->dir, -1, 0);
		init_dvec(&entity->plan, 0, 0.66);
	}
	else if (entity->char_dir == 'E')
	{
		init_dvec(&entity->dir, 1, 0);
		init_dvec(&entity->plan, 0, -0.66);
	}
}

void	init_entity(t_cub_entity *entity, double x, double y)
{
	init_dvec(&entity->pos, x, y);
	entity->w = 16;
	entity->h = 16;
	init_entity_plan(entity);
}

t_uint	init_cub_context(t_cub_context *cubx)
{
	ft_bzero(cubx, sizeof(t_cub_context));
	cubx->lst_map = NULL;
	if (init_gc(cubx) != CONTINUE_PROC)
		return (CUB_CONTEXT_INIT_FAIL);
	return (CONTINUE_PROC);
}
