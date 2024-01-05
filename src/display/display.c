/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:51:06 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/05 16:47:01 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(int *)dst);
}

int	transparence(int c1, int c2, int t)
{
	int	r;
	int	g;
	int	b;
	float tr;

	tr = (float)t / 100;
	r = (((c1 >> 16) & 0xFF) * (1.0 - tr) + ((c2 >> 16) & 0xFF) * tr);
	if (r > 255)
		r = 255;
	g = (((c1 >> 8) & 0xFF) * (1.0 - tr) + ((c2 >> 8) & 0xFF) * tr);
	if (g > 255)
		g = 255;
	b = (c1 & 0xFF) * (1.0 - tr) + ((c2 & 0xFF) * tr);
	if (b > 255)
		b = 255;
	return (255 << 24 | r << 16 | g << 8 | b);
}
