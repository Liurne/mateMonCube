/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:28:39 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/30 18:08:33 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_dtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	error(t_data *cub, char *msg)
{
	if (msg)
		ft_dprintf(2, "Error: %s\n", msg);
	if (cub->file)
		free(cub->file);
	if (cub->map.map)
		free_dtab(cub->map.map);
	if (cub->map.b_map)
		free_dtab(cub->map.b_map);
	destroy_img(cub, &cub->pl.pl);
	destroy_img(cub, &(cub->tex_wall[0]));
	destroy_img(cub, &(cub->tex_wall[1]));
	destroy_img(cub, &(cub->tex_wall[2]));
	destroy_img(cub, &(cub->tex_wall[3]));
	close_window(cub);
	return (exit(1), 1);
}

int process(t_data *cub)
{
	t_rect	src;
	t_rect	dst;
	t_rect	cadre;

	init_rect(&src, 5,5,126,126);
	init_rect(&dst, 50,50,500,500);
	init_rect(&cadre, 49, 49, 501, 501);
	player_manager(cub);
	//printf("win w:%d, h:%d\n",cub->win.w, cub->win.h);
	//display_texture(&cub->win.renderer, &cub->data.tex_wall[0], &src, &dst);
	raycast(cub, &cub->pl, &cub->map);
	mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->win.renderer.img, 0, 0);
	//mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->map.img.img, 0, 0);
	//mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->pl.pl.img, cub->pl.x * cub->map.tile_dim - cub->pl.w / 2, cub->pl.y * cub->map.tile_dim - cub->pl.h / 2);
	return (0);
}