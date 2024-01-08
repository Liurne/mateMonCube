/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:05 by liurne            #+#    #+#             */
/*   Updated: 2024/01/04 16:50:27 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int keycode, t_data *cub)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
		close_window(cub);
	if ((keycode == 119 || keycode == 65362) && !cub->keys.down)
		cub->keys.up = 1;
	if ((keycode == 115 || keycode == 65364) && !cub->keys.up)
		cub->keys.down = 1;
	if ((keycode == 97 || keycode == 65361) && !cub->keys.right)
		cub->keys.left = 1;
	if ((keycode == 100 || keycode == 65363) && !cub->keys.left)
		cub->keys.right = 1;
	if (keycode == 113 && !cub->keys.r_right)
		cub->keys.r_left = 1;
	if (keycode == 101 && !cub->keys.r_left)
		cub->keys.r_right = 1;
	return (keycode);
}

int	key_release(int keycode, t_data *cub)
{
	if (keycode == 119 || keycode == 65362)
		cub->keys.up = 0;
	if (keycode == 115 || keycode == 65364)
		cub->keys.down = 0;
	if (keycode == 97 || keycode == 65361)
		cub->keys.left = 0;
	if (keycode == 100 || keycode == 65363)
		cub->keys.right = 0;
	if (keycode == 113)
		cub->keys.r_left = 0;
	if (keycode == 101)
		cub->keys.r_right = 0;
	return (keycode);
}
