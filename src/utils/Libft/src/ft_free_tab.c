/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:39:27 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/09 13:42:31 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_free_tab_len(char **strs, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return ;
}

void	ft_free_tab(t_cub_context *cubx, char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		cubx->gc->free(cubx, strs[i]);
		i++;
	}
	cubx->gc->free(cubx, strs);
	return ;
}
