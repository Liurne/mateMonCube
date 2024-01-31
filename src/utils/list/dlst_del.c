/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:52:38 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/12 15:00:15 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../xenocube.h"

void	dlst_remove(t_cub_context *cubx, t_dlist **dlst, t_uint index)
{
	t_dlist	*tmp;
	t_uint	i;

	if (!dlst)
		return ;
	tmp = *dlst;
	i = 0;
	while (tmp && i++ < index)
		tmp = tmp->next;
	if (tmp)
	{
		if (tmp->next)
			tmp->next = tmp->next->next;
		else
			tmp->next = NULL;
		if (tmp->prev)
			tmp->prev = tmp->prev->prev;
		else
			tmp->prev = NULL;
		cubx->gc->free(cubx, tmp->data);
		cubx->gc->free(cubx, tmp);
	}
}

void	dlst_remove_first(t_cub_context *cubx, t_dlist **dlst)
{
	t_dlist	*tmp;

	if (!dlst)
		return ;
	tmp = *dlst;
	if (tmp)
	{
		*dlst = tmp->next;
		(*dlst)->prev = NULL;
		cubx->gc->free(cubx, tmp->data);
		cubx->gc->free(cubx, tmp);
	}
}

void	dlst_remove_last(t_cub_context *cubx, t_dlist **dlst)
{
	t_dlist	*tmp;

	if (!dlst)
		return ;
	tmp = *dlst;
	if (tmp)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next = NULL;
		cubx->gc->free(cubx, tmp->data);
		cubx->gc->free(cubx, tmp);
	}
}
