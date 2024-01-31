/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:21:48 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/16 17:21:48 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_strcpy(char *dst, const char *src, int n, unsigned int len)
{
	size_t	i;

	i = 0;
	(void)len;
	while (src[i] != '\0')
	{
		if (n == 1 && (!ft_isdigit(src[i]) && !ft_isalpha(src[i])))
		{
			dst[i] = ' ';
			i++;
			continue ;
		}
		if (src[i] == '\n')
		{
			break ;
		}
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = ' ';
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strndup(t_cub_context *cubx, const char *str, unsigned int len)
{
	char	*dest;
	int		n;

	n = 0;
	if (len > ft_strlen(str))
		n = 1;
	dest = gc_malloc(cubx, sizeof(char) * (len + 1), false);
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, str, n, len));
}
