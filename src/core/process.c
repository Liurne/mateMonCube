/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:28:39 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/29 00:09:26 by liurne           ###   ########.fr       */
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
	destroy_img(cub, &(cub->data.tex_wall[0]));
	destroy_img(cub, &(cub->data.tex_wall[1]));
	destroy_img(cub, &(cub->data.tex_wall[2]));
	destroy_img(cub, &(cub->data.tex_wall[3]));
	close_window(cub);
	return (exit(1), 1);
}

int process(t_data *cub)
{
	int x, y;
	player_manager(cub);
	//printf("win w:%d, h:%d\n",cub->win.w, cub->win.h);
	x = 0;
	while(x < cub->win.w)
	{
		y = 0;
		while (y < cub->win.h)
		{
			put_pixel(&cub->win.renderer, x, y, 0x000000);
			y++;
		}
		x++;
	}
	raycast(cub, &cub->pl, &cub->map);
	mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->win.renderer.img, 0, 0);
	//mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->map.img.img, 0, 0);
	//mlx_put_image_to_window(cub->win.mlx, cub->win.win, cub->pl.pl.img, cub->pl.x * cub->map.tile_dim - cub->pl.w / 2, cub->pl.y * cub->map.tile_dim - cub->pl.h / 2);
	return (0);
}