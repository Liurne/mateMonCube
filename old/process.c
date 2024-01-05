/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:04:36 by liurne            #+#    #+#             */
/*   Updated: 2024/01/05 13:53:08 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	error(t_data *cub, char *msg)
{
	if (msg)
		ft_dprintf(2, "Error: %s\n", msg);
	if (cub->map.map)
		free_dtab(cub->map.map);
	if (cub->map.b_map)
		free(cub->map.b_map);
	clear_img(cub);
	close_window(cub);
	return (exit(1), 1);
}

int process(t_data *cub)
{
	
}