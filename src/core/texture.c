/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:39:28 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/30 11:32:33 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	display_texture(t_img *renderer, t_img *img, t_rect *src, t_rect *dst)
{
	int	i;
	int	j;
	int	tmp_x;
	int	tmp_y;

	i = 0;
	while (i < dst->w)
	{
		j = 0;
		while (j < dst->h)
		{
			tmp_x = ((src->pos.x + i) * src->w) / dst->w;
			tmp_y = ((src->pos.y + j) * src->h) / dst->h;
			put_pixel(renderer, i + dst->pos.x, j + dst->pos.y,
				get_pixel(img, tmp_x, tmp_y));
			j++;
		}
		i++;
	}
}
