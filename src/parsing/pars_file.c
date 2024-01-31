/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:29:41 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/31 13:27:32 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	find_we_no(t_cub_context *cubx, t_str line, int fd, t_uint *check)
{
	t_uint	status;

	if (line[0] == 'W' && line[1] == 'E')
	{
		status = pars_graphic_path(cubx, line, fd, 0);
		(*check)++;
		if (status != CONTINUE_PROC)
			return (status);
		printf("cubx.img[0].img = %p\n", cubx->img[0].img);
	}
	else if (line[0] == 'N' && line[1] == 'O')
	{
		status = pars_graphic_path(cubx, line, fd, 1);
		(*check)++;
		if (status != CONTINUE_PROC)
			return (status);
		printf("cubx.img[1].img = %p\n", cubx->img[1].img);
	}
	return (CONTINUE_PROC);
}

t_uint	find_ea_so(t_cub_context *cubx, t_str line, int fd, t_uint *check)
{
	t_uint	status;

	if (line[0] == 'E' && line[1] == 'A')
	{
		status = pars_graphic_path(cubx, line, fd, 2);
		(*check)++;
		if (status != CONTINUE_PROC)
			return (status);
		printf("cubx.img[2].img = %p\n", cubx->img[2].img);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		status = pars_graphic_path(cubx, line, fd, 3);
		(*check)++;
		if (status != CONTINUE_PROC)
			return (status);
		printf("cubx.img[3].img = %p\n", cubx->img[3].img);
	}
	return (CONTINUE_PROC);
}

t_uint	find_color(t_cub_context *cubx, t_str line, int fd, t_uint *check)
{
	t_uint	status;

	if (line[0] == 'F')
	{
		status = pars_color(cubx, line, 'F', fd);
		(*check)++;
		if (status != CONTINUE_PROC)
			return (status);
	}
	else if (line[0] == 'C')
	{
		status = pars_color(cubx, line, 'C', fd);
		(*check)++;
		if (status != CONTINUE_PROC)
			return (status);
	}
	return (CONTINUE_PROC);
}

t_uint	find_the_path(t_cub_context *cubx, t_str line, int fd)
{
	t_uint	check;

	check = 0;
	while (line != NULL)
	{
		if (find_we_no(cubx, line, fd, &check) != CONTINUE_PROC)
			return (free(line), MALLOC_FAIL);
		if (find_ea_so(cubx, line, fd, &check) != CONTINUE_PROC)
			return (free(line), MALLOC_FAIL);
		if (find_color(cubx, line, fd, &check) != CONTINUE_PROC)
			return (free(line), MALLOC_FAIL);
		printf("check = %d\n", check);
		if (check == 6)
		{
			if (add_map_to_lst(cubx, fd) != CONTINUE_PROC)
				return (free(line), MALLOC_FAIL);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
		free(line);
	return (CONTINUE_PROC);
}

t_uint	pars_file(t_cub_context *cubx, t_str path)
{
	int		fd;
	t_str	line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (BAD_FD);
	line = get_next_line(fd);
	if (line == NULL)
		return (MALLOC_FAIL);
	if (find_the_path(cubx, line, fd) != CONTINUE_PROC)
		return (MALLOC_FAIL);
	close(fd);
	return (CONTINUE_PROC);
}
