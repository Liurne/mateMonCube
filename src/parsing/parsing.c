/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:48:31 by jcoquard          #+#    #+#             */
/*   Updated: 2024/01/05 14:56:08 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(t_data *cub)
{
	int	i;
	cubtransfo(cub, &(cub->map), cub->file);
	i = 0;
	while (cub->map.map[i])
	{
		ft_putstr_fd(cub->map.map[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	return (0);
}
