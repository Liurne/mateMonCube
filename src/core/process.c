/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:51:37 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/21 17:45:33 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

int	quit_loop(t_cub_context *cub)
{
	mlx_loop_end(cub->win.mlx);
	return (0);
}

int	process(t_cub_context *cub)
{
	player_manager(cub);
	raycast(cub, &cub->player, &cub->map);
	mlx_put_image_to_window(cub->win.mlx,
		cub->win.win, cub->win.renderer.img, 0, 0);
	return (0);
}
