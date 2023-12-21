/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/12/15 15:15:27 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	new_img(t_data *cub, t_img *img, int w, int h)
{
	img->img = mlx_new_image(cub->win.mlx, w, h);
	if (!img->img)
		error(cub, ERR_IMG);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
		error(cub, ERR_IMG);
	return (0);
}

int	load_img(t_data *cub, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(cub->win.mlx, path, &(img->img_w),
			&(img->img_h));
	if (!img->img)
		return(printf("%s\n", path), 1);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
		return(printf("%s\n", path), 1);
	return (0);
}

int	destroy_img(t_data *cub, t_img *img)
{
	if (img->img)
		mlx_destroy_image(cub->win.mlx, img->img);
	return (0);
}

int	close_window(t_data *cub)
{
	destroy_img(cub, &(cub->win.renderer));
	if (cub->win.win)
		mlx_destroy_window(cub->win.mlx, cub->win.win);
	if (cub->win.mlx)
	{
		mlx_destroy_display(cub->win.mlx);
		free(cub->win.mlx);
	}
	exit(0);
	return (0);
}

int	init_window(t_data *cub, int win_w, int win_h)
{
	ft_bzero(cub, sizeof(t_data));
	cub->win.w = win_w;
	cub->win.h = win_h;
	cub->win.mlx = mlx_init();
	if (!cub->win.mlx)
		error(cub, ERR_MLX);
	cub->win.win = mlx_new_window(cub->win.mlx, cub->win.w, cub->win.h, "so_long");
	if (!cub->win.win)
		error(cub, ERR_LIB);
	new_img(cub, &(cub->win.renderer), cub->win.w, cub->win.h);
	if (!cub->win.renderer.img)
		error(cub, ERR_IMG);
	return (0);
}
