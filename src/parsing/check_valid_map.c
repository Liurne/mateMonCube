/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:10:58 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/29 16:02:15 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

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

t_uint	check_char(t_cub_context *cubx)
{
	t_uint	x;
	t_uint	y;
	t_uint	find;

	find = 0;
	y = 0;
	while (cubx->map.map[y] && y <= cubx->map.h)
	{
		x = 0;
		while (cubx->map.map[y][x] && x <= cubx->map.w)
		{
			if (is_player(cubx->map.map[y][x]))
				find++;
			if (find > 1)
				return (PLAYER_ERROR);
			if (cubx->map.map[y][x] != 'N' && cubx->map.map[y][x] != 'S'
				&& cubx->map.map[y][x] != 'W' && cubx->map.map[y][x] != 'E'
				&& cubx->map.map[y][x] != '1' && cubx->map.map[y][x] != '0'
				&& cubx->map.map[y][x] != ' ' && cubx->map.map[y][x] != '\n')
				return (WRONG_CHAR);
			x++;
		}
		y++;
	}
	return (CONTINUE_PROC);
}
