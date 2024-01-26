/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:13 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/26 18:40:10 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "define.h"

void	init_ray(int x, t_entity *e, t_ray *ray, t_data *cub)
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
		ray->ray_line.p1.x = cub->win.w - x;
		ray->ray_line.p2.x = cub->win.w - x;

}

void	init_step(t_ray *ray, t_entity *e)
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

void get_collision(t_ray *ray, t_map *map)
{
	while (!ray->collision && ray->map_pos.x > 0 && ray->map_pos.x
		< map->w && ray->map_pos.y > 0 && ray->map_pos.y < map->h)
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

void	raycast(t_data *cub, t_entity *e, t_map *map)
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
			//correction de l'effet fish-eye
			if (ray.side % 2 == 0)
				ray.distance = fabs((ray.map_pos.x - (e->pos.x) + (1 - ray.step.x) * 0.5) / ray.direction.x);
			else
				ray.distance = fabs((ray.map_pos.y - (e->pos.y) + (1 - ray.step.y) * 0.5) / ray.direction.y);
			ray.line_h = cub->win.h / ray.distance;
			ray.ray_line.p1.y = -ray.line_h * 0.5 + cub->win.h * 0.5;
			ray.ray_line.p2.y = ray.line_h * 0.5 + cub->win.h * 0.5;
			if(ray.ray_line.p1.y < 0)
				ray.ray_line.p1.y = 0;
			if (ray.ray_line.p2.y >= cub->win.w)
				ray.ray_line.p2.y = cub->win.h - 1;
			if (ray.side == 0)
				draw_line(&cub->win.renderer, &ray.ray_line, 0x00FF0000);
			else if (ray.side == 2)
				draw_line(&cub->win.renderer, &ray.ray_line, 0x00FF00FF);
			else if (ray.side == 1)
				draw_line(&cub->win.renderer, &ray.ray_line, 0x00A00000);
			else if (ray.side == 3)
				draw_line(&cub->win.renderer, &ray.ray_line, 0x00FF00A0);
		}
		i++;
	}
}
