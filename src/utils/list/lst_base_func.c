/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_base_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:28:14 by  mchenava         #+#    #+#             */
/*   Updated: 2024/02/12 15:39:20 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../xenocube.h"

t_list	*lst_create(t_cub_context *cubx, void *data)
{
	t_list	*new;

	new = cubx->gc->malloc(cubx, sizeof(t_list), true);
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

t_uint	lst_print(t_list **lst, t_str text)

{
	t_list	*tmp;

	if (!lst)
		return (NULL_DATA);
	tmp = *lst;
	while (tmp)
	{
		printf(text, tmp->data);
		tmp = tmp->next;
	}
	return (CONTINUE_PROC);
}

t_uint	lst_clear(t_cub_context *cubx, t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst)
		return (NULL_DATA);
	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		cubx->gc->free(cubx, tmp->data);
		cubx->gc->free(cubx, tmp);
		tmp = tmp2;
	}
	*lst = NULL;
	return (CONTINUE_PROC);
}

t_uint	lst_size(t_list **lst)
{
	t_list	*tmp;
	t_uint	i;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_uint	lst_remplace(t_cub_context *cubx,
	t_list **lst, t_uint index, t_str data)
{
	t_list	*tmp;
	t_uint	i;

	if (!lst)
		return (NULL_DATA);
	if (!data)
		return (NULL_DATA);
	tmp = *lst;
	i = 0;
	while (tmp && i++ < index)
		tmp = tmp->next;
	if (tmp)
	{
		cubx->gc->free(cubx, tmp->data);
		tmp->data = ft_strdup(cubx, data);
		if (!tmp->data)
			return (MALLOC_FAIL);
	}
	return (CONTINUE_PROC);
}
