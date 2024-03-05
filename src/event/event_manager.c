/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:01:39 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/21 17:45:45 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

int	key_press(int keycode, t_cub_context *cubx)
{
	if (keycode == 65307)
		quit_loop(cubx);
	if ((keycode == 119 || keycode == 65362) && !cubx->keyboard.down)
		cubx->keyboard.up = 1;
	if ((keycode == 115 || keycode == 65364) && !cubx->keyboard.up)
		cubx->keyboard.down = 1;
	if ((keycode == 97) && !cubx->keyboard.right)
		cubx->keyboard.left = 1;
	if ((keycode == 100) && !cubx->keyboard.left)
		cubx->keyboard.right = 1;
	if (keycode == 65361 && !cubx->keyboard.r_right)
		cubx->keyboard.r_left = 1;
	if (keycode == 65363 && !cubx->keyboard.r_left)
		cubx->keyboard.r_right = 1;
	return (keycode);
}

int	key_release(int keycode, t_cub_context *cubx)
{
	if (keycode == 119 || keycode == 65362)
		cubx->keyboard.up = 0;
	if (keycode == 115 || keycode == 65364)
		cubx->keyboard.down = 0;
	if (keycode == 97)
		cubx->keyboard.left = 0;
	if (keycode == 100)
		cubx->keyboard.right = 0;
	if (keycode == 65361)
		cubx->keyboard.r_left = 0;
	if (keycode == 65363)
		cubx->keyboard.r_right = 0;
	return (keycode);
}

void	player_manager(t_cub_context *cubx)
{
	if (cubx->keyboard.r_left)
		rotate_left(&cubx->player);
	if (cubx->keyboard.r_right)
		rotate_right(&cubx->player);
	if (cubx->keyboard.up)
		move_forward(&cubx->map, &cubx->player);
	if (cubx->keyboard.down)
		move_backward(&cubx->map, &cubx->player);
	if (cubx->keyboard.left)
		move_left(&cubx->map, &cubx->player);
	if (cubx->keyboard.right)
		move_right(&cubx->map, &cubx->player);
}
