/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_map_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:50:41 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/13 12:54:35 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	add_map_to_lst(t_cub_context *cubx, t_uint fd)
{
	t_uint	status;
	t_str	line;

	status = CONTINUE_PROC;
	line = get_next_line(fd);
	while (line != NULL)
	{
		status = lst_add_back(cubx, &cubx->lst_map, ft_strdup(cubx, line));
		if (status != CONTINUE_PROC)
			return (status);
		free(line);
		line = get_next_line(fd);
	}
	lst_print(&cubx->lst_map, "%s");
	return (CONTINUE_PROC);
}
