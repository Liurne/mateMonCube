/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:10:58 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/31 18:02:06 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	check_player_evo(t_cub_context *cubx, t_uint x, t_uint y, t_uint check)
{
	if (x > 0 && cubx->map.map[y][x - 1] == '0')
	{
		cubx->map.map[y][x - 1] = '*';
		check = 1;
	}
	if (cubx->map.map[y][x + 1] == '0')
	{
		cubx->map.map[y][x + 1] = '*';
		check = 1;
	}
	if (y > 0 && cubx->map.map[y - 1][x] == '0')
	{
		cubx->map.map[y - 1][x] = '*';
		check = 1;
	}
	if (y + 1 == cubx->map.h)
		return (0);
	if (cubx->map.map[y + 1][x] == '0')
	{
		cubx->map.map[y + 1][x] = '*';
		check = 1;
	}
	return (check);
}

t_uint	check_hole(t_cub_context *cubx, t_uint x, t_uint y)
{
	if (x <= 0)
		return (MAP_ERROR);
	if (cubx->map.map[y][x - 1] != '1' && cubx->map.map[y][x - 1] != '*')
		return (MAP_ERROR);
	if (cubx->map.map[y][x + 1] != '1' && cubx->map.map[y][x + 1] != '*')
		return (MAP_ERROR);
	if (y <= 0)
		return (MAP_ERROR);
	if (cubx->map.map[y - 1][x] != '1' && cubx->map.map[y - 1][x] != '*')
		return (MAP_ERROR);
	if (y + 1 == cubx->map.h)
		return (MAP_ERROR);
	if (cubx->map.map[y + 1][x] != '1' && cubx->map.map[y + 1][x] != '*')
		return (MAP_ERROR);
	return (CONTINUE_PROC);
}

t_uint	check_anomaly(t_cub_context *cubx)
{
	t_uint	x;
	t_uint	y;

	y = 0;
	while (cubx->map.map[y] && y <= cubx->map.h)
	{
		printf("%s\n", cubx->map.map[y]);
		x = 0;
		while (cubx->map.map[y][x] && x <= cubx->map.w)
		{
			if (cubx->map.map[y][x] == '*')
			{
				if (check_hole(cubx, x, y) != CONTINUE_PROC)
					return (MAP_ERROR);
			}
			x++;
		}
		y++;
	}
	return (CONTINUE_PROC);
}

t_uint	check_valid_map(t_cub_context *cubx)
{
	t_uint	x;
	t_uint	y;
	t_uint	check;

	check = 1;
	cubx->map.map[(t_uint)cubx->player.pos.y][(t_uint)cubx->player.pos.x] = '*';
	while (check == 1)
	{
		check = 0;
		y = 0;
		while (cubx->map.map[y] && y <= cubx->map.h)
		{
			x = 0;
			while (cubx->map.map[y][x] && x <= cubx->map.w)
			{
				if (cubx->map.map[y][x] == '*')
					check = check_player_evo(cubx, x, y, check);
				x++;
			}
			y++;
		}
	}
	return (check_anomaly(cubx));
}
