/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:12:36 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/10 23:12:36 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

t_uint	find_player(t_cub_context *cubx)
{
	t_uint	i;
	t_uint	j;

	i = 0;
	j = 0;
	while (cubx->map.map[i] != NULL)
	{
		j = 0;
		while (cubx->map.map[i][j] != '\0')
		{
			if (cubx->map.map[i][j] == 'N' || cubx->map.map[i][j] == 'S'
				|| cubx->map.map[i][j] == 'E' || cubx->map.map[i][j] == 'W')
			{
				cubx->player.char_dir = cubx->map.map[i][j];
				init_entity(&cubx->player, (double)j + 0.5, (double)i + 0.5);
				cubx->map.map[i][j] = '0';
				return (CONTINUE_PROC);
			}
			j++;
		}
		i++;
	}
	return (MAP_ERROR);
}

t_uint	is_tab(t_cub_context *cubx,
	t_str map_data, t_str str_space, t_list *current)
{
	t_uint	i;

	i = 0;
	while (map_data[i] != '\0')
	{
		if (map_data[i] == '\t')
		{
			str_space = NULL;
			while (map_data[i] == '\t')
			{
				map_data[i] = ' ';
				str_space = ft_strjoin(cubx, str_space, "   ");
				if (str_space == NULL)
					return (MALLOC_FAIL);
			}
			current->data = ft_strjoin(cubx, str_space, map_data);
			if (current->data == NULL)
				return (MALLOC_FAIL);
			map_data = (char *)(current)->data;
			i += 3;
		}
		i++;
	}
	return (CONTINUE_PROC);
}

t_uint	remplace_tab_space(t_cub_context *cubx)
{
	t_list	*current;
	t_str	map_data;
	t_str	str_space;

	current = cubx->lst_map;
	map_data = NULL;
	str_space = NULL;
	while (current)
	{
		map_data = (char *)(current)->data;
		if (is_tab(cubx, map_data, str_space, current) != CONTINUE_PROC)
			return (MALLOC_FAIL);
		current = current->next;
	}
	return (CONTINUE_PROC);
}

t_uint	find_sizes(t_cub_context *cubx)
{
	t_uint	i;
	t_uint	size_x;
	t_uint	size_y;
	t_list	*current;
	char	*map_data;

	size_x = 0;
	size_y = 0;
	current = cubx->lst_map;
	while (current)
	{
		i = 0;
		map_data = (char *)(current)->data;
		while (map_data[i])
		{
			if (i > size_x)
				size_x = i;
			i++;
		}
		size_y++;
		current = current->next;
	}
	cubx->map.w = size_x;
	cubx->map.h = size_y;
	return (CONTINUE_PROC);
}

t_uint	check_map(t_cub_context *cubx)
{
	t_uint	status;

	status = remplace_tab_space(cubx);
	if (status != CONTINUE_PROC)
		return (status);
	status = find_sizes(cubx);
	if (status != CONTINUE_PROC)
		return (status);
	status = create_tab_map(cubx);
	if (status != CONTINUE_PROC)
		return (status);
	status = check_char(cubx);
	if (status != CONTINUE_PROC)
		return (status);
	status = find_player(cubx);
	if (status != CONTINUE_PROC)
		return (status);
	status = check_valid_map(cubx);
	if (status != CONTINUE_PROC)
		return (status);
	return (status);
}
