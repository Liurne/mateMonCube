/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:13 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/31 18:53:53 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->img_w || y < 0 || y >= img->img_h)
		return ;
	((int *)img->addr)[y * (img->line_length >> 2) + x] = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	if (x < 0 || x >= img->img_w || y < 0 || y >= img->img_h)
		return (0);
	return (((int *)img->addr)[y * (img->line_length >> 2) + x]);
}

void	draw_line(t_img *img, t_line *line, int color)
{
	int	dx;
	int	dy;
	int	steps;
	int	i;

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
			tmp_x = src->pos.x + (i * src->w) / dst->w;
			tmp_y = src->pos.y + (j * src->h) / dst->h;
			put_pixel(renderer, i + dst->pos.x, j + dst->pos.y,
				get_pixel(img, tmp_x, tmp_y));
			j++;
		}
		i++;
	}
}
