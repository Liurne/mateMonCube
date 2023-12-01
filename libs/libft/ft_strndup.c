/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:16:59 by jcoquard          #+#    #+#             */
/*   Updated: 2023/11/29 01:02:39 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*res;
	size_t	l;
	size_t	i;

	l = 0;
	while (s[l])
		l++;
	if (l < n || n == 0)
		return (NULL);
	res = (char *)ft_calloc(n + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (s[++i] && i < n)
		res[i] = s[i];
	return (res);
}
