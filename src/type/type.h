/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:17:51 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 20:17:51 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

// # include "../../xenocube.h"

typedef unsigned int	t_uint;
typedef char*			t_str;

typedef struct			s_cub_context t_cub_context;
typedef struct			s_list t_list;
typedef struct			s_dlist t_dlist;
typedef struct			s_color t_color;
typedef struct			s_garbage_collector t_garbage_collector;
typedef struct			s_ptr t_ptr;
typedef struct			s_cub_textures t_cub_textures;
typedef struct			s_img t_img;
typedef struct			s_cub_path t_cub_path;
typedef struct			s_cub_entity t_cub_entity;
typedef struct			s_vec t_vec;
typedef struct			s_win t_win;
typedef struct			s_keyboard t_keyboard;
typedef struct			s_map t_map;
typedef struct 			s_vec t_vec;
typedef struct 			s_dvec t_dvec;
typedef struct 			s_line t_line;
typedef struct 			s_rect t_rect;
typedef struct			s_ray t_ray;

typedef void (*			t_free_func)(
	t_cub_context	*cubx,
	void *ptr
);
typedef void *(*		t_malloc_func)(
	t_cub_context	*cubx,
	size_t size,
	bool count
);

#endif