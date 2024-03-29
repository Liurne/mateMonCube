/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:20:27 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/09 13:42:31 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_strcpy(char *dst, const char *src, char c)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup_char(t_cub_context *cubx, const char *str, char c)
{
	char	*dest;

	dest = cubx->gc->malloc(cubx, sizeof(char) * (ft_strlen(str) + 1), false);
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, str, c));
}
