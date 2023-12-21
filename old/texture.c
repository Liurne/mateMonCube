/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liurne <liurne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:16:06 by liurne            #+#    #+#             */
/*   Updated: 2023/12/15 15:09:44 by liurne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clear_img(t_data *cub)
{
	destroy_img(cub, &(cub->map.tex[0]));
	destroy_img(cub, &(cub->map.tex[1]));
	destroy_img(cub, &(cub->map.tex[2]));
	destroy_img(cub, &(cub->map.tex[3]));
}