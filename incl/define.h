/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:18:53 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/29 00:03:43 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

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
# define SPEED_ROTATE 0.04
# define SPEED_MOVE 0.1
# define WIN_W 1280
# define WIN_H 768

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_dvec
{
	double	x;
	double	y;
}	t_dvec;

typedef struct s_line
{
	t_vec	p1;
	t_vec	p2;
}	t_line;

typedef struct s_ray
{
	int		collision;
	int		side;
	double	distance;
	double	camera;
	t_dvec	direction;
	t_dvec	range_next;
	t_dvec	next;
	t_vec	step;
	t_vec	map_pos;
	int		line_h;
	t_line	ray_line;
	double	wall_x;
	int		tex_x;
}	t_ray;

typedef struct s_color
{
	char	r;
	char	g;
	char	b;
	int		a;
}	t_color;

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

typedef struct s_win
{
	void	*mlx;
	void	*win;
	t_img	renderer;
	int		w;
	int		h;
}	t_win;

typedef struct s_keyboard
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	r_left;
	int	r_right;
}	t_keyboard;

typedef struct s_entity
{
	t_dvec pos;
	int w;
	int h;
	t_dvec	dir;
	t_dvec	plan;
	t_img pl;
} t_entity;

typedef struct s_map
{
	char	**map;
	char	**b_map;
	int		w;
	int		h;
	int		tile_dim;
	t_vec	pos;
	t_img	img;
}	t_map;

typedef struct s_cub_textures
{
	t_img	tex_wall[4];
	t_color	col_floor;
	t_color	col_ceilling;
}	t_cub_textures;

typedef struct s_data
{
	t_win		win;
	t_keyboard	keys;
	t_map		map;
	t_entity	pl;
	char		*file;
	t_cub_textures data;
}	t_data;

#endif