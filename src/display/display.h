/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:12:46 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/31 18:11:32 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "../../xenocube.h"

char	get_tile(t_map *map, int x, int y);
void	get_collision(t_ray *ray, t_map *map);
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);
void	draw_line(t_img *img, t_line *line, int color);
void	display_texture(t_img *renderer, t_img *img, t_rect *src, t_rect *dst);
void	raycast(t_cub_context *cub, t_cub_entity *e, t_map *map);
void	calculate_ray_height(t_cub_context *cub, t_ray *ray, t_cub_entity *e);

#endif