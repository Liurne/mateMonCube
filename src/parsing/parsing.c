/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:48:31 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/05 17:03:04 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(t_data *cub)
{
	int	x;
	int	y;
	cubtransfo(cub, &(cub->map), cub->file);
	new_img(cub, &(cub->map.img), cub->map.w * 128, cub->map.h * 128);
	y = 0;
	while (y < cub->map.h * 128)
	{
		x = 0;
		while (x < cub->map.w * 128)
		{
			if (cub->map.map[x / 128][y / 128] != '1')
				put_pixel(&(cub->map.img), x, y, 0x00FFFFFF);
			x++;
		}
		ft_putstr_fd(cub->map.map[y], 1);
		ft_putstr_fd("\n", 1);
		y++;
	}
	return (0);
}
