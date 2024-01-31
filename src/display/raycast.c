/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:13 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/30 19:33:17 by liurne           ###   ########.fr       */
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
	ray->ray.p1.x = cub->win.w - x;
	ray->ray.p2.x = cub->win.w - x;
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

void	get_collision(t_ray *ray, t_map *map)
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

void	calculate_wall_tex(t_data *cub, t_ray *ray, t_entity *e)
{
	ray->tex_x = (int)(ray->wall_x * (double)(cub->tex_wall[ray->side].img_w));
	if (!(ray->side % 2) && ray->direction.x > 0)
		ray->tex_x = cub->tex_wall[ray->side].img_w - ray->tex_x - 1;
	if (ray->side % 2 && ray->direction.y < 0)
		ray->tex_x = cub->tex_wall[ray->side].img_w - ray->tex_x - 1;
	init_rect(&ray->text_ray, ray->tex_x, 0, 1, cub->tex_wall[ray->side].img_h);
	init_rect(&ray->rect_ray, ray->ray.p1.x, ray->ray.p1.y, 1, \
	ray->ray.p2.y - ray->ray.p1.y);
	if (ray->ray.p1.y < 0)
	{
		ray->text_ray.pos.y = cub->tex_wall[ray->side].img_h * 0.5 * \
		(1 - ((double)cub->win.h / (double)ray->line_h));
		ray->rect_ray.pos.y = 0;
	}
	if (ray->ray.p2.y >= cub->win.h)
	{
		ray->text_ray.h = (cub->tex_wall[ray->side].img_h * \
		((double)cub->win.h / (double)ray->line_h)) * 1.70;
		ray->rect_ray.h = cub->win.w - 1;
	}
}

void	calculate_ray_height(t_data *cub, t_ray *ray, t_entity *e)
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
	calculate_wall_tex(cub, ray, e);
	if (ray->ray.p1.y < 0)
		ray->ray.p1.y = 0;
	if (ray->ray.p2.y >= cub->win.h)
		ray->ray.p2.y = cub->win.h - 1;
}

void	draw_ray(t_data *cub, t_ray *ray)
{
	t_line	ceiling;
	t_line	floor;

	init_line(&ceiling, ray->ray.p1.x, 0, ray->ray.p1.x, ray->ray.p1.y);
	init_line(&floor, ray->ray.p1.x, ray->ray.p2.y, ray->ray.p1.x, \
		cub->win.h - 1);
	draw_line(&cub->win.renderer, &ceiling, 0x000900090);
	if (cub->tex_wall[ray->side].img)
		display_texture(&cub->win.renderer, &cub->tex_wall[ray->side], \
		&ray->text_ray, &ray->rect_ray);
	else
	{
		if (ray->side == 0)
			draw_line(&cub->win.renderer, &ray->ray, 0x00C010C0);
		else if (ray->side == 2)
			draw_line(&cub->win.renderer, &ray->ray, 0x00EE00EE);
		else if (ray->side == 1)
			draw_line(&cub->win.renderer, &ray->ray, 0x00F060F0);
		else if (ray->side == 3)
			draw_line(&cub->win.renderer, &ray->ray, 0x00FF00A0);
	}
	draw_line(&cub->win.renderer, &floor, 0x00D090D0);
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
			calculate_ray_height(cub, &ray, e);
			draw_ray(cub, &ray);
		}
		i++;
	}
}
