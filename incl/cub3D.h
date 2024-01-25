/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:17:58 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/24 17:28:06 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "define.h"
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

/*     utils     */
void	free_dtab(char **tab);

/*     window     */
int		new_img(t_data *cub, t_img *img, int w, int h);
int		load_img(t_data *cub, char *path, t_img *img);
int		destroy_img(t_data *cub, t_img *img);
int		close_window(t_data *cub);
int		init_window(t_data *cub, int win_w, int win_h);

/*     process     */
int		error(t_data *cub, char *msg);
int		process(t_data *cub);

/*     event     */
int		key_press(int keycode, t_data *cub);
int		key_release(int keycode, t_data *cub);

/*     loading     */
int		load_file(t_data *cub, char *path);

/*     parsing     */
int		parsing(t_data *cub);
int		cubtransfo(t_data *cub, t_map *map, char *str);

/*     display     */
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);
int		transparence(int c1, int c2, int t);
void	line(t_img *img, t_vec p1, t_vec p2, int color);
void	raycast(t_data *cub);

/*     init     */
void init_entity(t_data *cub, t_entity *entity, double x, double y);

/*     entity     */
void	player_manager(t_data *cub);
char	get_tile(t_map *map, int x, int y);

#endif