/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:31:33 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/13 11:54:17 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../xenocube.h"

t_list	*lstcpy(t_cub_context *cubx, t_list *lst)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = lst;
	while (tmp)
	{
		lst_add_back(cubx, &new, ft_strdup(cubx, tmp->data));
		tmp = tmp->next;
	}
	return (new);
}

t_uint	lst_add_front(t_cub_context *cubx, t_list **lst, void *data)
{
	t_list	*new;

	if (!lst)
		return (NULL_DATA);
	new = lst_create(cubx, data);
	if (!new)
		return (MALLOC_FAIL);
	new->next = *lst;
	*lst = new;
	return (CONTINUE_PROC);
}

t_uint	lst_add_back(t_cub_context *cubx, t_list **lst, void *data)
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL_DATA);
	new = lst_create(cubx, data);
	if (!new)
		return (MALLOC_FAIL);
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (CONTINUE_PROC);
}

t_uint	lst_insert(t_cub_context *cubx, t_list **lst, void *data, t_uint index)
{
	t_list	*new;
	t_list	*tmp;
	t_uint	i;

	if (!lst)
		return (NULL_DATA);
	new = lst_create(cubx, data);
	if (!new)
		return (MALLOC_FAIL);
	if (!*lst)
		*lst = new;
	else
	{
		i = 0;
		tmp = *lst;
		while (tmp->next && i++ < index)
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
	return (CONTINUE_PROC);
}

t_uint	lst_append(t_cub_context *cubx, t_list **lst, t_uint index, t_str data)
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
		tmp->data = ft_strfjoin(cubx, tmp->data, data);
		if (!tmp->data)
			return (MALLOC_FAIL);
	}
	return (CONTINUE_PROC);
}
