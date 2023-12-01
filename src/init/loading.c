/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:04:01 by liurne            #+#    #+#             */
/*   Updated: 2023/11/29 00:58:38 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static int	strcub(const char *haystack)
{
	size_t	i;
	size_t	j;
	char	*ber;

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

static char	*strjoin_spe(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (res);
}

static char	*read_file(t_data *cub, int fd)
{
	char	buff[43];
	int		rbytes;
	char	*str;

	rbytes = 1;
	str = NULL;
	while (rbytes)
	{
		rbytes = read(fd, buff, 42);
		if (rbytes == -1)
		{
			free(str);
			str = NULL;
			return (error(cub, ERR_READ), NULL);
		}
		buff[rbytes] = '\0';
		str = strjoin_spe(str, buff);
		if (!str)
			return (error(cub, ERR_MALLOC), NULL);
	}
	return (str);
}

int load_file(t_data *cub, char *path)
{
	int	fd;

	if (!strcub(path))
		return (error(cub, ERR_CUB));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error(cub, ERR_OPEN));
	cub->file = read_file(cub, fd);
	close(fd);
	if (!cub->file)
		return (error(cub, ERR_READ));
	return (0);
}
