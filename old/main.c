/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:56:56 by liurne            #+#    #+#             */
/*   Updated: 2023/12/14 15:10:44 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cube3d.h"

int	main(int ac, char **av)
{
	t_data	cub;

	init_window(&cub, WIN_W, WIN_H);
	if (ac < 2 || ac > 2)
		return (error(&cub, ERR_ARG));
	if (load_file(&cub, av[1]))
		return (1);
	if (parsing(&cub))
		return (1);
	mlx_hook(cub.win.win, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.win.win, 3, 1L << 1, key_release, &cub);
	mlx_hook(cub.win.win, 17, 1L << 0, close_window, &cub);
	mlx_loop_hook(cub.win.mlx, event_manager, &cub);
	mlx_loop(cub.win.mlx);
	return (0);
}