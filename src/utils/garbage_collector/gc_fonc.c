/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_fonc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:52:58 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/08 19:52:58 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

void	*gc_malloc(t_cub_context *cubx, size_t size, bool count)
{
	t_ptr				*new_ptr;
	t_garbage_collector	*gc;

	new_ptr = malloc(sizeof(t_ptr));
	if (!new_ptr)
		return (NULL);
	new_ptr->ptr = malloc(size);
	if (!new_ptr->ptr)
		return (NULL);
	gc = cubx->gc;
	new_ptr->size = size;
	new_ptr->counted = count;
	new_ptr->next = NULL;
	if (!gc->ptrs)
		gc->ptrs = new_ptr;
	else
	{
		new_ptr->next = gc->ptrs;
		gc->ptrs = new_ptr;
	}
	if (count)
		gc->nb_ptrs++;
	return (new_ptr->ptr);
}

void	gc_free(t_cub_context *cubx, void *ptr)
{
	t_ptr				*prev;
	t_ptr				*curr;
	t_garbage_collector	*gc;

	gc = cubx->gc;
	prev = NULL;
	curr = gc->ptrs;
	while (curr)
	{
		if (curr->ptr == ptr)
		{
			if (prev)
				prev->next = curr->next;
			else
				gc->ptrs = curr->next;
			free(curr->ptr);
			if (curr->counted)
				gc->nb_ptrs--;
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

void	gc_free_all(t_cub_context *cubx)
{
	t_ptr				*ptrs;
	t_ptr				*tmp;
	t_ptr				*top;
	t_garbage_collector	*gc;

	gc = cubx->gc;
	ptrs = gc->ptrs;
	top = ptrs;
	while (ptrs)
	{
		tmp = ptrs;
		if (tmp->ptr)
			free(tmp->ptr);
		if (ptrs->counted)
			gc->nb_ptrs--;
		ptrs = ptrs->next;
		free(tmp);
	}
	gc->ptrs = top;
	free(gc);
}
