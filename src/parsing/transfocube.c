/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfocube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:04:01 by liurne            #+#    #+#             */
/*   Updated: 2024/01/08 18:40:52 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	alloc_cub(t_data *cub, t_map *map)
{
	int	i;

	map->map = ft_calloc(map->w + 1, sizeof(char *));
	if (!map->map)
		return (error(cub, ERR_MALLOC));
	i = 0;
	while (i < map->w)
	{
		map->map[i] = ft_calloc(map->h + 1, sizeof(char));
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
			map->map[j][i] = *str;
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
	printf("yup\n");
	alloc_cub(cub, map);
	printf("pute\n");
	cpy_cub(map, str);
	printf("tepu\n");
	return (0);
}
