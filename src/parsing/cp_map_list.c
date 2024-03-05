/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_map_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:50:41 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/21 17:46:06 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

t_uint	add_map_to_lst(t_cub_context *cubx, t_str line)
{
	t_uint	status;
	t_uint	i;

	status = CONTINUE_PROC;
	i = 0;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (i + 1 < ft_strlen(line))
	{
		if (!((line[i] == '1' || line[i] == '0')
				&& (line[i + 1] == '1' || line[i + 1] == '0')))
		{
			free(line);
			line = get_next_line(cubx->fd);
		}
	}
	while (line != NULL)
	{
		status = lst_add_back(cubx, &cubx->lst_map, ft_strdup(cubx, line));
		if (status != CONTINUE_PROC)
			return (status);
		free(line);
		line = get_next_line(cubx->fd);
	}
	return (CONTINUE_PROC);
}
