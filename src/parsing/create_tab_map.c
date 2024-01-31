/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:25:18 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/10 23:25:18 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	create_tab_map(t_cub_context *cubx)
{
	t_uint	i;
	t_list	*current;
	char	*map_data;

	i = 0;
	current = cubx->lst_map;
	map_data = NULL;
	cubx->map.map = gc_malloc(cubx, sizeof(char *) * (cubx->map.h + 1), false);
	if (cubx->map.map == NULL)
		return (MALLOC_FAIL);
	while (current)
	{
		map_data = current->data;
		if (map_data[0] == '\0' || map_data[0] == '\n')
		{
			current = current->next;
			continue ;
		}
		cubx->map.map[i] = ft_strndup(cubx, (char *)(current)->data, cubx->map.w);
		i++;
		current = current->next;
	}
	cubx->map.map[i] = NULL;
	return (CONTINUE_PROC);
}

t_uint	back_to_normal_map(t_cub_context *cubx)
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
			if (cubx->map.map[i][j] == '*')
				cubx->map.map[i][j] = '0';
			j++;
		}
		i++;
	}
	return (CONTINUE_PROC);
}
