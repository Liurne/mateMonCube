/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:04:01 by liurne            #+#    #+#             */
/*   Updated: 2023/12/15 16:57:39 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

//wall NO SO WE EA
//player N S W E
//celling and floor C F ***,***,***

int	datalen(char *file)
{
	int	i;

	i = 0;
	while (file && file[i] && !ft_iswhitespace(file[i]))
		i++;
	printf("data len:%d\n", i);
	return (i);
}

int get_texture(t_data *cub, char *file, int wall)
{
	char	*path;
	int		i;

	i = 2;
	while (file && ft_iswhitespace(file[i]))
		i++;
	path = ft_strndup(file, datalen(file + i));
	if (!path)
		error(cub, ERR_MALLOC);
	if (cub->map.tex[wall].img)
		destroy_img(cub, &(cub->map.tex[wall]));
	if (load_img(cub, path, &(cub->map.tex[wall])))
	{
		free(path);
		error(cub, ERR_TEX);
	}
	free(path);
	return (i + datalen(file + i));
}
int function(t_data *cub, char *file)
{
	while (file && ft_iswhitespace(*file))
		file++;
	if (!ft_strncmp(file, "NO", 2))
		file += get_texture(cub, file, 0);
	else if (!ft_strncmp(file, "SO", 2))
		file += get_texture(cub, file, 1);
	else if (!ft_strncmp(file, "WE", 2))
		file += get_texture(cub, file, 2);
	else if (!ft_strncmp(file, "EA", 2))
		file += get_texture(cub, file, 3);
	return (0);
}

int pars_file(t_data *cub, char *file)
{
	int	i;

	while (file && *file)
	{
		i = 0;
		while (ft_iswhitespace(file[i]))
			i++;
		if (!file[i])
			return (printf("Map incomplete\n"));
		if (!ft_strncmp(file, "NO", 2))
			file += get_texture(cub, file, 0);
		else if (!ft_strncmp(file, "SO", 2))
			file += get_texture(cub, file, 1);
		else if (!ft_strncmp(file, "WE", 2))
			file += get_texture(cub, file, 2);
		else if (!ft_strncmp(file, "EA", 2))
			file += get_texture(cub, file, 3);
		else if ()
		
	}
}

int	parsing(t_data *cub)
{
	//function(cub, cub->file);
	int	i;

	cubtransfo(cub, &(cub->map), cub->map.b_map);
	i = 0;
	while (cub->map.map[i])
	{
		ft_putstr_fd(cub->map.map[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	return (0);
}
