/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:48:31 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/12 18:23:29 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(t_data *cub)
{
	int	x;
	int	y;
	cubtransfo(cub, &(cub->map), cub->file);
	cub->map.w--;
	cub->map.tile_dim = 64;
	new_img(cub, &(cub->map.img), cub->map.w * cub->map.tile_dim, cub->map.h * cub->map.tile_dim);
	x = 0;
	while (x < cub->map.w * cub->map.tile_dim)
	{
		y = 0;
		while (y < cub->map.h * cub->map.tile_dim)
		{
			if (cub->map.map[x / cub->map.tile_dim][y / cub->map.tile_dim] == '1')
				put_pixel(&(cub->map.img), x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < cub->map.w)
	{
		y = 0;
		while (y < cub->map.h)
		{
			if (cub->map.map[x][y] == 'N')
			{
				cub->map.map[x][y] = '0';
				init_entity(cub, &cub->pl, x * cub->map.tile_dim, y * cub->map.tile_dim);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (0);
}
