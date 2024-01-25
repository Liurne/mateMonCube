/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:34:27 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/25 16:35:43 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//SUD	= dir(0, 1) plan(0.66, 0)
//NORD	= dir(0, -1) plan(-0.66, 0)
//OUEST	= dir(-1, 0) plan(0, 0.66)
//EST	= dir(1, 0) plan(0, -0.66)

void init_entity(t_data *cub, t_entity *entity, double x, double y)
{
	int	i,j;
	entity->x = x;
	entity->y = y;
	entity->w = 16;
	entity->h = 16;
	entity->dir_x = 0;
	entity->dir_y = -1;
	entity->plan_x = -0.66;
	entity->plan_y = 0;
	new_img(cub, &entity->pl, 16, 16);
	i = 0;
	while (i < entity->w)
	{
		j = 0;
		while (j < entity->h)
		{
			put_pixel(&(entity->pl), i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
}