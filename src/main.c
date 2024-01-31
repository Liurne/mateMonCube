/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:25:47 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/31 14:15:49 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	cub;

	init_window(&cub, WIN_W, WIN_H);
	if (ac > 1)
		load_file(&cub, av[1]);
	printf("yep\n");
	parsing(&cub);
	printf("nop\n");
	load_img(&cub, "tex/mossy_1.xpm", &cub.tex_wall[0]);
	load_img(&cub, "tex/mossy_1.xpm", &cub.tex_wall[2]);
	load_img(&cub, "tex/mossy_1.xpm", &cub.tex_wall[3]);
	load_img(&cub, "tex/Tile.xpm", &cub.tex_wall[1]);
	mlx_hook(cub.win.win, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.win.win, 3, 1L << 1, key_release, &cub);
	mlx_hook(cub.win.win, 17, 1L << 0, close_window, &cub);
	mlx_loop_hook(cub.win.mlx, process, &cub);
	mlx_loop(cub.win.mlx);
	return (0);
}
