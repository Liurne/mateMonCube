/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:48:34 by bfaure            #+#    #+#             */
/*   Updated: 2024/01/09 13:42:31 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static size_t	ft_intlen(long nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(t_cub_context *cubx, int n)
{
	char	*str;
	size_t	len;
	size_t	i;
	long	nb;

	nb = n;
	len = ft_intlen(nb);
	i = len;
	str = gc_malloc(cubx, sizeof(char) * len + 1, false);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[(len--) - 1] = nb % 10 + '0';
		nb /= 10;
	}
	str[i] = '\0';
	return (str);
}
