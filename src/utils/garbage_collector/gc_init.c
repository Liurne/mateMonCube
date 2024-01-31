/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:53:13 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 19:53:13 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

t_uint	init_gc(t_cub_context *cubx)
{
	t_garbage_collector	*gc;

	gc = (t_garbage_collector *)malloc(sizeof(t_garbage_collector));
	if (!gc)
		return (MALLOC_FAIL);
	ft_bzero(gc, sizeof(t_garbage_collector));
	gc->free = gc_free;
	gc->malloc = gc_malloc;
	gc->ptrs = NULL;
	gc->nb_ptrs = 0;
	cubx->gc = gc;
	return (CONTINUE_PROC);
}
