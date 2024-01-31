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

# include "../../xenocube.h"

t_uint	pars_graphic_path(t_cub_context *cubx, t_str line, int fd, t_uint n)
{
	t_uint			i;
	t_str			path;

	i = 2;
	while (ft_isspace(line[i]))
	{
		if (line[i] == '\n')
		{
			line = get_next_line(fd);
			if (line == NULL)
				return (MALLOC_FAIL);
			i = 0;
			continue ;
		}
		i++;
	}
	path = ft_substr(cubx, line, i, ft_strlen(line));
	if (path == NULL)
		return (MALLOC_FAIL);
	printf("path = %s\n", path);
	if (load_img(cubx, path, n) != CONTINUE_PROC)
		return (cubx->gc->free(cubx, path), MALLOC_FAIL);
	cubx->gc->free(cubx, path);
	printf("pars_graphic_path img.img = %p\n", cubx->img[n].img);
	return (CONTINUE_PROC);
}

t_uint	f_color(t_cub_context *cubx, t_str *color, int bg)
{
	if (bg == 'F')
	{
		cubx->color_f.r = ft_atoi(color[0]);
		if (cubx->color_f.r > 255 || cubx->color_f.r < 0)
			return (DONT_FUCK_WITH_ME);
		cubx->color_f.g = ft_atoi(color[1]);
		if (cubx->color_f.g > 255 || cubx->color_f.g < 0)
			return (DONT_FUCK_WITH_ME);
		cubx->color_f.b = ft_atoi(color[2]);
		if (cubx->color_f.b > 255 || cubx->color_f.b < 0)
			return (DONT_FUCK_WITH_ME);
	}
	return (CONTINUE_PROC);
}

t_uint	c_color(t_cub_context *cubx, t_str *color, int bg)
{
	if (bg == 'C')
	{
		cubx->color_c.r = ft_atoi(color[0]);
		if (cubx->color_c.r > 255 || cubx->color_c.r < 0)
			return (DONT_FUCK_WITH_ME);
		cubx->color_c.g = ft_atoi(color[1]);
		if (cubx->color_c.g > 255 || cubx->color_c.g < 0)
			return (DONT_FUCK_WITH_ME);
		cubx->color_c.b = ft_atoi(color[2]);
		if (cubx->color_c.b > 255 || cubx->color_c.b < 0)
			return (DONT_FUCK_WITH_ME);
	}
	return (CONTINUE_PROC);
}

t_uint	pars_color(t_cub_context *cubx, t_str line, int bg, int fd)
{
	t_str			*color;

	line++;
	while (ft_isspace((int)*line) && line != NULL)
	{
		if (*line == '\n')
		{
			line = get_next_line(fd);
			line++;
			continue ;
		}
		line++;
	}
	color = ft_split(cubx, line, ',');
	if (color == NULL)
		return (MALLOC_FAIL);
	if (f_color(cubx, color, bg) != CONTINUE_PROC)
		return (DONT_FUCK_WITH_ME);
	if (c_color(cubx, color, bg) != CONTINUE_PROC)
		return (DONT_FUCK_WITH_ME);
	ft_free_tab(cubx, color);
	printf("cubx->color_f.r = %i\ncubx->color_f.g = %i\ncubx->color_f.b = %i\n", cubx->color_f.r, cubx->color_f.g, cubx->color_f.b);
	printf("cubx->color_c.r = %i\ncubx->color_c.g = %i\ncubx->color_c.b = %i\n", cubx->color_c.r, cubx->color_c.g, cubx->color_c.b);
	return (CONTINUE_PROC);
}
