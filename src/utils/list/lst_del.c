/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:38:33 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/12 15:29:18 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../xenocube.h"

t_uint	lst_remove(t_cub_context *cubx, t_list **lst, t_uint index)
{
	t_list	*current;
	t_list	*previous;
	t_uint	i;

	current = *lst;
	previous = NULL;
	i = 0;
	while (current != NULL)
	{
		if (i == index)
		{
			if (previous == NULL)
				*lst = current->next;
			else
				previous->next = current->next;
			cubx->gc->free(cubx, current->data);
			cubx->gc->free(cubx, current);
			return (CONTINUE_PROC);
		}
		i++;
		previous = current;
		current = current->next;
	}
	return (CONTINUE_PROC);
}

t_uint	lst_remove_first(t_cub_context *cubx, t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL_DATA);
	tmp = *lst;
	if (tmp)
	{
		*lst = tmp->next;
		cubx->gc->free(cubx, tmp->data);
		cubx->gc->free(cubx, tmp);
	}
	return (CONTINUE_PROC);
}

t_uint	lst_remove_last(t_cub_context *cubx, t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL_DATA);
	tmp = *lst;
	if (tmp)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		cubx->gc->free(cubx, tmp->next->data);
		cubx->gc->free(cubx, tmp->next);
		tmp->next = NULL;
	}
	return (CONTINUE_PROC);
}
