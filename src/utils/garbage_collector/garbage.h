/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:52:35 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 19:52:35 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include "../../../xenocube.h"

struct s_garbage_collector
{
	t_free_func			free;
	t_malloc_func		malloc;
	t_ptr				*ptrs;
	int					nb_ptrs;
};

struct s_ptr
{
	t_uint			size;
	void			*ptr;
	t_ptr			*next;
	bool			counted;
};

void	*gc_malloc(t_cub_context *cubx, size_t size, bool count);
void	gc_free(t_cub_context *cubx, void *ptr);
void	gc_free_all(t_cub_context *cubx);
t_uint	init_gc(t_cub_context *cubx);

#endif
