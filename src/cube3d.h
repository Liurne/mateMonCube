/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:49:09 by liurne            #+#    #+#             */
/*   Updated: 2023/11/29 01:19:40 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# define ERR_ARG "Invalid number of arguments"
# define ERR_MLX "Couldn't initiate mlx"
# define ERR_LIB "Couldn't create a window"
# define ERR_MAP "Map invalid or non-existant"
# define ERR_TEX "Texture invalid or non-existant"
# define ERR_IMG "Couldn't creater an image"
# define ERR_MALLOC "Malloc failed"
# define ERR_CUB "Invalid file extension (need .cub)"
# define ERR_OPEN "Couldn't open the file"
# define ERR_READ "Couldn't read the file"
# define WIN_W 1280
# define WIN_H 768

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_w;
	int		img_h;
}	t_img;

typedef struct s_color
{
	char	r;
	char	g;
	char	b;
	int		a;
}	t_color;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	t_img	renderer;
	int		w;
	int		h;
}	t_win;

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_map
{
	char	**map;
	char	*b_map;
	int		w;
	int		h;
	t_vec	pos;
	t_vec	end;
	t_img	img;
	t_img	tex[4];
	t_color	floor;
	t_color	celling;
	
}	t_map;

typedef struct s_keyboard
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	r_left;
	int	r_right;
}	t_keyboard;

typedef struct s_data
{
	t_win		win;
	t_keyboard	keys;
	t_map		map;
	char		*file;
}	t_data;

/*     utils     */
void	free_dtab(char **tab);
int		cubtransfo(t_data *cub, t_map *map, char *str);

/*     process     */
int		error(t_data *cub, char *msg);
int		process(t_data *cub);

/*     init     */
int		new_img(t_data *cub, t_img *img, int w, int h);
int		load_img(t_data *cub, char *path, t_img *img);
int		destroy_img(t_data *cub, t_img *img);
int		close_window(t_data *cub);
int		init_window(t_data *cub, int win_w, int win_h);
int		load_file(t_data *cub, char *path);
int		parsing(t_data *cub);
void	clear_img(t_data *cub);

#endif