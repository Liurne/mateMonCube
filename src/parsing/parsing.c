/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:48:31 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/08 18:45:16 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(t_data *cub)
{
	int	x;
	int	y;
	cubtransfo(cub, &(cub->map), cub->file);
	cub->map.w--;
	new_img(cub, &(cub->map.img), cub->map.w * 64, cub->map.h * 64);
	x = 0;
	while (x < cub->map.w * 64)
	{
		y = 0;
		while (y < cub->map.h * 64)
		{
			if (cub->map.map[x / 64][y / 64] != '0')
				put_pixel(&(cub->map.img), x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	return (0);
}
