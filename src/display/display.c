/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:51:06 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/26 17:51:58 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#include "stdio.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->img_w || y < 0 || y >= img->img_h)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	char	*dst;
	if (x < 0 || x >= img->img_w || y < 0 || y >= img->img_h)
		return (0);
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

void	draw_line(t_img *img, t_line *line, int color)
{
	int	dx;
	int	dy;
	int	steps;
	int i;

	dx = line->p2.x - line->p1.x;
	dy = line->p2.y - line->p1.y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	i = 0;
	put_pixel(img, line->p1.x, line->p1.y, color);
	while (i < steps)
	{
		line->p1.x += dx / steps;
		line->p1.y += dy / steps;
		put_pixel(img, line->p1.x, line->p1.y, color);
		i++;
	}
}
