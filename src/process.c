/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:28:39 by jcoquard          #+#    #+#             */
/*   Updated: 2023/12/14 16:30:18 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	free_dtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	error(t_data *cub, char *msg)
{
	if (msg)
		ft_dprintf(2, "Error: %s\n", msg);
	if (cub->map.map)
		free_dtab(cub->map.map);
	if (cub->map.b_map)
		free(cub->map.b_map);
	destroy_img(cub, &(cub->map.tex[0]));
	destroy_img(cub, &(cub->map.tex[1]));
	destroy_img(cub, &(cub->map.tex[2]));
	destroy_img(cub, &(cub->map.tex[3]));
	close_window(cub);
	return (exit(1), 1);
}

int process(t_data *cub)
{
	return (0);
}