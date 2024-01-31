/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:15:42 by bfaure            #+#    #+#             */
/*   Updated: 2022/11/18 11:15:42 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strfjoin(t_cub_context *cubx, char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = cubx->gc->malloc(cubx, sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2)) + 1, true);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (cubx->gc->free(cubx, s1), str);
}

char	*ft_strnjoin(t_cub_context *cubx, char *s1, char *s2, ssize_t n)
{
	char	*str;
	int		i;
	int		j;

	str = cubx->gc->malloc(cubx, sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2)) + 1, true);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] && i < n)
		str[j++] = s2[i++];
	str[j] = '\0';
	return (cubx->gc->free(cubx, s1), str);
}
