/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:25:47 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/04 17:09:48 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	cub;

	init_window(&cub, WIN_W, WIN_H);
	(void)ac;
	(void)av;

	mlx_hook(cub.win.win, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.win.win, 3, 1L << 1, key_release, &cub);
	mlx_hook(cub.win.win, 17, 1L << 0, close_window, &cub);
	mlx_loop_hook(cub.win.mlx, process, &cub);
	mlx_loop(cub.win.mlx);
	return (0);
}
