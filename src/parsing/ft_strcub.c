/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:34:42 by bfaure            #+#    #+#             */
/*   Updated: 2024/02/21 17:46:17 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "xenocube.h"

t_uint	ft_strcub(const char *haystack)
{
	size_t	i;
	size_t	j;
	t_str	ber;

	ber = ".cub\0";
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == ber[j] && ber[j] && haystack[i + j])
			j++;
		if (!ber[j] && !haystack[i + j] && i + j > 4 && haystack[i - 1]
			!= '/')
			return (1);
		i++;
	}
	return (0);
}
