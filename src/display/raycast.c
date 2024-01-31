/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:13 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/31 18:49:30 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../xenocube.h"

static void	init_ray(int x, t_cub_entity *e, t_ray *ray, t_cub_context *cub)
{
	ray->collision = 0;
	ray->camera = 2 * x / (double)cub->win.w - 1;
	ray->map_pos.x = (int)(e->pos.x);
	ray->map_pos.y = (int)(e->pos.y);
	ray->direction.x = e->dir.x + e->plan.x * ray->camera;
	ray->direction.y = e->dir.y + e->plan.y * ray->camera;
	ray->range_next.x = sqrt(1 + pow(ray->direction.y, 2)
			/ pow(ray->direction.x, 2));
	ray->range_next.y = sqrt(1 + pow(ray->direction.x, 2)
			/ pow(ray->direction.y, 2));
	ray->ray.p1.x = cub->win.w - x;
	ray->ray.p2.x = cub->win.w - x;
}

static void	init_step(t_ray *ray, t_cub_entity *e)
{
	if (ray->direction.x < 0)
	{
		ray->step.x = -1;
		ray->next.x = (e->pos.x - ray->map_pos.x)
			* ray->range_next.x;
	}
	else
	{
		ray->step.x = 1;
		ray->next.x = (ray->map_pos.x + 1 - e->pos.x)
			* ray->range_next.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step.y = -1;
		ray->next.y = (e->pos.y - ray->map_pos.y)
			* ray->range_next.y;
	}
	else
	{
		ray->step.y = 1;
		ray->next.y = (ray->map_pos.y + 1 - e->pos.y)
			* ray->range_next.y;
	}
}

static void	draw_ray(t_cub_context *cub, t_ray *ray)
{
	t_line	ceiling;
	t_line	floor;
	t_vec	pt;

	init_vec(&pt, ray->ray.p1.x, 0);
	init_line(&ceiling, &pt, &ray->ray.p1);
	init_vec(&pt, ray->ray.p1.x, cub->win.h - 1);
	init_line(&floor, &ray->ray.p2, &pt);
	draw_line(&cub->win.renderer, &ceiling, 0x000900090);
	if (cub->img[ray->side].img)
		display_texture(&cub->win.renderer, &cub->img[ray->side], \
		&ray->text_ray, &ray->rect_ray);
	else
	{
		if (ray->side == 0)
			draw_line(&cub->win.renderer, &ray->ray, 0x00B010B0);
		else if (ray->side == 2)
			draw_line(&cub->win.renderer, &ray->ray, 0x00EE00EE);
		else if (ray->side == 1)
			draw_line(&cub->win.renderer, &ray->ray, 0x00F060F0);
		else if (ray->side == 3)
			draw_line(&cub->win.renderer, &ray->ray, 0x00FF00A0);
	}
	draw_line(&cub->win.renderer, &floor, 0x00B090B0);
}

void	raycast(t_cub_context *cub, t_cub_entity *e, t_map *map)
{
	int		i;
	t_ray	ray;

	i = 0;
	while (i < cub->win.w)
	{
		init_ray(i, e, &ray, cub);
		init_step(&ray, e);
		get_collision(&ray, map);
		if (ray.collision)
		{
			calculate_ray_height(cub, &ray, e);
			draw_ray(cub, &ray);
		}
		i++;
	}
}
