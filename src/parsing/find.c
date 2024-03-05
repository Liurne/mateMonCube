/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:46:19 by bfaure            #+#    #+#             */
/*   Updated: 2024/03/01 13:02:03 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

t_uint	find_we_no(t_cub_context *cubx, t_str line)
{
	while (ft_isspace(*line))
		line++;
	if (!*line)
		return (CONTINUE_PROC);
	if (line[0] == 'W' && line[1] == 'E')
		return (handle_we(cubx, line));
	else if (line[0] == 'N' && line[1] == 'O')
		return (handle_no(cubx, line));
	else if (check_id(cubx, line, 0) == 1)
		return (BAD_ID);
	return (CONTINUE_PROC);
}

t_uint	find_ea_so(t_cub_context *cubx, t_str line)
{
	while (ft_isspace(*line))
		line++;
	if (!*line)
		return (CONTINUE_PROC);
	if (line[0] == 'E' && line[1] == 'A')
		return (handle_ea(cubx, line));
	else if (line[0] == 'S' && line[1] == 'O')
		return (handle_so(cubx, line));
	else if (check_id(cubx, line, 1) == 1)
		return (BAD_ID);
	return (CONTINUE_PROC);
}

t_uint	handle_color_f(t_cub_context *cubx, t_str line)
{
	if (cubx->find.f != 0)
		return (TOO_MANY_CO_ID);
	cubx->find.f = 1;
	return (pars_color(cubx, line, 'F'));
}

t_uint	handle_color_c(t_cub_context *cubx, t_str line)
{
	if (cubx->find.c != 0)
		return (TOO_MANY_CO_ID);
	cubx->find.c = 1;
	return (pars_color(cubx, line, 'C'));
}

t_uint	find_color(t_cub_context *cubx, t_str line)
{
	while (ft_isspace(*line))
		line++;
	if (!*line)
		return (CONTINUE_PROC);
	if (line[0] == 'F')
		return (handle_color_f(cubx, line));
	else if (line[0] == 'C')
		return (handle_color_c(cubx, line));
	else if (check_id(cubx, line, 0) == 1 && check_id(cubx, line, 1) == 1)
		return (BAD_ID);
	return (CONTINUE_PROC);
}
