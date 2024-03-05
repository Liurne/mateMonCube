/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:30:25 by bfaure            #+#    #+#             */
/*   Updated: 2024/03/01 13:39:58 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

bool	check_id(t_cub_context *cubx, t_str line, t_uint c)
{
	if (c == 0)
		return (line[0] != ' ' && line[0] != 'F' && line[0] != 'C'
			&& !(line[0] == 'E' && line[1] == 'A') && is_finish(cubx, line) == 0
			&& !(line[0] == 'S' && line[1] == 'O') && line[0] != '\n');
	else if (c == 1)
		return (line[0] != ' ' && line[0] != 'F' && line[0] != 'C'
			&& !(line[0] == 'W' && line[1] == 'E') && is_finish(cubx, line) == 0
			&& !(line[0] == 'N' && line[1] == 'O') && line[0] != '\n');
	return (1);
}

t_uint	handle_we(t_cub_context *cubx, t_str line)
{
	if (cubx->find.we != 0)
		return (TOO_MANY_TX_ID);
	cubx->find.we = 1;
	return (pars_graphic_path(cubx, line, 0));
}

t_uint	handle_no(t_cub_context *cubx, t_str line)
{
	if (cubx->find.no != 0)
		return (TOO_MANY_TX_ID);
	cubx->find.no = 1;
	return (pars_graphic_path(cubx, line, 1));
}

t_uint	handle_ea(t_cub_context *cubx, t_str line)
{
	if (cubx->find.ea != 0)
		return (TOO_MANY_TX_ID);
	cubx->find.ea = 1;
	return (pars_graphic_path(cubx, line, 2));
}

t_uint	handle_so(t_cub_context *cubx, t_str line)
{
	if (cubx->find.so != 0)
		return (TOO_MANY_TX_ID);
	cubx->find.so = 1;
	return (pars_graphic_path(cubx, line, 3));
}
