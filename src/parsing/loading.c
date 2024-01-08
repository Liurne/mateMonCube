/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:04:01 by liurne            #+#    #+#             */
/*   Updated: 2024/01/05 14:56:28 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

static char	*read_file(int fd)
{
	char	buff[43];
	int		rbytes;
	char	*tmp;
	char	*res;

	rbytes = 1;
	res = NULL;
	while (rbytes)
	{
		ft_bzero(buff, 43 * sizeof(char));
		rbytes = read(fd, buff, 42);
		if (rbytes == -1)
			return (NULL);
		tmp = ft_strdup(res);
		free(res);
		res = ft_strjoin(tmp, buff);
		free (tmp);
		if (!res)
			return (NULL);
	}
	return (res);
}

int load_file(t_data *cub, char *path)
{
	int	fd;

	if (!strcub(path))
		return (error(cub, ERR_CUB));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error(cub, ERR_OPEN));
	cub->file = read_file(fd);
	close(fd);
	if (!cub->file)
		return (error(cub, ERR_READ));
	return (0);
}
