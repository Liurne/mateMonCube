/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:47:00 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 19:47:00 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

static t_uint	init_error(t_cub_context *cubx)
{
	if (init_cub_context(cubx) != CONTINUE_PROC)
	{
		printf("Error\nCub_context_init fail\n");
		return (gc_free_all(cubx), CUB_CONTEXT_INIT_FAIL);
	}
	if (win_init(cubx, 1920, 1080) != CONTINUE_PROC)
	{
		printf("Error\nmlx init fail\n");
		mlx_destroy_display(cubx->win.mlx);
		free(cubx->win.mlx);
		return (WIN_INIT_FAIL);
	}
	return (CONTINUE_PROC);
}

static void	error_handler(t_cub_context *cubx, t_uint status)
{
	if (status != CONTINUE_PROC)
	{
		if (status == MALLOC_FAIL)
			printf("Error\nMalloc fail\n");
		else if (status == BAD_COLOR_FORMAT)
			printf("Error\nWrong color format\n");
		else if (status == BAD_FD)
			printf("Error\nSomething goes wrong with fd\n");
		else if (status == TOO_MANY_TX_ID)
			printf("Error\nToo many texture id\n");
		else if (status == TOO_MANY_CO_ID)
			printf("Error\nToo many color id\n");
		else if (status == BAD_ID)
			printf("Error\nBad id\n");
		ft_clear(cubx);
	}
	return ;
}

static t_uint	map_error(t_cub_context *cubx, t_str *argv)
{
	t_uint	status;

	status = pars_file(cubx, argv[1]);
	error_handler(cubx, status);
	status = check_map(cubx);
	if (status != CONTINUE_PROC)
	{
		if (status == MAP_ERROR)
			printf("Error\nMap error\n");
		else if (status == PLAYER_ERROR)
			printf("Error\nSomthing goes wrong with player\n");
		else if (status == WRONG_CHAR)
			printf("Error\nWrong char in map\n");
		ft_clear(cubx);
	}
	return (CONTINUE_PROC);
}

static t_uint	error_manager(t_cub_context *cubx, t_str *argv)
{
	if (init_error(cubx) != CONTINUE_PROC)
		return (INIT_FAIL);
	if (map_error(cubx, argv) != CONTINUE_PROC)
		return (MAP_ERROR);
	return (CONTINUE_PROC);
}

int	main(int argc, char **argv)
{
	t_cub_context	cubx;

	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		return (0);
	}
	else
	{
		if (ft_strcub(argv[1]) != 1)
			return (printf("Error\nWrong file format\n"), 0);
		if (error_manager(&cubx, argv) != CONTINUE_PROC)
			ft_clear(&cubx);
		back_to_normal_map(&cubx);
		mlx_hook(cubx.win.win, 2, 1L << 0, key_press, &cubx);
		mlx_hook(cubx.win.win, 3, 1L << 1, key_release, &cubx);
		mlx_hook(cubx.win.win, 17, 1L << 0, quit_loop, &cubx);
		mlx_loop_hook(cubx.win.mlx, process, &cubx);
		mlx_loop(cubx.win.mlx);
		ft_clear(&cubx);
	}
	return (0);
}
