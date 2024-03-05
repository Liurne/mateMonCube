/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_graphic_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:15:35 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 19:15:35 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

t_uint	remove_spaces_path(t_cub_context *cubx, t_str line)
{
	t_uint	i;

	i = 2;
	while (ft_isspace(line[i]))
	{
		if (line[i] == '\n')
		{
			printf("Error\nMissing texture\n");
			free(line);
			ft_clear(cubx);
		}
		i++;
	}
	return (i);
}

t_uint	pars_graphic_path(t_cub_context *cubx, t_str line, t_uint n)
{
	t_str			path;
	t_uint			i;

	i = remove_spaces_path(cubx, line);
	path = ft_substr(cubx, line, i, ft_strlen(line));
	if (!path)
		return (MALLOC_FAIL);
	if (load_img(cubx, path, n) != CONTINUE_PROC)
		return (cubx->gc->free(cubx, path), IMG_INIT_FAIL);
	if (path)
		cubx->gc->free(cubx, path);
	return (CONTINUE_PROC);
}
