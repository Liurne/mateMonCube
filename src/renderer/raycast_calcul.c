/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calcul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:13 by jcoquard          #+#    #+#             */
/*   Updated: 2024/02/21 17:46:37 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

char	get_tile(t_map *map, int x, int y)
{
	if (x < (int)map->w - 1 && y < (int)map->h - 1 && x >= 0 && y >= 0)
		return (map->map[y][x]);
	return ('1');
}

void	get_collision(t_ray *ray, t_map *map)
{
	while (!ray->collision && ray->map_pos.x > 0 && ray->map_pos.x
		< (int)map->w && ray->map_pos.y > 0 && ray->map_pos.y < (int)map->h)
	{
		if (ray->next.x < ray->next.y)
		{
			ray->next.x += ray->range_next.x;
			ray->map_pos.x += ray->step.x;
			ray->side = 0;
			if (ray->direction.x > 0)
				ray->side = 2;
		}
		else
		{
			ray->next.y += ray->range_next.y;
			ray->map_pos.y += ray->step.y;
			ray->side = 1;
			if (ray->direction.y > 0)
				ray->side = 3;
		}
		if (get_tile(map, ray->map_pos.x, ray->map_pos.y) != '0')
			ray->collision = 1;
	}
}

void	calculate_wall_tex(t_cub_context *cub, t_ray *ray)
{
	t_vec	pt;

	ray->tex_x = (int)(ray->wall_x * (double)(cub->img[ray->side].img_w));
	if (!(ray->side % 2) && ray->direction.x > 0)
		ray->tex_x = cub->img[ray->side].img_w - ray->tex_x - 1;
	if (ray->side % 2 && ray->direction.y < 0)
		ray->tex_x = cub->img[ray->side].img_w - ray->tex_x - 1;
	init_vec(&pt, ray->tex_x, 0);
	init_rect(&ray->text_ray, &pt, 1, cub->img[ray->side].img_h);
	init_rect(&ray->rect_ray, &ray->ray.p1, 1, \
	ray->ray.p2.y - ray->ray.p1.y);
	if (ray->ray.p1.y < 0)
	{
		ray->text_ray.pos.y = (-ray->ray.p1.y * cub->img[ray->side].img_h) \
		/ (double)ray->line_h;
		ray->rect_ray.pos.y = 0;
	}
	if (ray->ray.p2.y >= cub->win.h)
	{
		ray->text_ray.h = (cub->win.h * cub->img[ray->side].img_h) \
		/ (double)ray->line_h;
		ray->rect_ray.h = cub->win.h - 1;
	}
}

void	calculate_ray_height(t_cub_context *cub, t_ray *ray, t_cub_entity *e)
{
	if (ray->side % 2 == 0)
		ray->distance = fabs((ray->map_pos.x - (e->pos.x) + \
		(1 - ray->step.x) * 0.5) / ray->direction.x);
	else
		ray->distance = fabs((ray->map_pos.y - (e->pos.y) + \
		(1 - ray->step.y) * 0.5) / ray->direction.y);
	ray->line_h = cub->win.h / ray->distance;
	ray->ray.p1.y = -ray->line_h * 0.5 + cub->win.h * 0.5;
	ray->ray.p2.y = ray->line_h * 0.5 + cub->win.h * 0.5;
	if (ray->side % 2)
		ray->wall_x = e->pos.x + ((ray->map_pos.y - e->pos.y \
		+ (1 - ray->step.y) * 0.5) / ray->direction.y) * ray->direction.x;
	else
		ray->wall_x = e->pos.y + ((ray->map_pos.x - e->pos.x \
		+ (1 - ray->step.x) * 0.5) / ray->direction.x) * ray->direction.y;
	ray->wall_x -= floor((ray->wall_x));
	calculate_wall_tex(cub, ray);
	if (ray->ray.p1.y < 0 || ray->ray.p1.y >= cub->win.h)
		ray->ray.p1.y = 0;
	if (ray->ray.p2.y >= cub->win.h || ray->ray.p2.y < 0)
		ray->ray.p2.y = cub->win.h - 1;
}
