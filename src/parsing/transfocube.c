/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfocube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:04:01 by liurne            #+#    #+#             */
/*   Updated: 2024/01/05 13:54:17 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	alloc_cub(t_data *cub, t_map *map)
{
	int	i;

	map->map = ft_calloc(map->h + 1, sizeof(char *));
	if (!map->map)
		return (error(cub, ERR_MALLOC));
	i = 0;
	while (i < map->h)
	{
		map->map[i] = ft_calloc(map->w + 1, sizeof(char));
		if (!map->map[i])
			return (free_dtab(map->map), error(cub, ERR_MALLOC));
		i++;
	}
	return (0);
}

static void cpy_cub(t_map *map, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && *str)
	{
		if (*str == '\n')
		{
			i++;
			j = -1;
		}
		else
			map->map[i][j] = *str;
		j++;
		str++;
	}
}

int	cubtransfo(t_data *cub, t_map *map, char *str)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	map->h = 1;
	while (str && str[++i])
	{
		if (str[i] == '\n')
		{
			if (map->w < j)
				map->w = j;
			j = 0;
			map->h++;
		}
		j++;
	}
	if (map->w < j)
		map->w = j;
	alloc_cub(cub, map);
	cpy_cub(map, str);
	return (0);
}
