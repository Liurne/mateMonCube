/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:52:45 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/31 19:01:21 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

t_uint	ft_clear(t_cub_context *cubx)
{
	t_uint	i;

	i = 0;
	while (i < 4)
	{
		if (cubx->img[i].img)
			printf("cubx->img[%d].img = %p\n", i, cubx->img[i].img);
		if (cubx->img[i].img)
			mlx_destroy_image(cubx->win.mlx, cubx->img[i].img);
		i++;
	}
	if (cubx->win.renderer.img)
		mlx_destroy_image(cubx->win.mlx, cubx->win.renderer.img);
	mlx_destroy_window(cubx->win.mlx, cubx->win.win);
	mlx_destroy_display(cubx->win.mlx);
	free(cubx->win.mlx);
	gc_free_all(cubx);
	return (CONTINUE_PROC);
}
